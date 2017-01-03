/******************************************************************************
* File Name: TimeoutCalc.h
* Version 1.0
*
* Description:
*  This header file contains the definitions for the timeout parameters,  
*  declaration of the functions used for calculating the the timeout parameters
*
* Note:
*  The timeout values given below are applicable for a PSoC 5 Host processor 
*  with the CPU operating at a clock frequency of 63 MHz. A test pin defined as
*  TESTPIN is used to arrive at these timeout values by toggling the pin, and 
*  measuring the low pulse width of the square wave on the test pin using an
*  oscilloscope.
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

#ifndef __TIMEOUTCALC_H
#define __TIMEOUTCALC_H

/***************************** USER ATTENTION REQUIRED ************************
***************************** HOST PROCESSOR SPECIFIC *************************
***************************** Macros for the TESTPIN *************************/

#define TESTPIN_PRT_NUM            0
#define TESTPIN_PIN_NUM            5

#define TESTPIN_PIN_MASK           (0x01 << TESTPIN_PIN_NUM)

#define TESTPIN_PRT_OUT_REG        (*((volatile unsigned char *)(0x40005100 + (TESTPIN_PRT_NUM * 0x10))))
#define TESTPIN_DM_REG             (*((volatile unsigned char *)(0x40005000 + (TESTPIN_PRT_NUM * 8) + TESTPIN_PIN_NUM)))

#define CMOSOUT_DM_ANDMASK         0xF1
#define CMOSOUT_DM_ORMASK          0x0C

#define TESTPIN_DRIVEMODE_CMOSOUT  (TESTPIN_DM_REG = (TESTPIN_DM_REG & CMOSOUT_DM_ANDMASK) | CMOSOUT_DM_ORMASK) 
#define TESTPIN_OUTPUT_HIGH        (TESTPIN_PRT_OUT_REG = TESTPIN_PRT_OUT_REG | TESTPIN_PIN_MASK)
#define TESTPIN_OUTPUT_LOW         (TESTPIN_PRT_OUT_REG = TESTPIN_PRT_OUT_REG & (~TESTPIN_PIN_MASK))

/***************************** USER ATTENTION REQUIRED ************************
***************************** HOST PROCESSOR SPECIFIC *************************
***************************** Timeout parameter definitions *******************
*
* The below four timeout values namely: XRES_PULSE_100US, SROM_POLLING_TIMEOUT,
* and DEVICE_ACQUIRE_TIMEOUT, should be calculated by calling the corresponding
* functions in the for loop of the main() function  and measuring the low pulse
* width of the square wave signal on the TESTPIN. Refer to the procedure given
* for calculating each of the parameters below.
* The default definitions below are for a PSoC 5 host programmer operating at a
* frequency of 63 MHZ.
* Modify these values as required for your host processor.

******************************************************************************/

/*********************Calculating XRES_PULSE_100US ****************************
* 1.) Call ONLY the function TestDelayHundredUs(), defined in TimeoutCalc.c, in
* 	  the for loop of the main code.
* 2.) Note down the LOW PULSE WIDTH (Tlow) of the square wave on the pin
*	  TEST_PIN.
* 3.) Tune the value of the definition XRES_PULSE_100US below till the low
*	  pulse width (Tlow) is JUST GREATER than 100uS.
* 4.) For example, for a PSoC 5 host programmer operating at 63MHz, defining
*	  the XRES_PULSE_100US as 600 gave a low pulse width of 100 uS. This was
*	  used in the HSSP code.
*
******************************************************************************/
#define XRES_PULSE_100US  607

/*********************Calculating DEVICE_ACQUIRE_TIMEOUT **********************
* 1.) Call ONLY the function TestModeTimeout(), defined in TimeoutCalc.c, in the
*	  for loop of the main code.
* 2.) Note down the LOW PULSE WIDTH (Tlow in us) of the square wave on the pin
*	  TEST_PIN.
* 3.) DEVICE_ACQUIRE_TIMEOUT = (1.5 ms)/(Tlow), rounded off to the next higher
*	  integer.
* 4.) For example, for a PSoC 5 host programmer operating at 63MHz, Tlow was
*	  101 uS. So, DEVICE_ACQUIRE_TIMEOUT = (1500)/(101 us) = 14.85 = 15. This
*	  value was used in the HSSP code.
* 5.) The value 1.5 ms is derived from the programming specifications document
*
******************************************************************************/
#define DEVICE_ACQUIRE_TIMEOUT 16

/*********************Calculating SROM_POLLING_TIMEOUT ************************
* 1.) Call ONLY the function TestSromPollingTimeout(), defined in TimeoutCalc.c,
*	  in the for loop of the main code.
* 2.) Note down the LOW PULSE WIDTH (Tlow in us) of the square wave on the pin
*	  TEST_PIN.
* 3.) SROM_POLLING_TIMEOUT = (1000000 us)/(Tlow), rounded off to the next higher
*	  integer.
* 4.) For example, for a PSoC 5 host programmer operating at 63MHz, Tlow was
*	  960uS for 10 cycles. So, SROM_POLLING_TIMEOUT = (1000000us)/(96us) = 10416.
*	  This value was used in the HSSP code.
* 5.) The value 1000000us (1 second) is derived from the programming
*	  specifications document based on the SROM polling timeout duration which
*	  is 1 second.
******************************************************************************/
#define SROM_POLLING_TIMEOUT 10416

/******************************************************************************
*   Function Prototypes
******************************************************************************/
void TestDelayHundredUs(void);
void TestModeTimeout(void);
void TestSromPollingTimeout(void);

#endif /* __TIMEOUTCALC_H */


/* [] END OF FILE */
