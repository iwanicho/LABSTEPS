/*
 * Z_inCL1.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_inCL1".
 *
 * Model version              : 9.31
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Jan 16 12:28:05 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Z_inCL1.h"
#include "Z_inCL1_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_Z_inCL1_T Z_inCL1_B;

/* Block states (default storage) */
DW_Z_inCL1_T Z_inCL1_DW;

/* Real-time model */
static RT_MODEL_Z_inCL1_T Z_inCL1_M_;
RT_MODEL_Z_inCL1_T *const Z_inCL1_M = &Z_inCL1_M_;
uint16_T MW_adcInitFlag = 0;

/* Model initialize function */
void Z_inCL1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Z_inCL1_M, (NULL));

  /* block I/O */
  {
    Z_inCL1_B.analogdial_o1 = 0.0;
    Z_inCL1_B.analogdial_o2 = 0.0;
    Z_inCL1_B.analogdial_o3 = 0.0;
    Z_inCL1_B.analogdial_o4 = 0.0;
    Z_inCL1_B.analogdial_o5 = 0.0;
    Z_inCL1_B.analogdial_o6 = 0.0;
  }

  /* states (dwork) */
  Z_inCL1_DW.discreteintegrator_states = 0.0;
  Z_inCL1_DW.Memory3_PreviousInput = 0.0;

  /* Start for S-Function (HardwareInterrupt_sfun): '<S7>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC-PWM Subsystem'
   */

  /* Start for function-call system: '<Root>/ADC-PWM Subsystem' */

  /* Start for S-Function (c280xadc): '<S1>/analog dial' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_A (5U, 12816U, 84U, 0U, 0U);

  /* Start for S-Function (c280xpwm): '<S1>/ePWM3' */

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
       EPwm3Regs.ETSEL.bit.SOCAEN     = 1;          // Start of conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASEL    = 2;          // Start of conversion A Select
       EPwm3Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM3SOCA Period Select
       EPwm3Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm3Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM3SOCB Period Select
       EPwm3Regs.ETSEL.bit.INTEN      = 0;          // EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSEL     = 1;          // EPWM3INTn Select
       EPwm3Regs.ETPS.bit.INTPRD      = 1;          // EPWM3INTn Period Select
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF0F) | 0x1A01;
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

  /* Start for S-Function (c280xpwm): '<S1>/ref observer' */

  /*** Initialize ePWM1 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 7500;

    /* // Time-Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL   = 1;          // Sync output select
       EPwm1Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
       EPwm1Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
       EPwm1Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm1Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm1Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FBF) | 0x12;

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
    EPwm1Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm1Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
       EPwm1Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
       EPwm1Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm1Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm1Regs.CMPA.half.CMPA = 0;
    EPwm1Regs.CMPB = 0;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 96;
    EPwm1Regs.AQCTLB.all = 264;

    /* // Action-Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm1Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE   = 0;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x3F) | 0x0;
    EPwm1Regs.DBRED = 0;
    EPwm1Regs.DBFED = 0;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASEL    = 2;          // Start of conversion A Select
       EPwm1Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM1SOCA Period Select
       EPwm1Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm1Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSEL.bit.INTEN      = 0;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSEL     = 1;          // EPWM1INTn Select
       EPwm1Regs.ETPS.bit.INTPRD      = 1;          // EPWM1INTn Period Select
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0F) | 0x1201;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM1B
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* End of Start for S-Function (HardwareInterrupt_sfun): '<S7>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S7>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC-PWM Subsystem'
   */

  /* System initialize for function-call system: '<Root>/ADC-PWM Subsystem' */

  /* InitializeConditions for Memory: '<S3>/Memory3' */
  Z_inCL1_DW.Memory3_PreviousInput = Z_inCL1_P.Memory3_InitialCondition;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/discrete integrator' */
  Z_inCL1_DW.discreteintegrator_states =
    Z_inCL1_P.discreteintegrator_InitialState;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S7>/Hardware Interrupt' */
}

/* Model terminate function */
void Z_inCL1_terminate(void)
{
  /* (no terminate code required) */
}

void Z_inCL1_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(32,&SEQ1INT,0);
  HWI_TIC28x_EnableIRQ(32);
}

