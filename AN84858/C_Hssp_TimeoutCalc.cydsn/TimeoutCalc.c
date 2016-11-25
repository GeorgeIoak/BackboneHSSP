/******************************************************************************
* File Name: TimeoutCalc.c
* Version 1.0
*
* Description:
*  This file provides source code for the functions used to calculate the 
*  timeout parameters used in the HSSP application
*
* Owner:
*	Tushar Rastogi, Application Engineer (tusr@cypress.com)
*
* Related Document:
*	AN84858 - PSoC 4 Programming using an External Microcontroller (HSSP)
*
* Hardware Dependency:
*   PSoC 5LP Development Kit - CY8CKIT-050
*
* Code Tested With:
*	PSoC Creator 3.2
*	ARM GCC 4.8.4
*	CY8CKIT-050
*
* Note:
*  Refer to the header file TimeoutCalc.h for the procedure to calculate the 
*  timeout parameters
*******************************************************************************
* Copyright (2015), Cypress Semiconductor Corporation.
*******************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
******************************************************************************/


/******************************************************************************
*   Header file Inclusion
******************************************************************************/
#include "TimeoutCalc.h"
#include "SWD_PacketLayer.h"
#include "SWD_UpperPacketLayer.h"

/******************************************************************************
*   Macro Definitions
******************************************************************************/
#define CPUSS_SYSREQ	            0x40000004
#define SROM_SYSREQ_BIT	            0x80000000
#define SROM_PRIVILEGED_BIT	        0x10000000
#define DPACC_DP_IDCODE_READ   		0xA5

/******************************************************************************
*   Function Definitions
******************************************************************************/

/******************************************************************************
* Function Name: TestDelayHundredUs
*******************************************************************************
*
* Summary:
*  This function is used to calculate the timing parameter XRES_PULSE_100US
*
* Parameters:
*  None
*
* Return:
*  None
*
* Note:
*  Refer to the explanation of the parameter XRES_PULSE_100US in the file
*  TimeoutCalc.h for details on using this function to calculate the parameter
*  XRES_PULSE_100US  
*
******************************************************************************/

void TestDelayHundredUs(void)
{
    unsigned short timestamp;
    
	/* Make the pin low before start of the delay */
    TESTPIN_OUTPUT_LOW;
    
    /* For loop to introduce the 100 us delay */
    for(timestamp = 0; timestamp < XRES_PULSE_100US; timestamp++)
    {
		/* Do Nothing */
    }
    
	/* Make the pin high after end of the delay */
    TESTPIN_OUTPUT_HIGH;
}

/******************************************************************************
* Function Name: TestSromPollingTimeout
*******************************************************************************
*
* Summary:
*  This function is used to calculate the timing parameter SROM_POLLING_TIMEOUT
*
* Parameters:
*  None
*
* Return:
*  None
*
* Note:
*  Refer to the explanation of the parameter SROM_POLLING_TIMEOUT in the file
*  TimeoutCalc.h for details on using this function to calculate the parameter
*  SROM_POLLING_TIMEOUT
*
******************************************************************************/
void TestSromPollingTimeout()
{
	unsigned short timestamp = 0;
	unsigned long statusCode = 0;
	
	/* Make the pin low before sending SWD clock train */
	TESTPIN_OUTPUT_LOW;
	
	for(timestamp = 0; timestamp < 10; timestamp++)
	{
		Read_IO (CPUSS_SYSREQ, &statusCode);
		
		/*performing SROM_SYSREQ_BIT | SROM_PRIVILEGED_BIT */
		statusCode &= (SROM_SYSREQ_BIT | SROM_PRIVILEGED_BIT);
	}
	
	/* Make the pin high after sending SWD clock train */
	TESTPIN_OUTPUT_HIGH;
}

/******************************************************************************
* Function Name: TestModeTimeout
*******************************************************************************
*
* Summary:
*  This function is used to calculate the timing parameter
*  DEVICE_ACQUIRE_TIMEOUT
*
* Parameters:
*  None
*
* Return:
*  None
*
* Note:
*  Refer to the explanation of the parameter DEVICE_ACQUIRE_TIMEOUT in the file
*  TimeoutCalc.h for details on using this function to calculate the parameter
*  DEVICE_ACQUIRE_TIMEOUT  
*
******************************************************************************/
void TestModeTimeout()
{
	unsigned short timestamp = 0;
	unsigned long chip_DAP_Id = 0;
	
	/* Make the pin low before sending SWD clock train */
	TESTPIN_OUTPUT_LOW; 
	
	for(timestamp = 0; timestamp < 1; timestamp++)
    {
		Swd_LineReset();
		Read_DAP(DPACC_DP_IDCODE_READ, &chip_DAP_Id);
	}
	
	/* Make the pin high after sending SWD clock train */
	TESTPIN_OUTPUT_HIGH;
}

/* [] END OF FILE */
