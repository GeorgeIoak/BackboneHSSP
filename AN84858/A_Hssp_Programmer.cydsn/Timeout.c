/******************************************************************************
* File Name: Timeout.c
* Version 1.0
*
* Description:
*  This file provides source code for the delay routine used in the HSSP
*  application
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
#include "Timeout.h"

/******************************************************************************
*   Function Definitions
******************************************************************************/

/******************************************************************************
* Function Name: DelayHundredUs
*******************************************************************************
*
* Summary:
*  Generates an approximate delay for 100 microseconds
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The delay is introduced by using a for loop with a predefined iteration
*  determined by the parameter XRES_PULSE_100US in the header file Timeout.h. 
*
******************************************************************************/

void DelayHundredUs(void)
{
    unsigned short timestamp;    

    /* Delay using a empty for loop */
    for(timestamp = 0; timestamp < XRES_PULSE_100US; timestamp++)
    {
        
    }
}

/* [] END OF FILE */
