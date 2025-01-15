/*
 * Z_CL1.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_CL1".
 *
 * Model version              : 9.38
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Fri Jan 10 19:15:09 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Z_CL1.h"
#include "Z_CL1_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_Z_CL1_T Z_CL1_B;

/* Block states (default storage) */
DW_Z_CL1_T Z_CL1_DW;

/* Real-time model */
static RT_MODEL_Z_CL1_T Z_CL1_M_;
RT_MODEL_Z_CL1_T *const Z_CL1_M = &Z_CL1_M_;
uint16_T MW_adcInitFlag = 0;

/* Model initialize function */
void Z_CL1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Z_CL1_M, (NULL));

  /* block I/O */
  {
    Z_CL1_B.analogdial_o1 = 0.0;
    Z_CL1_B.analogdial_o2 = 0.0;
    Z_CL1_B.analogdial_o3 = 0.0;
    Z_CL1_B.analogdial_o4 = 0.0;
  }

  /* states (dwork) */
  Z_CL1_DW.discreteintegrator_states = 0.0;
  Z_CL1_DW.discreteintegrator_states_l = 0.0;
  Z_CL1_DW.Memory3_PreviousInput = 0.0;
  Z_CL1_DW.Memory2_PreviousInput = 0.0;
  Z_CL1_DW.Memory3_PreviousInput_c = 0.0;

  /* Start for S-Function (HardwareInterrupt_sfun): '<S9>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC-PWM Subsystem'
   */

  /* Start for function-call system: '<Root>/ADC-PWM Subsystem' */

  /* Start for S-Function (c280xadc): '<S1>/analog dial' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_A (3U, 12816U, 0U, 0U, 0U);

  /* Start for S-Function (c280xpwm): '<S1>/Vout_emul_observer1' */

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

  /* Start for S-Function (c280xpwm): '<S1>/Vout_emul_observer2' */

  /*** Initialize ePWM2 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 7500;

    /* // Time-Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL   = 1;          // Sync output select
       EPwm2Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
       EPwm2Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
       EPwm2Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm2Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm2Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FBF) | 0x12;

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
       EPwm2Regs.DBCTL.bit.OUT_MODE   = 0;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x3F) | 0x0;
    EPwm2Regs.DBRED = 0;
    EPwm2Regs.DBFED = 0;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASEL    = 2;          // Start of conversion A Select
       EPwm2Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM2SOCA Period Select
       EPwm2Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm2Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSEL.bit.INTEN      = 0;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSEL     = 1;          // EPWM2INTn Select
       EPwm2Regs.ETPS.bit.INTPRD      = 1;          // EPWM2INTn Period Select
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0F) | 0x1201;
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
       EPwm3Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
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
       EPwm3Regs.ETSEL.bit.INTSEL     = 4;          // EPWM3INTn Select
       EPwm3Regs.ETPS.bit.INTPRD      = 1;          // EPWM3INTn Period Select
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF0F) | 0x1A04;
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

  /* End of Start for S-Function (HardwareInterrupt_sfun): '<S9>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S9>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC-PWM Subsystem'
   */

  /* System initialize for function-call system: '<Root>/ADC-PWM Subsystem' */

  /* InitializeConditions for Memory: '<S5>/Memory3' */
  Z_CL1_DW.Memory3_PreviousInput = Z_CL1_P.Memory3_InitialCondition;

  /* InitializeConditions for Memory: '<S3>/Memory2' */
  Z_CL1_DW.Memory2_PreviousInput = Z_CL1_P.Memory2_InitialCondition;

  /* InitializeConditions for Memory: '<S3>/Memory3' */
  Z_CL1_DW.Memory3_PreviousInput_c = Z_CL1_P.Memory3_InitialCondition_p;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/discrete integrator' */
  Z_CL1_DW.discreteintegrator_states = Z_CL1_P.discreteintegrator_InitialState;

  /* InitializeConditions for DiscreteTransferFcn: '<S5>/discrete integrator' */
  Z_CL1_DW.discreteintegrator_states_l = Z_CL1_P.discreteintegrator_InitialSta_j;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S9>/Hardware Interrupt' */
}

