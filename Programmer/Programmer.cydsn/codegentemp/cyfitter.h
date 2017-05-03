#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* ADC_ADC_SAR */
#define ADC_ADC_SAR__CLK CYREG_SAR1_CLK
#define ADC_ADC_SAR__CSR0 CYREG_SAR1_CSR0
#define ADC_ADC_SAR__CSR1 CYREG_SAR1_CSR1
#define ADC_ADC_SAR__CSR2 CYREG_SAR1_CSR2
#define ADC_ADC_SAR__CSR3 CYREG_SAR1_CSR3
#define ADC_ADC_SAR__CSR4 CYREG_SAR1_CSR4
#define ADC_ADC_SAR__CSR5 CYREG_SAR1_CSR5
#define ADC_ADC_SAR__CSR6 CYREG_SAR1_CSR6
#define ADC_ADC_SAR__PM_ACT_CFG CYREG_PM_ACT_CFG11
#define ADC_ADC_SAR__PM_ACT_MSK 0x02u
#define ADC_ADC_SAR__PM_STBY_CFG CYREG_PM_STBY_CFG11
#define ADC_ADC_SAR__PM_STBY_MSK 0x02u
#define ADC_ADC_SAR__SW0 CYREG_SAR1_SW0
#define ADC_ADC_SAR__SW2 CYREG_SAR1_SW2
#define ADC_ADC_SAR__SW3 CYREG_SAR1_SW3
#define ADC_ADC_SAR__SW4 CYREG_SAR1_SW4
#define ADC_ADC_SAR__SW6 CYREG_SAR1_SW6
#define ADC_ADC_SAR__TR0 CYREG_SAR1_TR0
#define ADC_ADC_SAR__WRK0 CYREG_SAR1_WRK0
#define ADC_ADC_SAR__WRK1 CYREG_SAR1_WRK1

/* ADC_Bypass */
#define ADC_Bypass__0__INTTYPE CYREG_PICU0_INTTYPE2
#define ADC_Bypass__0__MASK 0x04u
#define ADC_Bypass__0__PC CYREG_PRT0_PC2
#define ADC_Bypass__0__PORT 0u
#define ADC_Bypass__0__SHIFT 2u
#define ADC_Bypass__AG CYREG_PRT0_AG
#define ADC_Bypass__AMUX CYREG_PRT0_AMUX
#define ADC_Bypass__BIE CYREG_PRT0_BIE
#define ADC_Bypass__BIT_MASK CYREG_PRT0_BIT_MASK
#define ADC_Bypass__BYP CYREG_PRT0_BYP
#define ADC_Bypass__CTL CYREG_PRT0_CTL
#define ADC_Bypass__DM0 CYREG_PRT0_DM0
#define ADC_Bypass__DM1 CYREG_PRT0_DM1
#define ADC_Bypass__DM2 CYREG_PRT0_DM2
#define ADC_Bypass__DR CYREG_PRT0_DR
#define ADC_Bypass__INP_DIS CYREG_PRT0_INP_DIS
#define ADC_Bypass__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define ADC_Bypass__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define ADC_Bypass__LCD_EN CYREG_PRT0_LCD_EN
#define ADC_Bypass__MASK 0x04u
#define ADC_Bypass__PORT 0u
#define ADC_Bypass__PRT CYREG_PRT0_PRT
#define ADC_Bypass__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define ADC_Bypass__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define ADC_Bypass__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define ADC_Bypass__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define ADC_Bypass__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define ADC_Bypass__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define ADC_Bypass__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define ADC_Bypass__PS CYREG_PRT0_PS
#define ADC_Bypass__SHIFT 2u
#define ADC_Bypass__SLW CYREG_PRT0_SLW

/* ADC_IRQ */
#define ADC_IRQ__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define ADC_IRQ__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define ADC_IRQ__INTC_MASK 0x01u
#define ADC_IRQ__INTC_NUMBER 0u
#define ADC_IRQ__INTC_PRIOR_NUM 7u
#define ADC_IRQ__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define ADC_IRQ__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define ADC_IRQ__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* ADC_theACLK */
#define ADC_theACLK__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define ADC_theACLK__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define ADC_theACLK__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define ADC_theACLK__CFG2_SRC_SEL_MASK 0x07u
#define ADC_theACLK__INDEX 0x01u
#define ADC_theACLK__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define ADC_theACLK__PM_ACT_MSK 0x02u
#define ADC_theACLK__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define ADC_theACLK__PM_STBY_MSK 0x02u

