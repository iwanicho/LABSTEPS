/*
 * Z_CL3.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_CL3".
 *
 * Model version              : 9.82
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Wed Jan  8 18:16:51 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Z_CL3.h"
#include "rtwtypes.h"
#include "Z_CL3_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Z_CL3_T Z_CL3_B;

/* Block states (default storage) */
DW_Z_CL3_T Z_CL3_DW;

/* Real-time model */
static RT_MODEL_Z_CL3_T Z_CL3_M_;
RT_MODEL_Z_CL3_T *const Z_CL3_M = &Z_CL3_M_;
uint16_T MW_adcInitFlag = 0;

/*
 * Output and update for atomic system:
 *    '<S5>/VL2duty'
 *    '<S6>/VL2duty'
 *    '<S7>/VL2duty'
 */
void Z_CL3_VL2duty(real_T rtu_VLref, real_T rtu_Vin_fb, real_T rtu_Vout_fb,
                   B_VL2duty_Z_CL3_T *localB)
{
  real_T x_idx_1;

  /* MATLAB Function 'ADC-PWM Subsystem/control/innerLoop_currentControl7/VL2duty': '<S9>:1' */
  /* '<S9>:1:4' */
  x_idx_1 = (rtu_VLref - rtu_Vin_fb) / rtu_Vout_fb + 1.0;
  if (!(x_idx_1 > 0.0)) {
    x_idx_1 = 0.0;
  }

  if (x_idx_1 < 1.0) {
    localB->D = x_idx_1;
  } else {
    localB->D = 1.0;
  }
}

/* Model initialize function */
void Z_CL3_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Z_CL3_M, (NULL));

  /* block I/O */
  {
    Z_CL3_B.analogdial_o1 = 0.0;
    Z_CL3_B.analogdial_o2 = 0.0;
    Z_CL3_B.analogdial_o3 = 0.0;
    Z_CL3_B.analogdial_o4 = 0.0;
    Z_CL3_B.analogdial_o5 = 0.0;
    Z_CL3_B.analogdial_o6 = 0.0;
    Z_CL3_B.sf_VL2duty_j.D = 0.0;
    Z_CL3_B.sf_VL2duty_h.D = 0.0;
    Z_CL3_B.sf_VL2duty.D = 0.0;
  }

  /* states (dwork) */
  Z_CL3_DW.discreteintegrator_states = 0.0;
  Z_CL3_DW.discreteintegrator_states_l = 0.0;
  Z_CL3_DW.discreteintegrator_states_a = 0.0;
  Z_CL3_DW.discreteintegrator_states_c = 0.0;
  Z_CL3_DW.Memory_PreviousInput = 0.0;
  Z_CL3_DW.Memory2_PreviousInput = 0.0;
  Z_CL3_DW.Memory_PreviousInput_g = 0.0;
  Z_CL3_DW.Memory_PreviousInput_m = 0.0;
  Z_CL3_DW.Memory_PreviousInput_p = 0.0;

  /* Start for S-Function (HardwareInterrupt_sfun): '<S15>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC-PWM Subsystem'
   */

  /* Start for function-call system: '<Root>/ADC-PWM Subsystem' */

  /* Start for S-Function (c280xadc): '<S1>/analog dial' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_A (5U, 12816U, 84U, 0U, 0U);

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

  /* End of Start for S-Function (HardwareInterrupt_sfun): '<S15>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S15>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC-PWM Subsystem'
   */

  /* System initialize for function-call system: '<Root>/ADC-PWM Subsystem' */

  /* InitializeConditions for Memory: '<S6>/Memory' */
  Z_CL3_DW.Memory_PreviousInput = Z_CL3_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<S3>/Memory2' */
  Z_CL3_DW.Memory2_PreviousInput = Z_CL3_P.Memory2_InitialCondition;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  Z_CL3_DW.Memory_PreviousInput_g = Z_CL3_P.Memory_InitialCondition_f;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/discrete integrator' */
  Z_CL3_DW.discreteintegrator_states = Z_CL3_P.discreteintegrator_InitialState;

  /* InitializeConditions for DiscreteTransferFcn: '<S6>/discrete integrator' */
  Z_CL3_DW.discreteintegrator_states_l = Z_CL3_P.discreteintegrator_InitialSta_e;

  /* InitializeConditions for Memory: '<S5>/Memory' */
  Z_CL3_DW.Memory_PreviousInput_m = Z_CL3_P.Memory_InitialCondition_l;

  /* InitializeConditions for DiscreteTransferFcn: '<S5>/discrete integrator' */
  Z_CL3_DW.discreteintegrator_states_a = Z_CL3_P.discreteintegrator_InitialSta_m;

  /* InitializeConditions for Memory: '<S7>/Memory' */
  Z_CL3_DW.Memory_PreviousInput_p = Z_CL3_P.Memory_InitialCondition_i;

  /* InitializeConditions for DiscreteTransferFcn: '<S7>/discrete integrator' */
  Z_CL3_DW.discreteintegrator_states_c = Z_CL3_P.discreteintegrator_InitialSt_me;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S15>/Hardware Interrupt' */
}