/* Model terminate function */
void Z_CL1_terminate(void)
{
  /* (no terminate code required) */
}

void Z_CL1_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(32,&SEQ1INT,0);
  HWI_TIC28x_EnableIRQ(32);
}

/* Hardware Interrupt Block: '<S9>/Hardware Interrupt' */
interrupt void SEQ1INT(void)
{
  /* Event: End of sequence event */
  /* Check event End of sequence event occurred */
  if (0 != (AdcRegs.ADCST.bit.INT_SEQ1==1)) {
    if (1 == runModel) {
      {
        /* S-Function (HardwareInterrupt_sfun): '<S9>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/ADC-PWM Subsystem' */
        {
          real_T discreteintegrator_tmp;
          real_T discreteintegrator_tmp_n;
          real_T rtb_Fcn5;
          real_T rtb_Gain12;
          real_T rtb_Gain13;
          real_T rtb_Gain3;
          real_T rtb_IL;
          real_T x_idx_1;

          /* S-Function (c280xadc): '<S1>/analog dial' */
          {
            Z_CL1_B.analogdial_o1 = (AdcRegs.ADCRESULT0) >> 4;
            Z_CL1_B.analogdial_o2 = (AdcRegs.ADCRESULT1) >> 4;
            Z_CL1_B.analogdial_o3 = (AdcRegs.ADCRESULT2) >> 4;
            Z_CL1_B.analogdial_o4 = (AdcRegs.ADCRESULT3) >> 4;
            AdcRegs.ADCTRL2.bit.RST_SEQ1 = 0x1U;/* Sequencer reset*/
          }

          /* Fcn: '<S1>/Fcn5' incorporates:
           *  Gain: '<S1>/Gain10'
           */
          rtb_Fcn5 = 1.0 / Z_CL1_P.ADC_mapping * Z_CL1_B.analogdial_o3 * 2.0 *
            10.0 - 10.0;

          /* DataTypeConversion: '<S1>/Cast To Single3' incorporates:
           *  Gain: '<S1>/Gain'
           */
          x_idx_1 = floor(Z_CL1_P.Gain_Gain * rtb_Fcn5);
          if (rtIsNaN(x_idx_1) || rtIsInf(x_idx_1)) {
            x_idx_1 = 0.0;
          } else {
            x_idx_1 = fmod(x_idx_1, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/Vout_emul_observer1' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single3'
           */

          /*-- Update CMPA value for ePWM1 --*/
          {
            EPwm1Regs.CMPA.half.CMPA = (uint16_T)((x_idx_1 < 0.0 ? (uint16_T)
              -(int16_T)(uint16_T)-x_idx_1 : (uint16_T)x_idx_1));
          }

          /* Gain: '<S1>/Gain12' incorporates:
           *  Gain: '<S1>/Gain11'
           */
          rtb_Gain12 = 1.0 / Z_CL1_P.ADC_mapping * Z_CL1_B.analogdial_o4 *
            Z_CL1_P.VfbMax;

          /* DataTypeConversion: '<S1>/Cast To Single4' incorporates:
           *  Gain: '<S1>/Gain4'
           */
          x_idx_1 = floor(Z_CL1_P.Gain4_Gain * rtb_Gain12);
          if (rtIsNaN(x_idx_1) || rtIsInf(x_idx_1)) {
            x_idx_1 = 0.0;
          } else {
            x_idx_1 = fmod(x_idx_1, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/Vout_emul_observer2' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single4'
           */

          /*-- Update CMPA value for ePWM2 --*/
          {
            EPwm2Regs.CMPA.half.CMPA = (uint16_T)((x_idx_1 < 0.0 ? (uint16_T)
              -(int16_T)(uint16_T)-x_idx_1 : (uint16_T)x_idx_1));
          }

          /* Gain: '<S5>/Gain3' incorporates:
           *  Constant: '<S3>/Constant1'
           */
          rtb_Gain3 = Z_CL1_P.VLlim * Z_CL1_P.VinNom;

          /* DiscreteTransferFcn: '<S3>/discrete integrator' incorporates:
           *  Constant: '<S1>/Constant5'
           *  Gain: '<S3>/Gain13'
           *  Memory: '<S3>/Memory3'
           *  Sum: '<S3>/Sum14'
           *  Sum: '<S3>/Sum8'
           */
          discreteintegrator_tmp = (((Z_CL1_P.VoutNom - rtb_Gain12) -
            Z_CL1_DW.Memory3_PreviousInput_c) * Z_CL1_P.ki_v -
            Z_CL1_P.zden_Integrator[1L] * Z_CL1_DW.discreteintegrator_states) /
            Z_CL1_P.zden_Integrator[0];

          /* Sum: '<S3>/Sum9' incorporates:
           *  DiscreteTransferFcn: '<S3>/discrete integrator'
           *  Gain: '<S3>/Gain15'
           */
          rtb_Gain13 = (Z_CL1_P.znum_Integrator[0] * discreteintegrator_tmp +
                        Z_CL1_P.znum_Integrator[1L] *
                        Z_CL1_DW.discreteintegrator_states) - Z_CL1_P.kp_v *
            rtb_Gain12;

          /* MATLAB Function: '<S3>/Iout2IL2' incorporates:
           *  Constant: '<S1>/Constant5'
           *  Constant: '<S3>/Constant3'
           *  Memory: '<S3>/Memory2'
           */
          Z_CL1_B.VoutRef = Z_CL1_P.VoutNom;

          /* MATLAB Function 'ADC-PWM Subsystem/control/Iout2IL2': '<S4>:1' */
          if (Z_CL1_P.VoutNom < Z_CL1_P.VinNom) {
            /* '<S4>:1:3' */
            /* '<S4>:1:4' */
            Z_CL1_B.VoutRef = Z_CL1_P.VinNom;
          }

          /* '<S4>:1:6' */
          Z_CL1_B.VoutRef = (Z_CL1_P.VinNom - Z_CL1_P.RserL *
                             Z_CL1_DW.Memory2_PreviousInput) / Z_CL1_B.VoutRef;

          /* '<S4>:1:7' */
          rtb_IL = rtb_Gain13 / Z_CL1_B.VoutRef;

          /* Saturate: '<S3>/Saturation2' */
          if (rtb_IL > Z_CL1_P.ILmax) {
            rtb_IL = Z_CL1_P.ILmax;
          } else if (rtb_IL < -Z_CL1_P.ILmax) {
            rtb_IL = -Z_CL1_P.ILmax;
          }

          /* End of Saturate: '<S3>/Saturation2' */

          /* DiscreteTransferFcn: '<S5>/discrete integrator' incorporates:
           *  Gain: '<S5>/Gain'
           *  Memory: '<S5>/Memory3'
           *  Sum: '<S5>/Sum'
           *  Sum: '<S5>/Sum3'
           */
          discreteintegrator_tmp_n = (((rtb_IL - rtb_Fcn5) -
            Z_CL1_DW.Memory3_PreviousInput) * Z_CL1_P.ki_i -
            Z_CL1_P.zden_Integrator[1L] * Z_CL1_DW.discreteintegrator_states_l) /
            Z_CL1_P.zden_Integrator[0];

          /* Sum: '<S5>/Sum1' incorporates:
           *  DiscreteTransferFcn: '<S5>/discrete integrator'
           *  Gain: '<S5>/Gain1'
           */
          rtb_Fcn5 = (Z_CL1_P.znum_Integrator[0] * discreteintegrator_tmp_n +
                      Z_CL1_P.znum_Integrator[1L] *
                      Z_CL1_DW.discreteintegrator_states_l) - Z_CL1_P.kp_i *
            rtb_Fcn5;

          /* Switch: '<S6>/Switch2' incorporates:
           *  RelationalOperator: '<S6>/LowerRelop1'
           */
          if (!(rtb_Fcn5 > rtb_Gain3)) {
            /* Sum: '<S5>/Sum4' incorporates:
             *  Constant: '<S3>/Constant1'
             */
            rtb_Gain3 = Z_CL1_P.VinNom - rtb_Gain12;

            /* Switch: '<S6>/Switch' incorporates:
             *  RelationalOperator: '<S6>/UpperRelop'
             */
            if (!(rtb_Fcn5 < rtb_Gain3)) {
              rtb_Gain3 = rtb_Fcn5;
            }

            /* End of Switch: '<S6>/Switch' */
          }

          /* End of Switch: '<S6>/Switch2' */

          /* MATLAB Function: '<S5>/VL2duty' incorporates:
           *  Constant: '<S3>/Constant1'
           */
          /* MATLAB Function 'ADC-PWM Subsystem/control/innerLoop_currentControl7/VL2duty': '<S7>:1' */
          /* '<S7>:1:4' */
          x_idx_1 = (rtb_Gain3 - Z_CL1_P.VinNom) / rtb_Gain12 + 1.0;
          if (!(x_idx_1 > 0.0)) {
            x_idx_1 = 0.0;
          }

          if (!(x_idx_1 < 1.0)) {
            x_idx_1 = 1.0;
          }

          /* DataTypeConversion: '<S1>/Cast To Single2' incorporates:
           *  Gain: '<S1>/Gain1'
           *  MATLAB Function: '<S5>/VL2duty'
           */
          x_idx_1 = floor(Z_CL1_P.TBPRD * x_idx_1);
          if (rtIsNaN(x_idx_1) || rtIsInf(x_idx_1)) {
            x_idx_1 = 0.0;
          } else {
            x_idx_1 = fmod(x_idx_1, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/ePWM1' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single2'
           */

          /*-- Update CMPA value for ePWM3 --*/
          {
            EPwm3Regs.CMPA.half.CMPA = (uint16_T)((x_idx_1 < 0.0 ? (uint16_T)
              -(int16_T)(uint16_T)-x_idx_1 : (uint16_T)x_idx_1));
          }

          /* Update for Memory: '<S5>/Memory3' incorporates:
           *  Gain: '<S5>/Gain2'
           *  Sum: '<S5>/Sum2'
           */
          Z_CL1_DW.Memory3_PreviousInput = (rtb_Fcn5 - rtb_Gain3) *
            Z_CL1_P.kaw_i;

          /* Update for Memory: '<S3>/Memory2' */
          Z_CL1_DW.Memory2_PreviousInput = rtb_IL;

          /* Update for Memory: '<S3>/Memory3' incorporates:
           *  Gain: '<S3>/Gain8'
           *  MATLAB Function: '<S3>/Iout2IL2'
           *  Product: '<S3>/Product2'
           *  Sum: '<S3>/Sum13'
           */
          Z_CL1_DW.Memory3_PreviousInput_c = (rtb_Gain13 - rtb_IL *
            Z_CL1_B.VoutRef) * Z_CL1_P.kaw_v;

          /* Update for DiscreteTransferFcn: '<S3>/discrete integrator' */
          Z_CL1_DW.discreteintegrator_states = discreteintegrator_tmp;

          /* Update for DiscreteTransferFcn: '<S5>/discrete integrator' */
          Z_CL1_DW.discreteintegrator_states_l = discreteintegrator_tmp_n;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S9>/Hardware Interrupt' */
      }
    }

    /* Clear occurred End of sequence event event */
    AdcRegs.ADCST.bit.INT_SEQ1_CLR= 1;
  }

  HWI_TIC28x_AcknowledgeIrq(32);
}

void Z_CL1_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(32);
}