/* PWM_PWMHW */
#define PWM_PWMHW__CAP0 CYREG_TMR0_CAP0
#define PWM_PWMHW__CAP1 CYREG_TMR0_CAP1
#define PWM_PWMHW__CFG0 CYREG_TMR0_CFG0
#define PWM_PWMHW__CFG1 CYREG_TMR0_CFG1
#define PWM_PWMHW__CFG2 CYREG_TMR0_CFG2
#define PWM_PWMHW__CNT_CMP0 CYREG_TMR0_CNT_CMP0
#define PWM_PWMHW__CNT_CMP1 CYREG_TMR0_CNT_CMP1
#define PWM_PWMHW__PER0 CYREG_TMR0_PER0
#define PWM_PWMHW__PER1 CYREG_TMR0_PER1
#define PWM_PWMHW__PM_ACT_CFG CYREG_PM_ACT_CFG3
#define PWM_PWMHW__PM_ACT_MSK 0x01u
#define PWM_PWMHW__PM_STBY_CFG CYREG_PM_STBY_CFG3
#define PWM_PWMHW__PM_STBY_MSK 0x01u
#define PWM_PWMHW__RT0 CYREG_TMR0_RT0
#define PWM_PWMHW__RT1 CYREG_TMR0_RT1
#define PWM_PWMHW__SR0 CYREG_TMR0_SR0

/* SCL */
#define SCL__0__INTTYPE CYREG_PICU12_INTTYPE0
#define SCL__0__MASK 0x01u
#define SCL__0__PC CYREG_PRT12_PC0
#define SCL__0__PORT 12u
#define SCL__0__SHIFT 0u
#define SCL__AG CYREG_PRT12_AG
#define SCL__BIE CYREG_PRT12_BIE
#define SCL__BIT_MASK CYREG_PRT12_BIT_MASK
#define SCL__BYP CYREG_PRT12_BYP
#define SCL__DM0 CYREG_PRT12_DM0
#define SCL__DM1 CYREG_PRT12_DM1
#define SCL__DM2 CYREG_PRT12_DM2
#define SCL__DR CYREG_PRT12_DR
#define SCL__INP_DIS CYREG_PRT12_INP_DIS
#define SCL__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define SCL__MASK 0x01u
#define SCL__PORT 12u
#define SCL__PRT CYREG_PRT12_PRT
#define SCL__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define SCL__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define SCL__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define SCL__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define SCL__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define SCL__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define SCL__PS CYREG_PRT12_PS
#define SCL__SHIFT 0u
#define SCL__SIO_CFG CYREG_PRT12_SIO_CFG
#define SCL__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define SCL__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define SCL__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define SCL__SLW CYREG_PRT12_SLW

/* SDA */
#define SDA__0__INTTYPE CYREG_PICU12_INTTYPE1
#define SDA__0__MASK 0x02u
#define SDA__0__PC CYREG_PRT12_PC1
#define SDA__0__PORT 12u
#define SDA__0__SHIFT 1u
#define SDA__AG CYREG_PRT12_AG
#define SDA__BIE CYREG_PRT12_BIE
#define SDA__BIT_MASK CYREG_PRT12_BIT_MASK
#define SDA__BYP CYREG_PRT12_BYP
#define SDA__DM0 CYREG_PRT12_DM0
#define SDA__DM1 CYREG_PRT12_DM1
#define SDA__DM2 CYREG_PRT12_DM2
#define SDA__DR CYREG_PRT12_DR
#define SDA__INP_DIS CYREG_PRT12_INP_DIS
#define SDA__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define SDA__MASK 0x02u
#define SDA__PORT 12u
#define SDA__PRT CYREG_PRT12_PRT
#define SDA__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define SDA__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define SDA__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define SDA__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define SDA__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define SDA__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define SDA__PS CYREG_PRT12_PS
#define SDA__SHIFT 1u
#define SDA__SIO_CFG CYREG_PRT12_SIO_CFG
#define SDA__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define SDA__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define SDA__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define SDA__SLW CYREG_PRT12_SLW