/* Hardware Interrupt Block: '<S7>/Hardware Interrupt' */
interrupt void SEQ1INT(void)
{
  /* Event: End of sequence event */
  /* Check event End of sequence event occurred */
  if (0 != (AdcRegs.ADCST.bit.INT_SEQ1==1)) {
    if (1 == runModel) {
      {
        /* S-Function (HardwareInterrupt_sfun): '<S7>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/ADC-PWM Subsystem' */
        {
          real_T discreteintegrator_tmp;
          real_T rtb_Gain;
          real_T rtb_Gain1_o;
          real_T rtb_Gain3;
          real_T rtb_Gain4;
          real_T x_idx_1;

          /* Gain: '<S3>/Gain3' incorporates:
           *  Constant: '<S1>/Constant2'
           */
          rtb_Gain3 = Z_inCL1_P.VLlim * Z_inCL1_P.Constant2_Value;

          /* S-Function (c280xadc): '<S1>/analog dial' */
          {
            Z_inCL1_B.analogdial_o1 = (AdcRegs.ADCRESULT0) >> 4;
            Z_inCL1_B.analogdial_o2 = (AdcRegs.ADCRESULT1) >> 4;
            Z_inCL1_B.analogdial_o3 = (AdcRegs.ADCRESULT2) >> 4;
            Z_inCL1_B.analogdial_o4 = (AdcRegs.ADCRESULT3) >> 4;
            Z_inCL1_B.analogdial_o5 = (AdcRegs.ADCRESULT4) >> 4;
            Z_inCL1_B.analogdial_o6 = (AdcRegs.ADCRESULT5) >> 4;
            AdcRegs.ADCTRL2.bit.RST_SEQ1 = 0x1U;/* Sequencer reset*/
          }

          /* Gain: '<S1>/Gain2' incorporates:
           *  Fcn: '<S1>/Fcn5'
           *  Gain: '<S1>/Gain8'
           */
          rtb_Gain4 = (1.0 / Z_inCL1_P.ADC_mapping * Z_inCL1_B.analogdial_o3 *
                       2.0 * 10.0 - 10.0) * Z_inCL1_P.Gain2_Gain;

          /* DiscreteTransferFcn: '<S3>/discrete integrator' incorporates:
           *  Constant: '<S1>/Constant'
           *  Gain: '<S3>/Gain'
           *  Memory: '<S3>/Memory3'
           *  Sum: '<S3>/Sum'
           *  Sum: '<S3>/Sum3'
           */
          discreteintegrator_tmp = (((Z_inCL1_P.Constant_Value - rtb_Gain4) -
            Z_inCL1_DW.Memory3_PreviousInput) * Z_inCL1_P.ki_i -
            Z_inCL1_P.zden_Integrator[1L] * Z_inCL1_DW.discreteintegrator_states)
            / Z_inCL1_P.zden_Integrator[0];

          /* Sum: '<S3>/Sum1' incorporates:
           *  DiscreteTransferFcn: '<S3>/discrete integrator'
           *  Gain: '<S3>/Gain1'
           */
          rtb_Gain = (Z_inCL1_P.znum_Integrator[0] * discreteintegrator_tmp +
                      Z_inCL1_P.znum_Integrator[1L] *
                      Z_inCL1_DW.discreteintegrator_states) - Z_inCL1_P.kp_i *
            rtb_Gain4;

          /* Gain: '<S1>/Gain12' incorporates:
           *  Gain: '<S1>/Gain9'
           */
          rtb_Gain1_o = 1.0 / Z_inCL1_P.ADC_mapping * Z_inCL1_B.analogdial_o4 *
            Z_inCL1_P.VfbMax;

          /* Switch: '<S4>/Switch2' incorporates:
           *  RelationalOperator: '<S4>/LowerRelop1'
           */
          if (!(rtb_Gain > rtb_Gain3)) {
            /* Sum: '<S3>/Sum4' incorporates:
             *  Constant: '<S1>/Constant2'
             */
            rtb_Gain3 = Z_inCL1_P.Constant2_Value - rtb_Gain1_o;

            /* Switch: '<S4>/Switch' incorporates:
             *  RelationalOperator: '<S4>/UpperRelop'
             */
            if (!(rtb_Gain < rtb_Gain3)) {
              rtb_Gain3 = rtb_Gain;
            }

            /* End of Switch: '<S4>/Switch' */
          }

          /* End of Switch: '<S4>/Switch2' */

          /* MATLAB Function: '<S3>/VL2duty' incorporates:
           *  Constant: '<S1>/Constant2'
           */
          /* MATLAB Function 'ADC-PWM Subsystem/control/VL2duty': '<S5>:1' */
          /* '<S5>:1:4' */
          x_idx_1 = (rtb_Gain3 - Z_inCL1_P.Constant2_Value) / rtb_Gain1_o + 1.0;
          if (!(x_idx_1 > 0.0)) {
            x_idx_1 = 0.0;
          }

          if (!(x_idx_1 < 1.0)) {
            x_idx_1 = 1.0;
          }

          /* DataTypeConversion: '<S1>/Cast To Single2' incorporates:
           *  Gain: '<S1>/Gain1'
           *  MATLAB Function: '<S3>/VL2duty'
           */
          x_idx_1 = floor(Z_inCL1_P.TBPRD * x_idx_1);
          if (rtIsNaN(x_idx_1) || rtIsInf(x_idx_1)) {
            x_idx_1 = 0.0;
          } else {
            x_idx_1 = fmod(x_idx_1, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/ePWM3' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single2'
           */

          /*-- Update CMPA value for ePWM3 --*/
          {
            EPwm3Regs.CMPA.half.CMPA = (uint16_T)((x_idx_1 < 0.0 ? (uint16_T)
              -(int16_T)(uint16_T)-x_idx_1 : (uint16_T)x_idx_1));
          }

          /* DataTypeConversion: '<S1>/Cast To Single6' incorporates:
           *  Gain: '<S1>/Gain5'
           */
          x_idx_1 = floor(Z_inCL1_P.Gain5_Gain * rtb_Gain4);
          if (rtIsNaN(x_idx_1) || rtIsInf(x_idx_1)) {
            x_idx_1 = 0.0;
          } else {
            x_idx_1 = fmod(x_idx_1, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/pass to ePWM5' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single6'
           */

          /*-- Update CMPA value for ePWM4 --*/
          {
            EPwm4Regs.CMPA.half.CMPA = (uint16_T)((x_idx_1 < 0.0 ? (uint16_T)
              -(int16_T)(uint16_T)-x_idx_1 : (uint16_T)x_idx_1));
          }

          /* DataTypeConversion: '<S1>/Cast To Single7' incorporates:
           *  Gain: '<S1>/Gain13'
           */
          x_idx_1 = floor(Z_inCL1_P.Gain13_Gain * rtb_Gain1_o);
          if (rtIsNaN(x_idx_1) || rtIsInf(x_idx_1)) {
            x_idx_1 = 0.0;
          } else {
            x_idx_1 = fmod(x_idx_1, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/pass to ePWM6' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single7'
           */

          /*-- Update CMPA value for ePWM5 --*/
          {
            EPwm5Regs.CMPA.half.CMPA = (uint16_T)((x_idx_1 < 0.0 ? (uint16_T)
              -(int16_T)(uint16_T)-x_idx_1 : (uint16_T)x_idx_1));
          }

          /* DataTypeConversion: '<S1>/Cast To Single5' incorporates:
           *  Constant: '<S1>/Constant'
           *  Gain: '<S1>/Gain4'
           */
          x_idx_1 = floor(Z_inCL1_P.Gain4_Gain * Z_inCL1_P.Constant_Value);
          if (rtIsNaN(x_idx_1) || rtIsInf(x_idx_1)) {
            x_idx_1 = 0.0;
          } else {
            x_idx_1 = fmod(x_idx_1, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/ref observer' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single5'
           */

          /*-- Update CMPA value for ePWM1 --*/
          {
            EPwm1Regs.CMPA.half.CMPA = (uint16_T)((x_idx_1 < 0.0 ? (uint16_T)
              -(int16_T)(uint16_T)-x_idx_1 : (uint16_T)x_idx_1));
          }

          /* Update for Memory: '<S3>/Memory3' incorporates:
           *  Gain: '<S3>/Gain2'
           *  Sum: '<S3>/Sum2'
           */
          Z_inCL1_DW.Memory3_PreviousInput = (rtb_Gain - rtb_Gain3) *
            Z_inCL1_P.kaw_i;

          /* Update for DiscreteTransferFcn: '<S3>/discrete integrator' */
          Z_inCL1_DW.discreteintegrator_states = discreteintegrator_tmp;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S7>/Hardware Interrupt' */
      }
    }

    /* Clear occurred End of sequence event event */
    AdcRegs.ADCST.bit.INT_SEQ1_CLR= 1;
  }

  HWI_TIC28x_AcknowledgeIrq(32);
}

void Z_inCL1_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(32);
}
