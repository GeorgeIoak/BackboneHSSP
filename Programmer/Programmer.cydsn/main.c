/******************************************************************************


*******************************************************************************
*  Project Name: A_Hssp_Programmer
*  Project Revision: 1.00
*  Software Version: PSoC Creator 3.3
*  Device Tested: CY8C5868AXI-LP035
*  Compilers Tested: ARM GCC 4.9-2015-q1-update
*  Related Hardware: CY8CKIT-050
******************************************************************************/

/******************************************************************************
* Project Description:
* This is a sample HSSP implmentation demonstrating a PSoC 5LP programming
* PSoC 4. The project is tested using CY8CKIT-050 with PSoC 5LP chip and 
* CY8CKIT-001 with PSoC 4 processor module.
*
* Connections Required
* CY8CKIT-050 (PSoC 5LP DVK) :
*  Pin_SWDIO (P0[0])- This pin is connected to SWDIO (Debug pin) of PSoC 4 kit.
*  Pin_SWDCK (P0[1])- This pin is connected to SWDCK (Debug pin) of PSoC 4 kit.
*  Pin_XRES  (P0[2])- This pin is connected to XRES input of PSoC kit.
*  Pin_Start (P6[1])- This pin is internally connected to switch SW2.
*
* Note that the GNDs of both DVKs should be connected together and Power should
* be supplied from a single source.
*
* The hex file included in this project toggles pin P1[6] of PSoC 4 at 1Hz
* frequency and displays “PSoC Programmed” on the character LCD mounted on
* CY8CKIT-001 DVK.
* 
* Connections required on the CY8CKIT-001 with PSoC 4 Processor Module :
* 	1. Connect P1[6] to LED1
*	2. Mount character LCD on the kit
*
* Press SW2 on the PSoC 5LP DVK to start the programming operation.
* ProgramDevice() function in main.c calls all the programming steps
* sequentially to program PSoC 4.
*
* main.c checks the result of ProgramDevice() function and if it returns 
* SUCCESS, "HSSP Success" is displayed on the character LCD mounted on the
* PSoC 5LP kit. If ProgramDevice() returns failure, Step of failure, Reason
* of failure is displayed on the LCD. If the error is because of SROM, It
* displays the SROM error code.
*
* On the PSoC 4 Side, LED connected to P1[6] starts to toggle at 1 Hz
* frequency and character LCD displays the message after successful 
* programming.
*
* Note:
*  The Character LCD functions and the Pin_Start APIs in the main() function
*  are for PSoC 5LP host programmer. If you are using any other microcontroller,
*  replace the functions with the APIs supported by the host or change the macro
*  USE_LCD and USE_START_PIN to 0 to remove all LCD and Pin_Start functions.
******************************************************************************/

/* This file is included for calling Character LCD and Pin_Start APIs in
   PSoC 5LP. Remove this header file while porting to non PSoC 5LP host
   programmer */
#include <device.h>

#include <project.h>

/* These macros are used to remove all LCD and Pin_Start functions while
   porting this code to non PSoC 5LP host programmer */
#define USE_LCD 		0
#define USE_START_PIN 	0

/* This file has the top level HSSP routines that should be called from main
   application code */
#include "ProgrammingSteps.h"

/* Function which sequentially calls all the programming steps */
unsigned char ProgramDevice(void);

/* Global variable which stores the current programming step under execution */
unsigned char currentStep;

/* Slave address of the EZI2C */
#define EZI2C_SLAVE_ADDR        (0x08u)
#define BUFFER_SIZE             (0x04u)
#define BUFFER_RW_AREA_SIZE     (0x02u)

/* Denotes the offset inside the EZI2C buffer */
#define SLAVE_ADDR_SIZE         (0x01u)

#define ACTION_SELECT_NONE      (0x00u)     /* Do nothing       */
#define ACTION_SELECT_WRITE     (0x01u)     /* Write to EZI2C   */
#define ACTION_SELECT_READ      (0x02u)     /* Read from EZI2C  */

/* Desing interrupt handlers for SW1 and SW2 event */
CY_ISR_PROTO(ISR_WriteSW1_Interrupt);
CY_ISR_PROTO(ISR_ReadSW2_Interrupt);

/* EZI2C buffer */
uint8   ezi2cBuffer[BUFFER_SIZE];

/* I2C buffer with the data read from EZI2C */
uint8   i2cBufferRead[BUFFER_SIZE];

/* I2C buffer with the data to be written to EZI2C */
uint8   i2cBufferWrite[SLAVE_ADDR_SIZE + BUFFER_SIZE];

/* Initialize action variable */
volatile uint8 actionSelect = ACTION_SELECT_NONE;