/* Model terminate function */
void Z_CL3_terminate(void)
{
  /* (no terminate code required) */
}

void Z_CL3_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(32,&SEQ1INT,0);
  HWI_TIC28x_EnableIRQ(32);
}

/* Hardware Interrupt Block: '<S15>/Hardware Interrupt' */
interrupt void SEQ1INT(void)
{
  /* Event: End of sequence event */
  /* Check event End of sequence event occurred */
  if (0 != (AdcRegs.ADCST.bit.INT_SEQ1==1)) {
    if (1 == runModel) {
      {
        /* S-Function (HardwareInterrupt_sfun): '<S15>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/ADC-PWM Subsystem' */
        {
          real_T discreteintegrator_tmp;
          real_T discreteintegrator_tmp_f;
          real_T discreteintegrator_tmp_k;
          real_T discreteintegrator_tmp_m;
          real_T rtb_Gain_p;
          real_T rtb_IL3fb_tmp;
          real_T rtb_Switch2;

          /* Gain: '<S6>/Gain3' incorporates:
           *  Constant: '<S3>/Constant2'
           *  Gain: '<S5>/Gain3'
           *  Gain: '<S7>/Gain3'
           */
          rtb_IL3fb_tmp = Z_CL3_P.VLlim * Z_CL3_P.VinNom;

          /* S-Function (c280xadc): '<S1>/analog dial' */
          {
            Z_CL3_B.analogdial_o1 = (AdcRegs.ADCRESULT0) >> 4;
            Z_CL3_B.analogdial_o2 = (AdcRegs.ADCRESULT1) >> 4;
            Z_CL3_B.analogdial_o3 = (AdcRegs.ADCRESULT2) >> 4;
            Z_CL3_B.analogdial_o4 = (AdcRegs.ADCRESULT3) >> 4;
            Z_CL3_B.analogdial_o5 = (AdcRegs.ADCRESULT4) >> 4;
            Z_CL3_B.analogdial_o6 = (AdcRegs.ADCRESULT5) >> 4;
            AdcRegs.ADCTRL2.bit.RST_SEQ1 = 0x1U;/* Sequencer reset*/
          }

          /* Gain: '<S1>/Gain12' incorporates:
           *  Gain: '<S1>/Gain9'
           */
          Z_CL3_B.Vfb = 1.0 / Z_CL3_P.ADC_mapping * Z_CL3_B.analogdial_o4 *
            Z_CL3_P.VfbMax;

          /* DiscreteTransferFcn: '<S3>/discrete integrator' incorporates:
           *  Constant: '<S1>/Constant5'
           *  Gain: '<S3>/Gain13'
           *  Memory: '<S3>/Memory'
           *  Sum: '<S3>/Sum14'
           *  Sum: '<S3>/Sum8'
           */
          discreteintegrator_tmp = (((Z_CL3_P.VoutNom - Z_CL3_B.Vfb) -
            Z_CL3_DW.Memory_PreviousInput_g) * Z_CL3_P.ki_v -
            Z_CL3_P.zden_Integrator[1L] * Z_CL3_DW.discreteintegrator_states) /
            Z_CL3_P.zden_Integrator[0];

          /* Sum: '<S3>/Sum9' incorporates:
           *  DiscreteTransferFcn: '<S3>/discrete integrator'
           *  Gain: '<S3>/Gain15'
           */
          Z_CL3_B.Gain13 = (Z_CL3_P.znum_Integrator[0] * discreteintegrator_tmp
                            + Z_CL3_P.znum_Integrator[1L] *
                            Z_CL3_DW.discreteintegrator_states) - Z_CL3_P.kp_v *
            Z_CL3_B.Vfb;

          /* MATLAB Function: '<S3>/Iout2IL2' incorporates:
           *  Constant: '<S1>/Constant5'
           *  Constant: '<S3>/Constant3'
           *  Memory: '<S3>/Memory2'
           */
          Z_CL3_B.VoutRef = Z_CL3_P.VoutNom;

          /* MATLAB Function 'ADC-PWM Subsystem/control/Iout2IL2': '<S4>:1' */
          if (Z_CL3_P.VoutNom < Z_CL3_P.VinNom) {
            /* '<S4>:1:3' */
            /* '<S4>:1:4' */
            Z_CL3_B.VoutRef = Z_CL3_P.VinNom;
          }

          /* '<S4>:1:6' */
          Z_CL3_B.VoutRef = (Z_CL3_P.VinNom - Z_CL3_P.RserL *
                             Z_CL3_DW.Memory2_PreviousInput) / Z_CL3_B.VoutRef;

          /* '<S4>:1:7' */
          Z_CL3_B.IL = Z_CL3_B.Gain13 / Z_CL3_B.VoutRef;

          /* Saturate: '<S3>/Saturation2' */
          if (Z_CL3_B.IL > Z_CL3_P.ILmax) {
            Z_CL3_B.IL = Z_CL3_P.ILmax;
          } else if (Z_CL3_B.IL < -Z_CL3_P.ILmax) {
            Z_CL3_B.IL = -Z_CL3_P.ILmax;
          }

          /* End of Saturate: '<S3>/Saturation2' */

          /* Gain: '<S3>/Gain6' */
          Z_CL3_B.discreteintegrator = Z_CL3_P.Gain6_Gain * Z_CL3_B.IL;

          /* Fcn: '<S1>/Fcn6' incorporates:
           *  Gain: '<S1>/Gain10'
           */
          Z_CL3_B.Gain7 = 1.0 / Z_CL3_P.ADC_mapping * Z_CL3_B.analogdial_o5 *
            2.0 * 10.0 - 10.0;

          /* DiscreteTransferFcn: '<S6>/discrete integrator' incorporates:
           *  Gain: '<S6>/Gain'
           *  Memory: '<S6>/Memory'
           *  Sum: '<S6>/Sum'
           *  Sum: '<S6>/Sum3'
           */
          discreteintegrator_tmp_m = (((Z_CL3_B.discreteintegrator -
            Z_CL3_B.Gain7) - Z_CL3_DW.Memory_PreviousInput) * Z_CL3_P.ki_i -
            Z_CL3_P.zden_Integrator[1L] * Z_CL3_DW.discreteintegrator_states_l) /
            Z_CL3_P.zden_Integrator[0];

          /* Sum: '<S6>/Sum1' incorporates:
           *  DiscreteTransferFcn: '<S6>/discrete integrator'
           *  Gain: '<S6>/Gain1'
           */
          Z_CL3_B.Gain = (Z_CL3_P.znum_Integrator[0] * discreteintegrator_tmp_m
                          + Z_CL3_P.znum_Integrator[1L] *
                          Z_CL3_DW.discreteintegrator_states_l) - Z_CL3_P.kp_i *
            Z_CL3_B.Gain7;

          /* Switch: '<S10>/Switch2' incorporates:
           *  Gain: '<S6>/Gain3'
           *  RelationalOperator: '<S10>/LowerRelop1'
           */
          if (Z_CL3_B.Gain > rtb_IL3fb_tmp) {
            rtb_Switch2 = rtb_IL3fb_tmp;
          } else {
            /* Sum: '<S6>/Sum4' incorporates:
             *  Constant: '<S3>/Constant2'
             */
            Z_CL3_B.IL3fb = Z_CL3_P.VinNom - Z_CL3_B.Vfb;

            /* Switch: '<S10>/Switch' incorporates:
             *  RelationalOperator: '<S10>/UpperRelop'
             */
            if (Z_CL3_B.Gain < Z_CL3_B.IL3fb) {
              rtb_Switch2 = Z_CL3_B.IL3fb;
            } else {
              rtb_Switch2 = Z_CL3_B.Gain;
            }

            /* End of Switch: '<S10>/Switch' */
          }

          /* End of Switch: '<S10>/Switch2' */

          /* MATLAB Function: '<S6>/VL2duty' incorporates:
           *  Constant: '<S3>/Constant2'
           */
          Z_CL3_VL2duty(rtb_Switch2, Z_CL3_P.VinNom, Z_CL3_B.Vfb,
                        &Z_CL3_B.sf_VL2duty_h);

          /* DataTypeConversion: '<S1>/Cast To Single2' incorporates:
           *  Gain: '<S1>/Gain1'
           */
          Z_CL3_B.IL3fb = floor(Z_CL3_P.TBPRD * Z_CL3_B.sf_VL2duty_h.D);
          if (rtIsNaN(Z_CL3_B.IL3fb) || rtIsInf(Z_CL3_B.IL3fb)) {
            Z_CL3_B.IL3fb = 0.0;
          } else {
            Z_CL3_B.IL3fb = fmod(Z_CL3_B.IL3fb, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/ePWM' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single2'
           */

          /*-- Update CMPA value for ePWM2 --*/
          {
            EPwm2Regs.CMPA.half.CMPA = (uint16_T)((Z_CL3_B.IL3fb < 0.0 ?
              (uint16_T)-(int16_T)(uint16_T)-Z_CL3_B.IL3fb : (uint16_T)
              Z_CL3_B.IL3fb));
          }

          /* Fcn: '<S1>/Fcn5' incorporates:
           *  Gain: '<S1>/Gain8'
           */
          Z_CL3_B.IL3fb = 1.0 / Z_CL3_P.ADC_mapping * Z_CL3_B.analogdial_o3 *
            2.0 * 10.0 - 10.0;

          /* DiscreteTransferFcn: '<S5>/discrete integrator' incorporates:
           *  Gain: '<S5>/Gain'
           *  Memory: '<S5>/Memory'
           *  Sum: '<S5>/Sum'
           *  Sum: '<S5>/Sum3'
           */
          discreteintegrator_tmp_f = (((Z_CL3_B.discreteintegrator -
            Z_CL3_B.IL3fb) - Z_CL3_DW.Memory_PreviousInput_m) * Z_CL3_P.ki_i -
            Z_CL3_P.zden_Integrator[1L] * Z_CL3_DW.discreteintegrator_states_a) /
            Z_CL3_P.zden_Integrator[0];

          /* Sum: '<S5>/Sum1' incorporates:
           *  DiscreteTransferFcn: '<S5>/discrete integrator'
           *  Gain: '<S5>/Gain1'
           */
          Z_CL3_B.Memory = (Z_CL3_P.znum_Integrator[0] *
                            discreteintegrator_tmp_f + Z_CL3_P.znum_Integrator
                            [1L] * Z_CL3_DW.discreteintegrator_states_a) -
            Z_CL3_P.kp_i * Z_CL3_B.IL3fb;

          /* Switch: '<S8>/Switch2' incorporates:
           *  RelationalOperator: '<S8>/LowerRelop1'
           */
          if (Z_CL3_B.Memory > rtb_IL3fb_tmp) {
            rtb_Gain_p = rtb_IL3fb_tmp;
          } else {
            /* Sum: '<S5>/Sum4' incorporates:
             *  Constant: '<S3>/Constant1'
             */
            Z_CL3_B.IL3fb = Z_CL3_P.VinNom - Z_CL3_B.Vfb;

            /* Switch: '<S8>/Switch' incorporates:
             *  RelationalOperator: '<S8>/UpperRelop'
             */
            if (Z_CL3_B.Memory < Z_CL3_B.IL3fb) {
              rtb_Gain_p = Z_CL3_B.IL3fb;
            } else {
              rtb_Gain_p = Z_CL3_B.Memory;
            }

            /* End of Switch: '<S8>/Switch' */
          }

          /* End of Switch: '<S8>/Switch2' */

          /* MATLAB Function: '<S5>/VL2duty' incorporates:
           *  Constant: '<S3>/Constant1'
           */
          Z_CL3_VL2duty(rtb_Gain_p, Z_CL3_P.VinNom, Z_CL3_B.Vfb,
                        &Z_CL3_B.sf_VL2duty);

          /* DataTypeConversion: '<S1>/Cast To Single3' incorporates:
           *  Gain: '<S1>/Gain6'
           */
          Z_CL3_B.IL3fb = floor(Z_CL3_P.TBPRD * Z_CL3_B.sf_VL2duty.D);
          if (rtIsNaN(Z_CL3_B.IL3fb) || rtIsInf(Z_CL3_B.IL3fb)) {
            Z_CL3_B.IL3fb = 0.0;
          } else {
            Z_CL3_B.IL3fb = fmod(Z_CL3_B.IL3fb, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/ePWM1' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single3'
           */

          /*-- Update CMPA value for ePWM3 --*/
          {
            EPwm3Regs.CMPA.half.CMPA = (uint16_T)((Z_CL3_B.IL3fb < 0.0 ?
              (uint16_T)-(int16_T)(uint16_T)-Z_CL3_B.IL3fb : (uint16_T)
              Z_CL3_B.IL3fb));
          }

          /* Gain: '<S7>/Gain3' */
          Z_CL3_B.Gain7 = rtb_IL3fb_tmp;

          /* Fcn: '<S1>/Fcn7' incorporates:
           *  Gain: '<S1>/Gain11'
           */
          Z_CL3_B.IL3fb = 1.0 / Z_CL3_P.ADC_mapping * Z_CL3_B.analogdial_o6 *
            2.0 * 10.0 - 10.0;

          /* DiscreteTransferFcn: '<S7>/discrete integrator' incorporates:
           *  Gain: '<S7>/Gain'
           *  Memory: '<S7>/Memory'
           *  Sum: '<S7>/Sum'
           *  Sum: '<S7>/Sum3'
           */
          discreteintegrator_tmp_k = (((Z_CL3_B.discreteintegrator -
            Z_CL3_B.IL3fb) - Z_CL3_DW.Memory_PreviousInput_p) * Z_CL3_P.ki_i -
            Z_CL3_P.zden_Integrator[1L] * Z_CL3_DW.discreteintegrator_states_c) /
            Z_CL3_P.zden_Integrator[0];

          /* Sum: '<S7>/Sum1' incorporates:
           *  DiscreteTransferFcn: '<S7>/discrete integrator'
           *  Gain: '<S7>/Gain1'
           */
          Z_CL3_B.discreteintegrator = (Z_CL3_P.znum_Integrator[0] *
            discreteintegrator_tmp_k + Z_CL3_P.znum_Integrator[1L] *
            Z_CL3_DW.discreteintegrator_states_c) - Z_CL3_P.kp_i * Z_CL3_B.IL3fb;

          /* Switch: '<S12>/Switch2' incorporates:
           *  RelationalOperator: '<S12>/LowerRelop1'
           */
          if (!(Z_CL3_B.discreteintegrator > rtb_IL3fb_tmp)) {
            /* Sum: '<S7>/Sum4' incorporates:
             *  Constant: '<S3>/Constant4'
             */
            Z_CL3_B.IL3fb = Z_CL3_P.VinNom - Z_CL3_B.Vfb;

            /* Switch: '<S12>/Switch' incorporates:
             *  RelationalOperator: '<S12>/UpperRelop'
             */
            if (Z_CL3_B.discreteintegrator < Z_CL3_B.IL3fb) {
              Z_CL3_B.Gain7 = Z_CL3_B.IL3fb;
            } else {
              Z_CL3_B.Gain7 = Z_CL3_B.discreteintegrator;
            }

            /* End of Switch: '<S12>/Switch' */
          }

          /* End of Switch: '<S12>/Switch2' */

          /* MATLAB Function: '<S7>/VL2duty' incorporates:
           *  Constant: '<S3>/Constant4'
           */
          Z_CL3_VL2duty(Z_CL3_B.Gain7, Z_CL3_P.VinNom, Z_CL3_B.Vfb,
                        &Z_CL3_B.sf_VL2duty_j);

          /* DataTypeConversion: '<S1>/Cast To Single4' incorporates:
           *  Gain: '<S1>/Gain7'
           */
          Z_CL3_B.IL3fb = floor(Z_CL3_P.TBPRD * Z_CL3_B.sf_VL2duty_j.D);
          if (rtIsNaN(Z_CL3_B.IL3fb) || rtIsInf(Z_CL3_B.IL3fb)) {
            Z_CL3_B.IL3fb = 0.0;
          } else {
            Z_CL3_B.IL3fb = fmod(Z_CL3_B.IL3fb, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/ePWM2' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single4'
           */

          /*-- Update CMPA value for ePWM6 --*/
          {
            EPwm6Regs.CMPA.half.CMPA = (uint16_T)((Z_CL3_B.IL3fb < 0.0 ?
              (uint16_T)-(int16_T)(uint16_T)-Z_CL3_B.IL3fb : (uint16_T)
              Z_CL3_B.IL3fb));
          }

          /* Update for Memory: '<S6>/Memory' incorporates:
           *  Gain: '<S6>/Gain2'
           *  Sum: '<S6>/Sum2'
           */
          Z_CL3_DW.Memory_PreviousInput = (Z_CL3_B.Gain - rtb_Switch2) *
            Z_CL3_P.kaw_i;

          /* Update for Memory: '<S3>/Memory2' */
          Z_CL3_DW.Memory2_PreviousInput = Z_CL3_B.IL;

          /* Update for Memory: '<S3>/Memory' incorporates:
           *  Gain: '<S3>/Gain8'
           *  MATLAB Function: '<S3>/Iout2IL2'
           *  Product: '<S3>/Product2'
           *  Sum: '<S3>/Sum13'
           */
          Z_CL3_DW.Memory_PreviousInput_g = (Z_CL3_B.Gain13 - Z_CL3_B.IL *
            Z_CL3_B.VoutRef) * Z_CL3_P.kaw_v;

          /* Update for DiscreteTransferFcn: '<S3>/discrete integrator' */
          Z_CL3_DW.discreteintegrator_states = discreteintegrator_tmp;

          /* Update for DiscreteTransferFcn: '<S6>/discrete integrator' */
          Z_CL3_DW.discreteintegrator_states_l = discreteintegrator_tmp_m;

          /* Update for Memory: '<S5>/Memory' incorporates:
           *  Gain: '<S5>/Gain2'
           *  Sum: '<S5>/Sum2'
           */
          Z_CL3_DW.Memory_PreviousInput_m = (Z_CL3_B.Memory - rtb_Gain_p) *
            Z_CL3_P.kaw_i;

          /* Update for DiscreteTransferFcn: '<S5>/discrete integrator' */
          Z_CL3_DW.discreteintegrator_states_a = discreteintegrator_tmp_f;

          /* Update for Memory: '<S7>/Memory' incorporates:
           *  Gain: '<S7>/Gain2'
           *  Sum: '<S7>/Sum2'
           */
          Z_CL3_DW.Memory_PreviousInput_p = (Z_CL3_B.discreteintegrator -
            Z_CL3_B.Gain7) * Z_CL3_P.kaw_i;

          /* Update for DiscreteTransferFcn: '<S7>/discrete integrator' */
          Z_CL3_DW.discreteintegrator_states_c = discreteintegrator_tmp_k;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S15>/Hardware Interrupt' */
      }
    }

    /* Clear occurred End of sequence event event */
    AdcRegs.ADCST.bit.INT_SEQ1_CLR= 1;
  }

  HWI_TIC28x_AcknowledgeIrq(32);
}

void Z_CL3_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(32);
}