/* LED_B */
#define LED_B__0__INTTYPE CYREG_PICU0_INTTYPE3
#define LED_B__0__MASK 0x08u
#define LED_B__0__PC CYREG_PRT0_PC3
#define LED_B__0__PORT 0u
#define LED_B__0__SHIFT 3u
#define LED_B__AG CYREG_PRT0_AG
#define LED_B__AMUX CYREG_PRT0_AMUX
#define LED_B__BIE CYREG_PRT0_BIE
#define LED_B__BIT_MASK CYREG_PRT0_BIT_MASK
#define LED_B__BYP CYREG_PRT0_BYP
#define LED_B__CTL CYREG_PRT0_CTL
#define LED_B__DM0 CYREG_PRT0_DM0
#define LED_B__DM1 CYREG_PRT0_DM1
#define LED_B__DM2 CYREG_PRT0_DM2
#define LED_B__DR CYREG_PRT0_DR
#define LED_B__INP_DIS CYREG_PRT0_INP_DIS
#define LED_B__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define LED_B__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define LED_B__LCD_EN CYREG_PRT0_LCD_EN
#define LED_B__MASK 0x08u
#define LED_B__PORT 0u
#define LED_B__PRT CYREG_PRT0_PRT
#define LED_B__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define LED_B__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define LED_B__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define LED_B__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define LED_B__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define LED_B__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define LED_B__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define LED_B__PS CYREG_PRT0_PS
#define LED_B__SHIFT 3u
#define LED_B__SLW CYREG_PRT0_SLW

/* LED_G */
#define LED_G__0__INTTYPE CYREG_PICU0_INTTYPE0
#define LED_G__0__MASK 0x01u
#define LED_G__0__PC CYREG_PRT0_PC0
#define LED_G__0__PORT 0u
#define LED_G__0__SHIFT 0u
#define LED_G__AG CYREG_PRT0_AG
#define LED_G__AMUX CYREG_PRT0_AMUX
#define LED_G__BIE CYREG_PRT0_BIE
#define LED_G__BIT_MASK CYREG_PRT0_BIT_MASK
#define LED_G__BYP CYREG_PRT0_BYP
#define LED_G__CTL CYREG_PRT0_CTL
#define LED_G__DM0 CYREG_PRT0_DM0
#define LED_G__DM1 CYREG_PRT0_DM1
#define LED_G__DM2 CYREG_PRT0_DM2
#define LED_G__DR CYREG_PRT0_DR
#define LED_G__INP_DIS CYREG_PRT0_INP_DIS
#define LED_G__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define LED_G__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define LED_G__LCD_EN CYREG_PRT0_LCD_EN
#define LED_G__MASK 0x01u
#define LED_G__PORT 0u
#define LED_G__PRT CYREG_PRT0_PRT
#define LED_G__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define LED_G__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define LED_G__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define LED_G__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define LED_G__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define LED_G__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define LED_G__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define LED_G__PS CYREG_PRT0_PS
#define LED_G__SHIFT 0u
#define LED_G__SLW CYREG_PRT0_SLW

/* LED_R */
#define LED_R__0__INTTYPE CYREG_PICU0_INTTYPE1
#define LED_R__0__MASK 0x02u
#define LED_R__0__PC CYREG_PRT0_PC1
#define LED_R__0__PORT 0u
#define LED_R__0__SHIFT 1u
#define LED_R__AG CYREG_PRT0_AG
#define LED_R__AMUX CYREG_PRT0_AMUX
#define LED_R__BIE CYREG_PRT0_BIE
#define LED_R__BIT_MASK CYREG_PRT0_BIT_MASK
#define LED_R__BYP CYREG_PRT0_BYP
#define LED_R__CTL CYREG_PRT0_CTL
#define LED_R__DM0 CYREG_PRT0_DM0
#define LED_R__DM1 CYREG_PRT0_DM1
#define LED_R__DM2 CYREG_PRT0_DM2
#define LED_R__DR CYREG_PRT0_DR
#define LED_R__INP_DIS CYREG_PRT0_INP_DIS
#define LED_R__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define LED_R__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define LED_R__LCD_EN CYREG_PRT0_LCD_EN
#define LED_R__MASK 0x02u
#define LED_R__PORT 0u
#define LED_R__PRT CYREG_PRT0_PRT
#define LED_R__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define LED_R__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define LED_R__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define LED_R__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define LED_R__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define LED_R__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define LED_R__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define LED_R__PS CYREG_PRT0_PS
#define LED_R__SHIFT 1u
#define LED_R__SLW CYREG_PRT0_SLW

