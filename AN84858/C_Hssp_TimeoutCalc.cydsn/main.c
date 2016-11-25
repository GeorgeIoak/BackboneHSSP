/******************************************************************************
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
*******************************************************************************
*  Project Name: C_Hssp_TimeoutCalc
*  Project Revision: 1.00
*  Software Version: PSoC Creator 3.2
*  Device Tested: CY8C5868AXI-LP035
*  Compilers Tested: ARM GCC 4.8.4
*  Related Hardware: CY8CKIT-050
*******************************************************************************
* 
* Project Description:
*  This project is used to calculate the timeout parameters used in the main
*  projects "A_Hssp_Programmer" and "B_Hssp_Pioneer". The project is tested 
*  using CY8CKIT-050 with PSoC 5LP chip.
*
* Connections Required:
*  Connect TestPin (P0[3]) to oscilloscope to calculate the timeout parameters
*  by measuring the time difference between consecutive pulses.
*
*  In this file, the main function calls the functions used to calculate the 
*  timeout parameters used in the HSSP application.
*
* Note:
*  To calculate each timeout parameter, the corresponding function needs to be 
*  uncommented in the for loop of the main function, and the procedure given
*  in the TimeoutCalc.h under each timeout parameter should be used to
*  calculate the timeout parameter.
*  The calculated values should then be used in the main HSSP project in the
*  file Timeout.h.
*
******************************************************************************/
/******************************************************************************
*   Header file Inclusion
******************************************************************************/
/* Remove this header file for non PSoC 5 host programmer */
#include <device.h>

/* This header file has the function declarations, macros used to arrive at the
   timeout parameter values */
#include "TimeoutCalc.h"
#include "SWD_PhysicalLayer.h"

/********************************************************************************
*   Function Definitions
********************************************************************************/
void main()
{
	/* Set TEST pin for Strong drive mode */
    TESTPIN_DRIVEMODE_CMOSOUT;
	
	/* Drive the pin high */
    TESTPIN_OUTPUT_HIGH;       
    
    for(;;)
    {
        /* Uncomment ONLY ONE of the functions below at a time. Then, calculate the 
           corresponding timeout parameter using the explanation provided for the
           timeout parameter in the file TimeoutCalc.h */
    	
		/* Uncomment this line to calculate the timeout parameter XRES_PULSE_100US */
//        TestDelayHundredUs();

		/* Uncomment this line to calculate the timeout parameter DEVICE_ACQUIRE_TIMEOUT */
//		  TestModeTimeout();

		/* Uncomment this line to calculate the timeout parameter SROM_POLLING_TIMEOUT */
		  TestSromPollingTimeout();
	}
}

/* [] END OF FILE */
