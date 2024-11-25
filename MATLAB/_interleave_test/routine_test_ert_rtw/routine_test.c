/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: routine_test.c
 *
 * Code generated for Simulink model 'routine_test'.
 *
 * Model version                  : 9.11
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Nov 21 13:22:55 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "routine_test.h"
#include "routine_test_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
BlockIO_routine_test routine_test_B;

/* Real-time model */
static RT_MODEL_routine_test routine_test_M_;
RT_MODEL_routine_test *const routine_test_M = &routine_test_M_;
uint16_T MW_adcInitFlag = 0;

/* Model initialize function */
void routine_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(routine_test_M, (NULL));

  /* block I/O */
  {
    routine_test_B.ADC_o1 = 0.0;
    routine_test_B.ADC_o2 = 0.0;
  }

  /* Start for S-Function (HardwareInterrupt_sfun): '<S4>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC-PWM Subsystem'
   */

  /* Start for function-call system: '<Root>/ADC-PWM Subsystem' */

  /* Start for S-Function (c280xadc): '<S1>/ADC' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_A (1U, 16U, 0U, 0U, 0U);

  /* Start for S-Function (c280xpwm): '<S1>/ePWM' */

  /*** Initialize ePWM2 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 7500;

    /* // Time-Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL   = 1;          // Sync output select
       EPwm2Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
       EPwm2Regs.TBCTL.bit.PHSEN      = 1;          // Phase load enable
       EPwm2Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm2Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm2Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FBF) | 0x16;

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
    EPwm2Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm2Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
       EPwm2Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
       EPwm2Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm2Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm2Regs.CMPA.half.CMPA = 0;
    EPwm2Regs.CMPB = 0;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 96;
    EPwm2Regs.AQCTLB.all = 264;

    /* // Action-Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm2Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE   = 3;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL     = 2;          // Polarity Select Control
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x3F) | 0xB;
    EPwm2Regs.DBRED = 420;
    EPwm2Regs.DBFED = 420;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN     = 1;          // Start of conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASEL    = 2;          // Start of conversion A Select
       EPwm2Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM2SOCA Period Select
       EPwm2Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm2Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSEL.bit.INTEN      = 0;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSEL     = 4;          // EPWM2INTn Select
       EPwm2Regs.ETPS.bit.INTPRD      = 1;          // EPWM2INTn Period Select
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0F) | 0x1A04;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM2B
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c280xpwm): '<S1>/ePWM1' */

  /*** Initialize ePWM3 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 7500;

    /* // Time-Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL   = 1;          // Sync output select
       EPwm3Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
       EPwm3Regs.TBCTL.bit.PHSEN      = 1;          // Phase load enable
       EPwm3Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm3Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm3Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FBF) | 0x16;

    /* // Time-Base Phase Register
       EPwm3Regs.TBPHS.half.TBPHS     = 5000;          // Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000) | 0x13880000;
    EPwm3Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm3Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
       EPwm3Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
       EPwm3Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm3Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm3Regs.CMPA.half.CMPA = 0;
    EPwm3Regs.CMPB = 0;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 96;
    EPwm3Regs.AQCTLB.all = 264;

    /* // Action-Qualifier Software Force Register
       EPwm3Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm3Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm3Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm3Regs.DBCTL.bit.OUT_MODE   = 3;          // Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL     = 2;          // Polarity Select Control
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x3F) | 0xB;
    EPwm3Regs.DBRED = 420;
    EPwm3Regs.DBFED = 420;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASEL    = 2;          // Start of conversion A Select
       EPwm3Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM3SOCA Period Select
       EPwm3Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm3Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM3SOCB Period Select
       EPwm3Regs.ETSEL.bit.INTEN      = 0;          // EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSEL     = 1;          // EPWM3INTn Select
       EPwm3Regs.ETPS.bit.INTPRD      = 1;          // EPWM3INTn Period Select
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF0F) | 0x1201;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm3Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm3Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm3Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm3Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm3Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm3Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM3A
       EPwm3Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM3B
     */
    EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm3Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm3Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c280xpwm): '<S1>/ePWM2' */

  /*** Initialize ePWM6 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm6Regs.TBPRD = 7500;

    /* // Time-Base Control Register
       EPwm6Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
       EPwm6Regs.TBCTL.bit.SYNCOSEL   = 1;          // Sync output select
       EPwm6Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
       EPwm6Regs.TBCTL.bit.PHSEN      = 1;          // Phase load enable
       EPwm6Regs.TBCTL.bit.PHSDIR     = 1;          // Phase Direction
       EPwm6Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm6Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm6Regs.TBCTL.all = (EPwm6Regs.TBCTL.all & ~0x3FBF) | 0x2016;

    /* // Time-Base Phase Register
       EPwm6Regs.TBPHS.half.TBPHS     = 5000;          // Phase offset register
     */
    EPwm6Regs.TBPHS.all = (EPwm6Regs.TBPHS.all & ~0xFFFF0000) | 0x13880000;
    EPwm6Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm6Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
       EPwm6Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
       EPwm6Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm6Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm6Regs.CMPCTL.all = (EPwm6Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm6Regs.CMPA.half.CMPA = 0;
    EPwm6Regs.CMPB = 0;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm6Regs.AQCTLA.all = 96;
    EPwm6Regs.AQCTLB.all = 264;

    /* // Action-Qualifier Software Force Register
       EPwm6Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm6Regs.AQSFRC.all = (EPwm6Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm6Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm6Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm6Regs.AQCSFRC.all = (EPwm6Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm6Regs.DBCTL.bit.OUT_MODE   = 3;          // Dead Band Output Mode Control
       EPwm6Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm6Regs.DBCTL.bit.POLSEL     = 2;          // Polarity Select Control
     */
    EPwm6Regs.DBCTL.all = (EPwm6Regs.DBCTL.all & ~0x3F) | 0xB;
    EPwm6Regs.DBRED = 420;
    EPwm6Regs.DBFED = 420;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm6Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm6Regs.ETSEL.bit.SOCASEL    = 2;          // Start of conversion A Select
       EPwm6Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM6SOCA Period Select
       EPwm6Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm6Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm6Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM6SOCB Period Select
       EPwm6Regs.ETSEL.bit.INTEN      = 0;          // EPWM6INTn Enable
       EPwm6Regs.ETSEL.bit.INTSEL     = 1;          // EPWM6INTn Select
       EPwm6Regs.ETPS.bit.INTPRD      = 1;          // EPWM6INTn Period Select
     */
    EPwm6Regs.ETSEL.all = (EPwm6Regs.ETSEL.all & ~0xFF0F) | 0x1201;
    EPwm6Regs.ETPS.all = (EPwm6Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm6Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm6Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm6Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm6Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm6Regs.PCCTL.all = (EPwm6Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm6Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm6Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM6A
       EPwm6Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM6B
     */
    EPwm6Regs.TZCTL.all = (EPwm6Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm6Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm6Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm6Regs.TZEINT.all = (EPwm6Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c280xpwm): '<S1>/pass to ePWM5' */

  /*** Initialize ePWM4 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm4Regs.TBPRD = 7500;

    /* // Time-Base Control Register
       EPwm4Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
       EPwm4Regs.TBCTL.bit.SYNCOSEL   = 1;          // Sync output select
       EPwm4Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
       EPwm4Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
       EPwm4Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm4Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm4Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm4Regs.TBCTL.all = (EPwm4Regs.TBCTL.all & ~0x3FBF) | 0x12;

    /* // Time-Base Phase Register
       EPwm4Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
     */
    EPwm4Regs.TBPHS.all = (EPwm4Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
    EPwm4Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm4Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
       EPwm4Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
       EPwm4Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm4Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm4Regs.CMPCTL.all = (EPwm4Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm4Regs.CMPA.half.CMPA = 0;
    EPwm4Regs.CMPB = 0;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm4Regs.AQCTLA.all = 96;
    EPwm4Regs.AQCTLB.all = 264;

    /* // Action-Qualifier Software Force Register
       EPwm4Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm4Regs.AQSFRC.all = (EPwm4Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm4Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm4Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm4Regs.AQCSFRC.all = (EPwm4Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm4Regs.DBCTL.bit.OUT_MODE   = 0;          // Dead Band Output Mode Control
       EPwm4Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm4Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
     */
    EPwm4Regs.DBCTL.all = (EPwm4Regs.DBCTL.all & ~0x3F) | 0x0;
    EPwm4Regs.DBRED = 0;
    EPwm4Regs.DBFED = 0;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm4Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm4Regs.ETSEL.bit.SOCASEL    = 2;          // Start of conversion A Select
       EPwm4Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM4SOCA Period Select
       EPwm4Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm4Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm4Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM4SOCB Period Select
       EPwm4Regs.ETSEL.bit.INTEN      = 0;          // EPWM4INTn Enable
       EPwm4Regs.ETSEL.bit.INTSEL     = 4;          // EPWM4INTn Select
       EPwm4Regs.ETPS.bit.INTPRD      = 1;          // EPWM4INTn Period Select
     */
    EPwm4Regs.ETSEL.all = (EPwm4Regs.ETSEL.all & ~0xFF0F) | 0x1204;
    EPwm4Regs.ETPS.all = (EPwm4Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm4Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm4Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm4Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm4Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm4Regs.PCCTL.all = (EPwm4Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm4Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm4Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM4A
       EPwm4Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM4B
     */
    EPwm4Regs.TZCTL.all = (EPwm4Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm4Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm4Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm4Regs.TZEINT.all = (EPwm4Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c280xpwm): '<S1>/pass to ePWM6' */

  /*** Initialize ePWM5 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm5Regs.TBPRD = 7500;

    /* // Time-Base Control Register
       EPwm5Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
       EPwm5Regs.TBCTL.bit.SYNCOSEL   = 1;          // Sync output select
       EPwm5Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
       EPwm5Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
       EPwm5Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm5Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm5Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm5Regs.TBCTL.all = (EPwm5Regs.TBCTL.all & ~0x3FBF) | 0x12;

    /* // Time-Base Phase Register
       EPwm5Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
     */
    EPwm5Regs.TBPHS.all = (EPwm5Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
    EPwm5Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm5Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
       EPwm5Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
       EPwm5Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm5Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm5Regs.CMPCTL.all = (EPwm5Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm5Regs.CMPA.half.CMPA = 0;
    EPwm5Regs.CMPB = 0;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm5Regs.AQCTLA.all = 96;
    EPwm5Regs.AQCTLB.all = 264;

    /* // Action-Qualifier Software Force Register
       EPwm5Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm5Regs.AQSFRC.all = (EPwm5Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm5Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm5Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm5Regs.AQCSFRC.all = (EPwm5Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm5Regs.DBCTL.bit.OUT_MODE   = 0;          // Dead Band Output Mode Control
       EPwm5Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm5Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
     */
    EPwm5Regs.DBCTL.all = (EPwm5Regs.DBCTL.all & ~0x3F) | 0x0;
    EPwm5Regs.DBRED = 0;
    EPwm5Regs.DBFED = 0;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm5Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm5Regs.ETSEL.bit.SOCASEL    = 2;          // Start of conversion A Select
       EPwm5Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM5SOCA Period Select
       EPwm5Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm5Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm5Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM5SOCB Period Select
       EPwm5Regs.ETSEL.bit.INTEN      = 0;          // EPWM5INTn Enable
       EPwm5Regs.ETSEL.bit.INTSEL     = 4;          // EPWM5INTn Select
       EPwm5Regs.ETPS.bit.INTPRD      = 1;          // EPWM5INTn Period Select
     */
    EPwm5Regs.ETSEL.all = (EPwm5Regs.ETSEL.all & ~0xFF0F) | 0x1204;
    EPwm5Regs.ETPS.all = (EPwm5Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm5Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm5Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm5Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm5Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm5Regs.PCCTL.all = (EPwm5Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm5Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm5Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM5A
       EPwm5Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM5B
     */
    EPwm5Regs.TZCTL.all = (EPwm5Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm5Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm5Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm5Regs.TZEINT.all = (EPwm5Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* End of Start for S-Function (HardwareInterrupt_sfun): '<S4>/Hardware Interrupt' */
}

/* Model terminate function */
void routine_test_terminate(void)
{
  /* (no terminate code required) */
}

void routine_test_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(32,&SEQ1INT,0);
  HWI_TIC28x_EnableIRQ(32);
}

/* Hardware Interrupt Block: '<S4>/Hardware Interrupt' */
interrupt void SEQ1INT(void)
{
  /* Event: End of sequence event */
  /* Check event End of sequence event occurred */
  if (0 != (AdcRegs.ADCST.bit.INT_SEQ1==1)) {
    if (1 == runModel) {
      {
        /* S-Function (HardwareInterrupt_sfun): '<S4>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/ADC-PWM Subsystem' */
        {
          real_T tmp;
          uint16_T rtb_DutyCycle;

          /* S-Function (c280xadc): '<S1>/ADC' */
          {
            routine_test_B.ADC_o1 = (AdcRegs.ADCRESULT0) >> 4;
            routine_test_B.ADC_o2 = (AdcRegs.ADCRESULT1) >> 4;
            AdcRegs.ADCTRL2.bit.RST_SEQ1 = 0x1U;/* Sequencer reset*/
          }

          /* DataTypeConversion: '<S1>/Cast To Single2' incorporates:
           *  Gain: '<S1>/Gain1'
           *  Gain: '<S1>/Gain3'
           */
          tmp = floor(1.0 / routine_test_P.ADC_mapping * routine_test_B.ADC_o1 *
                      routine_test_P.TBPRD);
          if (rtIsNaN(tmp) || rtIsInf(tmp)) {
            tmp = 0.0;
          } else {
            tmp = fmod(tmp, 65536.0);
          }

          rtb_DutyCycle = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp :
            (uint16_T)tmp;

          /* End of DataTypeConversion: '<S1>/Cast To Single2' */

          /* S-Function (c280xpwm): '<S1>/ePWM' */

          /*-- Update CMPA value for ePWM2 --*/
          {
            EPwm2Regs.CMPA.half.CMPA = (uint16_T)(rtb_DutyCycle);
          }

          /* S-Function (c280xpwm): '<S1>/ePWM1' */

          /*-- Update CMPA value for ePWM3 --*/
          {
            EPwm3Regs.CMPA.half.CMPA = (uint16_T)(rtb_DutyCycle);
          }

          /* S-Function (c280xpwm): '<S1>/ePWM2' */

          /*-- Update CMPA value for ePWM6 --*/
          {
            EPwm6Regs.CMPA.half.CMPA = (uint16_T)(rtb_DutyCycle);
          }
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S4>/Hardware Interrupt' */
      }
    }

    /* Clear occurred End of sequence event event */
    AdcRegs.ADCST.bit.INT_SEQ1_CLR= 1;
  }

  HWI_TIC28x_AcknowledgeIrq(32);
}

void routine_test_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(32);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