/* Pin_EN */
#define Pin_EN__0__INTTYPE CYREG_PICU2_INTTYPE6
#define Pin_EN__0__MASK 0x40u
#define Pin_EN__0__PC CYREG_PRT2_PC6
#define Pin_EN__0__PORT 2u
#define Pin_EN__0__SHIFT 6u
#define Pin_EN__AG CYREG_PRT2_AG
#define Pin_EN__AMUX CYREG_PRT2_AMUX
#define Pin_EN__BIE CYREG_PRT2_BIE
#define Pin_EN__BIT_MASK CYREG_PRT2_BIT_MASK
#define Pin_EN__BYP CYREG_PRT2_BYP
#define Pin_EN__CTL CYREG_PRT2_CTL
#define Pin_EN__DM0 CYREG_PRT2_DM0
#define Pin_EN__DM1 CYREG_PRT2_DM1
#define Pin_EN__DM2 CYREG_PRT2_DM2
#define Pin_EN__DR CYREG_PRT2_DR
#define Pin_EN__INP_DIS CYREG_PRT2_INP_DIS
#define Pin_EN__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Pin_EN__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Pin_EN__LCD_EN CYREG_PRT2_LCD_EN
#define Pin_EN__MASK 0x40u
#define Pin_EN__PORT 2u
#define Pin_EN__PRT CYREG_PRT2_PRT
#define Pin_EN__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Pin_EN__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Pin_EN__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Pin_EN__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Pin_EN__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Pin_EN__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Pin_EN__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Pin_EN__PS CYREG_PRT2_PS
#define Pin_EN__SHIFT 6u
#define Pin_EN__SLW CYREG_PRT2_SLW

/* Pin_OC */
#define Pin_OC__0__INTTYPE CYREG_PICU2_INTTYPE5
#define Pin_OC__0__MASK 0x20u
#define Pin_OC__0__PC CYREG_PRT2_PC5
#define Pin_OC__0__PORT 2u
#define Pin_OC__0__SHIFT 5u
#define Pin_OC__AG CYREG_PRT2_AG
#define Pin_OC__AMUX CYREG_PRT2_AMUX
#define Pin_OC__BIE CYREG_PRT2_BIE
#define Pin_OC__BIT_MASK CYREG_PRT2_BIT_MASK
#define Pin_OC__BYP CYREG_PRT2_BYP
#define Pin_OC__CTL CYREG_PRT2_CTL
#define Pin_OC__DM0 CYREG_PRT2_DM0
#define Pin_OC__DM1 CYREG_PRT2_DM1
#define Pin_OC__DM2 CYREG_PRT2_DM2
#define Pin_OC__DR CYREG_PRT2_DR
#define Pin_OC__INP_DIS CYREG_PRT2_INP_DIS
#define Pin_OC__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Pin_OC__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Pin_OC__LCD_EN CYREG_PRT2_LCD_EN
#define Pin_OC__MASK 0x20u
#define Pin_OC__PORT 2u
#define Pin_OC__PRT CYREG_PRT2_PRT
#define Pin_OC__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Pin_OC__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Pin_OC__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Pin_OC__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Pin_OC__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Pin_OC__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Pin_OC__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Pin_OC__PS CYREG_PRT2_PS
#define Pin_OC__SHIFT 5u
#define Pin_OC__SLW CYREG_PRT2_SLW

/* Clock_1 */
#define Clock_1__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define Clock_1__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define Clock_1__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define Clock_1__INDEX 0x00u
#define Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_1__PM_ACT_MSK 0x01u
#define Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_1__PM_STBY_MSK 0x01u