int main()
{
    /* Variable to store the result of HSSP operation */
    unsigned char programResult;   
	
	/* Variable to store the HSSP Error status in case of failure */
    unsigned char errorStatus; 
	
	/* Variable to store the SROM Error status if errorStatus contains
	   SROM_TIMEOUT_ERROR error */
    unsigned char sromErrorStatus;
	
	/* Set USE_LCD macro to 0 if PSoC 5LP is not used as host microcontroller */
	if(USE_LCD)
	{
		/* Initialize Character LCD  */
	    LCD_Char_Start();
		
		/* Display the message */
		LCD_Char_Position(0,0);
		LCD_Char_PrintString("Press SWITCH SW2");
	}
    
	/* Set USE_START_PIN macro to 0 if PSoC 5LP is not used as host
	   microcontroller */
	if(USE_START_PIN)
	{
		while (Pin_Start_Read() == 1);
	}
	
	/* Set USE_LCD macro to 0 if PSoC 5LP is not used as host microcontroller */
	if(USE_LCD)
	{
		/* Clear Character LCD  */
		LCD_Char_ClearDisplay();
		
		/* Display the message */
	    LCD_Char_Position(0,0);
	    LCD_Char_PrintString("Programming PSoC4");
	}
       
    /* Start EZI2C */
    EZI2C_Start();
    
    /* Enable global interrupts */
    CyGlobalIntEnable;
    
    /* Initialize EZI2C buffer's read only data */
    ezi2cBuffer[BUFFER_RW_AREA_SIZE     ] = 0xAAu;
    ezi2cBuffer[BUFFER_RW_AREA_SIZE + 1u] = 0xBBu;

    /***************************************************************************
    * The first parameter sets the size of the exposed memory to the I2C
    * interface. In this case, it is the entire array. The second parameter sets
    * the boundary between the read/write and read only areas by setting the
    * number of bytes in the read/write area. The read/write area is first,
    * followed by the read only area. In this case, only the first
    * BUFFER_RW_AREA_SIZE bytes may be written, but all bytes may be read by the
    * I2C master. The third parameter is a pointer to the data.
    ***************************************************************************/
    EZI2C_SetBuffer1(BUFFER_SIZE, BUFFER_RW_AREA_SIZE, (void *) ezi2cBuffer);


    /* Start the HSSP Programming and store the status */
    programResult = ProgramDevice();
    
	/* Set USE_LCD macro to 0 if PSoC 5LP is not used as host microcontroller */
	if(USE_LCD)
	{
	    /* Character LCD will display the status of HSSP Programming  */
	    LCD_Char_ClearDisplay();
	}
    
	/* HSSP completed successfully */
    if(programResult == SUCCESS) 
    {
		/* Set USE_LCD macro to 0 if PSoC 5LP is not used as host microcontroller */
        if(USE_LCD)
		{
			LCD_Char_Position(0,0);
        	LCD_Char_PrintString("HSSP Success");
    	}
	}
	
	/* HSSP Failure */
    else
    {
		/* Set USE_LCD macro to 0 if PSoC 5LP is not used as host microcontroller */
        if(USE_LCD)
		{
			/* Display the step number where the HSSP failed */
	        LCD_Char_Position(0,0);
	        LCD_Char_PrintString("HSSP Fail Step");
	        LCD_Char_PrintInt8(currentStep);
		}
        		
        /* Get the HSSP error status and display on THE LCD */
        errorStatus = ReadHsspErrorStatus();
        
		/* Set USE_LCD macro to 0 if PSoC 5LP is not used as host microcontroller */
		if(USE_LCD)
		{
	        LCD_Char_Position(1,0);
	        LCD_Char_PrintString("Err ");
	        LCD_Char_PrintInt8(errorStatus);
		}
        
        /* If the errorStatus contains THE SROM_TIMEOUT_ERROR error condition,
           read the Status Code returned by CPUSS_SYSARG register and display
		   on THE LCD */
        if(errorStatus & SROM_TIMEOUT_ERROR)
        {
            sromErrorStatus = ReadSromStatus();
            
			/* Set USE_LCD macro to 0 if PSoC 5LP is not used as host microcontroller */
			if(USE_LCD)
			{
				LCD_Char_PrintString(" SROM ");
				LCD_Char_PrintInt8(sromErrorStatus);
			}
        }
    }

    for( ; ; )
    {
        /* Do Nothing */
    }
}

/******************************************************************************
* Function Name: unsigned char ProgramDevice(void)
*******************************************************************************
* Summary:
*  This function sequentially calls all the functions required to program a
*  PSoC 4. These functions are defined in ProgrammingSteps.h.
*
* Parameters:
*  None.
*
* Return:
*  SUCCESS - All the programming steps executed successfully
*  FAILURE - HSSP programming fails in any one of the programming step
*
******************************************************************************/
unsigned char ProgramDevice()
{
    currentStep = 0;
    
    currentStep++;    
    if(DeviceAcquire() == FAILURE)     
        return(FAILURE);
    
    currentStep++;
    if(VerifySiliconId() == FAILURE)    
        return(FAILURE);

    currentStep++;
    if(EraseAllFlash() == FAILURE)             
        return(FAILURE);

    currentStep++;
    if(ChecksumPrivileged() == FAILURE)                    
        return(FAILURE);

    currentStep++;
    if(ProgramFlash() == FAILURE)          
        return(FAILURE);

    currentStep++;
    if(VerifyFlash() == FAILURE)       
        return(FAILURE);

    currentStep++;
    if(ProgramProtectionSettings() == FAILURE) 
        return(FAILURE);

    currentStep++;
    if(VerifyProtectionSettings() == FAILURE)
        return(FAILURE);

    currentStep++;
    if(VerifyChecksum() == FAILURE) 
        return(FAILURE);

    ExitProgrammingMode();
    
	/* All the steps were completed successfully */
    return(SUCCESS);
}

/* End Of File [] */