/* LCD_Char_LCDPort */
#define LCD_Char_LCDPort__0__INTTYPE CYREG_PICU15_INTTYPE0
#define LCD_Char_LCDPort__0__MASK 0x01u
#define LCD_Char_LCDPort__0__PC CYREG_IO_PC_PRT15_PC0
#define LCD_Char_LCDPort__0__PORT 15u
#define LCD_Char_LCDPort__0__SHIFT 0u
#define LCD_Char_LCDPort__1__INTTYPE CYREG_PICU15_INTTYPE1
#define LCD_Char_LCDPort__1__MASK 0x02u
#define LCD_Char_LCDPort__1__PC CYREG_IO_PC_PRT15_PC1
#define LCD_Char_LCDPort__1__PORT 15u
#define LCD_Char_LCDPort__1__SHIFT 1u
#define LCD_Char_LCDPort__2__INTTYPE CYREG_PICU15_INTTYPE2
#define LCD_Char_LCDPort__2__MASK 0x04u
#define LCD_Char_LCDPort__2__PC CYREG_IO_PC_PRT15_PC2
#define LCD_Char_LCDPort__2__PORT 15u
#define LCD_Char_LCDPort__2__SHIFT 2u
#define LCD_Char_LCDPort__3__INTTYPE CYREG_PICU15_INTTYPE3
#define LCD_Char_LCDPort__3__MASK 0x08u
#define LCD_Char_LCDPort__3__PC CYREG_IO_PC_PRT15_PC3
#define LCD_Char_LCDPort__3__PORT 15u
#define LCD_Char_LCDPort__3__SHIFT 3u
#define LCD_Char_LCDPort__4__INTTYPE CYREG_PICU15_INTTYPE4
#define LCD_Char_LCDPort__4__MASK 0x10u
#define LCD_Char_LCDPort__4__PC CYREG_IO_PC_PRT15_PC4
#define LCD_Char_LCDPort__4__PORT 15u
#define LCD_Char_LCDPort__4__SHIFT 4u
#define LCD_Char_LCDPort__5__INTTYPE CYREG_PICU15_INTTYPE5
#define LCD_Char_LCDPort__5__MASK 0x20u
#define LCD_Char_LCDPort__5__PC CYREG_IO_PC_PRT15_PC5
#define LCD_Char_LCDPort__5__PORT 15u
#define LCD_Char_LCDPort__5__SHIFT 5u
#define LCD_Char_LCDPort__6__INTTYPE CYREG_PICU15_INTTYPE6
#define LCD_Char_LCDPort__6__MASK 0x40u
#define LCD_Char_LCDPort__6__PC CYREG_IO_PC_PRT15_7_6_PC0
#define LCD_Char_LCDPort__6__PORT 15u
#define LCD_Char_LCDPort__6__SHIFT 6u
#define LCD_Char_LCDPort__AG CYREG_PRT15_AG
#define LCD_Char_LCDPort__AMUX CYREG_PRT15_AMUX
#define LCD_Char_LCDPort__BIE CYREG_PRT15_BIE
#define LCD_Char_LCDPort__BIT_MASK CYREG_PRT15_BIT_MASK
#define LCD_Char_LCDPort__BYP CYREG_PRT15_BYP
#define LCD_Char_LCDPort__CTL CYREG_PRT15_CTL
#define LCD_Char_LCDPort__DM0 CYREG_PRT15_DM0
#define LCD_Char_LCDPort__DM1 CYREG_PRT15_DM1
#define LCD_Char_LCDPort__DM2 CYREG_PRT15_DM2
#define LCD_Char_LCDPort__DR CYREG_PRT15_DR
#define LCD_Char_LCDPort__INP_DIS CYREG_PRT15_INP_DIS
#define LCD_Char_LCDPort__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define LCD_Char_LCDPort__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define LCD_Char_LCDPort__LCD_EN CYREG_PRT15_LCD_EN
#define LCD_Char_LCDPort__MASK 0x7Fu
#define LCD_Char_LCDPort__PORT 15u
#define LCD_Char_LCDPort__PRT CYREG_PRT15_PRT
#define LCD_Char_LCDPort__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define LCD_Char_LCDPort__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define LCD_Char_LCDPort__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define LCD_Char_LCDPort__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define LCD_Char_LCDPort__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define LCD_Char_LCDPort__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define LCD_Char_LCDPort__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define LCD_Char_LCDPort__PS CYREG_PRT15_PS
#define LCD_Char_LCDPort__SHIFT 0u
#define LCD_Char_LCDPort__SLW CYREG_PRT15_SLW

/* Pin_XRES */
#define Pin_XRES__0__INTTYPE CYREG_PICU1_INTTYPE7
#define Pin_XRES__0__MASK 0x80u
#define Pin_XRES__0__PC CYREG_PRT1_PC7
#define Pin_XRES__0__PORT 1u
#define Pin_XRES__0__SHIFT 7u
#define Pin_XRES__AG CYREG_PRT1_AG
#define Pin_XRES__AMUX CYREG_PRT1_AMUX
#define Pin_XRES__BIE CYREG_PRT1_BIE
#define Pin_XRES__BIT_MASK CYREG_PRT1_BIT_MASK
#define Pin_XRES__BYP CYREG_PRT1_BYP
#define Pin_XRES__CTL CYREG_PRT1_CTL
#define Pin_XRES__DM0 CYREG_PRT1_DM0
#define Pin_XRES__DM1 CYREG_PRT1_DM1
#define Pin_XRES__DM2 CYREG_PRT1_DM2
#define Pin_XRES__DR CYREG_PRT1_DR
#define Pin_XRES__INP_DIS CYREG_PRT1_INP_DIS
#define Pin_XRES__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU1_BASE
#define Pin_XRES__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define Pin_XRES__LCD_EN CYREG_PRT1_LCD_EN
#define Pin_XRES__MASK 0x80u
#define Pin_XRES__PORT 1u
#define Pin_XRES__PRT CYREG_PRT1_PRT
#define Pin_XRES__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define Pin_XRES__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define Pin_XRES__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define Pin_XRES__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define Pin_XRES__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define Pin_XRES__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define Pin_XRES__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define Pin_XRES__PS CYREG_PRT1_PS
#define Pin_XRES__SHIFT 7u
#define Pin_XRES__SLW CYREG_PRT1_SLW

/* Pin_SWDCK */
#define Pin_SWDCK__0__INTTYPE CYREG_PICU1_INTTYPE6
#define Pin_SWDCK__0__MASK 0x40u
#define Pin_SWDCK__0__PC CYREG_PRT1_PC6
#define Pin_SWDCK__0__PORT 1u
#define Pin_SWDCK__0__SHIFT 6u
#define Pin_SWDCK__AG CYREG_PRT1_AG
#define Pin_SWDCK__AMUX CYREG_PRT1_AMUX
#define Pin_SWDCK__BIE CYREG_PRT1_BIE
#define Pin_SWDCK__BIT_MASK CYREG_PRT1_BIT_MASK
#define Pin_SWDCK__BYP CYREG_PRT1_BYP
#define Pin_SWDCK__CTL CYREG_PRT1_CTL
#define Pin_SWDCK__DM0 CYREG_PRT1_DM0
#define Pin_SWDCK__DM1 CYREG_PRT1_DM1
#define Pin_SWDCK__DM2 CYREG_PRT1_DM2
#define Pin_SWDCK__DR CYREG_PRT1_DR
#define Pin_SWDCK__INP_DIS CYREG_PRT1_INP_DIS
#define Pin_SWDCK__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU1_BASE
#define Pin_SWDCK__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define Pin_SWDCK__LCD_EN CYREG_PRT1_LCD_EN
#define Pin_SWDCK__MASK 0x40u
#define Pin_SWDCK__PORT 1u
#define Pin_SWDCK__PRT CYREG_PRT1_PRT
#define Pin_SWDCK__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define Pin_SWDCK__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define Pin_SWDCK__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define Pin_SWDCK__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define Pin_SWDCK__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define Pin_SWDCK__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define Pin_SWDCK__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define Pin_SWDCK__PS CYREG_PRT1_PS
#define Pin_SWDCK__SHIFT 6u
#define Pin_SWDCK__SLW CYREG_PRT1_SLW

/* Pin_SWDIO */
#define Pin_SWDIO__0__INTTYPE CYREG_PICU1_INTTYPE5
#define Pin_SWDIO__0__MASK 0x20u
#define Pin_SWDIO__0__PC CYREG_PRT1_PC5
#define Pin_SWDIO__0__PORT 1u
#define Pin_SWDIO__0__SHIFT 5u
#define Pin_SWDIO__AG CYREG_PRT1_AG
#define Pin_SWDIO__AMUX CYREG_PRT1_AMUX
#define Pin_SWDIO__BIE CYREG_PRT1_BIE
#define Pin_SWDIO__BIT_MASK CYREG_PRT1_BIT_MASK
#define Pin_SWDIO__BYP CYREG_PRT1_BYP
#define Pin_SWDIO__CTL CYREG_PRT1_CTL
#define Pin_SWDIO__DM0 CYREG_PRT1_DM0
#define Pin_SWDIO__DM1 CYREG_PRT1_DM1
#define Pin_SWDIO__DM2 CYREG_PRT1_DM2
#define Pin_SWDIO__DR CYREG_PRT1_DR
#define Pin_SWDIO__INP_DIS CYREG_PRT1_INP_DIS
#define Pin_SWDIO__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU1_BASE
#define Pin_SWDIO__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define Pin_SWDIO__LCD_EN CYREG_PRT1_LCD_EN
#define Pin_SWDIO__MASK 0x20u
#define Pin_SWDIO__PORT 1u
#define Pin_SWDIO__PRT CYREG_PRT1_PRT
#define Pin_SWDIO__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define Pin_SWDIO__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define Pin_SWDIO__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define Pin_SWDIO__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define Pin_SWDIO__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define Pin_SWDIO__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define Pin_SWDIO__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define Pin_SWDIO__PS CYREG_PRT1_PS
#define Pin_SWDIO__SHIFT 5u
#define Pin_SWDIO__SLW CYREG_PRT1_SLW

/* Pin_Start */
#define Pin_Start__0__INTTYPE CYREG_PICU3_INTTYPE5
#define Pin_Start__0__MASK 0x20u
#define Pin_Start__0__PC CYREG_PRT3_PC5
#define Pin_Start__0__PORT 3u
#define Pin_Start__0__SHIFT 5u
#define Pin_Start__AG CYREG_PRT3_AG
#define Pin_Start__AMUX CYREG_PRT3_AMUX
#define Pin_Start__BIE CYREG_PRT3_BIE
#define Pin_Start__BIT_MASK CYREG_PRT3_BIT_MASK
#define Pin_Start__BYP CYREG_PRT3_BYP
#define Pin_Start__CTL CYREG_PRT3_CTL
#define Pin_Start__DM0 CYREG_PRT3_DM0
#define Pin_Start__DM1 CYREG_PRT3_DM1
#define Pin_Start__DM2 CYREG_PRT3_DM2
#define Pin_Start__DR CYREG_PRT3_DR
#define Pin_Start__INP_DIS CYREG_PRT3_INP_DIS
#define Pin_Start__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Pin_Start__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Pin_Start__LCD_EN CYREG_PRT3_LCD_EN
#define Pin_Start__MASK 0x20u
#define Pin_Start__PORT 3u
#define Pin_Start__PRT CYREG_PRT3_PRT
#define Pin_Start__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Pin_Start__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Pin_Start__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Pin_Start__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Pin_Start__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Pin_Start__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Pin_Start__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Pin_Start__PS CYREG_PRT3_PS
#define Pin_Start__SHIFT 5u
#define Pin_Start__SLW CYREG_PRT3_SLW

/* Control_Reg */
#define Control_Reg_Sync_ctrl_reg__0__MASK 0x01u
#define Control_Reg_Sync_ctrl_reg__0__POS 0
#define Control_Reg_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG CYREG_B1_UDB05_06_ACTL
#define Control_Reg_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG CYREG_B1_UDB05_06_CTL
#define Control_Reg_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG CYREG_B1_UDB05_06_CTL
#define Control_Reg_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG CYREG_B1_UDB05_06_CTL
#define Control_Reg_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG CYREG_B1_UDB05_06_CTL
#define Control_Reg_Sync_ctrl_reg__16BIT_MASK_MASK_REG CYREG_B1_UDB05_06_MSK
#define Control_Reg_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG CYREG_B1_UDB05_06_MSK
#define Control_Reg_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG CYREG_B1_UDB05_06_MSK
#define Control_Reg_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG CYREG_B1_UDB05_06_MSK
#define Control_Reg_Sync_ctrl_reg__CONTROL_AUX_CTL_REG CYREG_B1_UDB05_ACTL
#define Control_Reg_Sync_ctrl_reg__CONTROL_REG CYREG_B1_UDB05_CTL
#define Control_Reg_Sync_ctrl_reg__CONTROL_ST_REG CYREG_B1_UDB05_ST_CTL
#define Control_Reg_Sync_ctrl_reg__COUNT_REG CYREG_B1_UDB05_CTL
#define Control_Reg_Sync_ctrl_reg__COUNT_ST_REG CYREG_B1_UDB05_ST_CTL
#define Control_Reg_Sync_ctrl_reg__MASK 0x01u
#define Control_Reg_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG CYREG_B1_UDB05_MSK_ACTL
#define Control_Reg_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG CYREG_B1_UDB05_MSK_ACTL
#define Control_Reg_Sync_ctrl_reg__PERIOD_REG CYREG_B1_UDB05_MSK

/* Pin_BatLevel */
#define Pin_BatLevel__0__INTTYPE CYREG_PICU0_INTTYPE4
#define Pin_BatLevel__0__MASK 0x10u
#define Pin_BatLevel__0__PC CYREG_PRT0_PC4
#define Pin_BatLevel__0__PORT 0u
#define Pin_BatLevel__0__SHIFT 4u
#define Pin_BatLevel__AG CYREG_PRT0_AG
#define Pin_BatLevel__AMUX CYREG_PRT0_AMUX
#define Pin_BatLevel__BIE CYREG_PRT0_BIE
#define Pin_BatLevel__BIT_MASK CYREG_PRT0_BIT_MASK
#define Pin_BatLevel__BYP CYREG_PRT0_BYP
#define Pin_BatLevel__CTL CYREG_PRT0_CTL
#define Pin_BatLevel__DM0 CYREG_PRT0_DM0
#define Pin_BatLevel__DM1 CYREG_PRT0_DM1
#define Pin_BatLevel__DM2 CYREG_PRT0_DM2
#define Pin_BatLevel__DR CYREG_PRT0_DR
#define Pin_BatLevel__INP_DIS CYREG_PRT0_INP_DIS
#define Pin_BatLevel__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define Pin_BatLevel__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define Pin_BatLevel__LCD_EN CYREG_PRT0_LCD_EN
#define Pin_BatLevel__MASK 0x10u
#define Pin_BatLevel__PORT 0u
#define Pin_BatLevel__PRT CYREG_PRT0_PRT
#define Pin_BatLevel__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define Pin_BatLevel__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define Pin_BatLevel__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define Pin_BatLevel__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define Pin_BatLevel__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define Pin_BatLevel__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define Pin_BatLevel__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define Pin_BatLevel__PS CYREG_PRT0_PS
#define Pin_BatLevel__SHIFT 4u
#define Pin_BatLevel__SLW CYREG_PRT0_SLW

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 62999999U
#define BCLK__BUS_CLK__KHZ 62999U
#define BCLK__BUS_CLK__MHZ 62U
#define CY_PROJECT_NAME "Programmer"
#define CY_VERSION "PSoC Creator  4.0 Update 1"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 12u
#define CYDEV_CHIP_DIE_PSOC5LP 19u
#define CYDEV_CHIP_DIE_PSOC5TM 20u
#define CYDEV_CHIP_DIE_TMA4 2u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 4u
#define CYDEV_CHIP_FAMILY_FM3 5u
#define CYDEV_CHIP_FAMILY_FM4 6u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 12u
#define CYDEV_CHIP_MEMBER_4C 18u
#define CYDEV_CHIP_MEMBER_4D 8u
#define CYDEV_CHIP_MEMBER_4E 4u
#define CYDEV_CHIP_MEMBER_4F 13u
#define CYDEV_CHIP_MEMBER_4G 2u
#define CYDEV_CHIP_MEMBER_4H 11u
#define CYDEV_CHIP_MEMBER_4I 17u
#define CYDEV_CHIP_MEMBER_4J 9u
#define CYDEV_CHIP_MEMBER_4K 10u
#define CYDEV_CHIP_MEMBER_4L 16u
#define CYDEV_CHIP_MEMBER_4M 15u
#define CYDEV_CHIP_MEMBER_4N 6u
#define CYDEV_CHIP_MEMBER_4O 5u
#define CYDEV_CHIP_MEMBER_4P 14u
#define CYDEV_CHIP_MEMBER_4Q 7u
#define CYDEV_CHIP_MEMBER_4U 3u
#define CYDEV_CHIP_MEMBER_5A 20u
#define CYDEV_CHIP_MEMBER_5B 19u
#define CYDEV_CHIP_MEMBER_FM3 24u
#define CYDEV_CHIP_MEMBER_FM4 25u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 21u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 22u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 23u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4C_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x1000
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000001u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x4000
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 3.30
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.30
#define CYDEV_VDDD_MV 3300
#define CYDEV_VDDIO0 3.30
#define CYDEV_VDDIO0_MV 3300
#define CYDEV_VDDIO1 3.30
#define CYDEV_VDDIO1_MV 3300
#define CYDEV_VDDIO2 3.30
#define CYDEV_VDDIO2_MV 3300
#define CYDEV_VDDIO3 3.30
#define CYDEV_VDDIO3_MV 3300
#define CYDEV_VIO0 3.30
#define CYDEV_VIO0_MV 3300
#define CYDEV_VIO1 3.30
#define CYDEV_VIO1_MV 3300
#define CYDEV_VIO2 3.30
#define CYDEV_VIO2_MV 3300
#define CYDEV_VIO3 3.30
#define CYDEV_VIO3_MV 3300
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
