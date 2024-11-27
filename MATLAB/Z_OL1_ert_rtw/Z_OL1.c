/*
 * Z_OL1.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_OL1".
 *
 * Model version              : 9.23
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Wed Nov 27 12:19:35 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Z_OL1.h"
#include "Z_OL1_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_Z_OL1_T Z_OL1_B;

/* Block states (default storage) */
DW_Z_OL1_T Z_OL1_DW;

/* Real-time model */
static RT_MODEL_Z_OL1_T Z_OL1_M_;
RT_MODEL_Z_OL1_T *const Z_OL1_M = &Z_OL1_M_;
uint16_T MW_adcInitFlag = 0;

/* Model initialize function */
void Z_OL1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Z_OL1_M, (NULL));

  /* block I/O */
  {
    Z_OL1_B.ADC_o1 = 0.0;
    Z_OL1_B.ADC_o2 = 0.0;
  }

  /* states (dwork) */
  Z_OL1_DW.InductorTF1_states = 0.0;
  Z_OL1_DW.CapacitorTF_states = 0.0;
  Z_OL1_DW.Memory3_PreviousInput = 0.0;
  Z_OL1_DW.Memory1_PreviousInput = 0.0;

  /* Start for S-Function (HardwareInterrupt_sfun): '<S8>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC-PWM Subsystem'
   */

  /* Start for function-call system: '<Root>/ADC-PWM Subsystem' */

  /* Start for S-Function (c280xpwm): '<S1>/Vout_emul_observer' */

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

  /* End of Start for S-Function (HardwareInterrupt_sfun): '<S8>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S8>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC-PWM Subsystem'
   */

  /* System initialize for function-call system: '<Root>/ADC-PWM Subsystem' */

  /* InitializeConditions for Memory: '<S4>/Memory3' */
  Z_OL1_DW.Memory3_PreviousInput = Z_OL1_P.Memory3_InitialCondition;

  /* InitializeConditions for DiscreteTransferFcn: '<S4>/Inductor TF1' */
  Z_OL1_DW.InductorTF1_states = Z_OL1_P.InductorTF1_InitialStates;

  /* InitializeConditions for Memory: '<S4>/Memory1' */
  Z_OL1_DW.Memory1_PreviousInput = Z_OL1_P.Memory1_InitialCondition;

  /* InitializeConditions for DiscreteTransferFcn: '<S4>/Capacitor TF' */
  Z_OL1_DW.CapacitorTF_states = Z_OL1_P.CapacitorTF_InitialStates;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S8>/Hardware Interrupt' */
}

/* Model terminate function */
void Z_OL1_terminate(void)
{
  /* (no terminate code required) */
}

void Z_OL1_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(32,&SEQ1INT,0);
  HWI_TIC28x_EnableIRQ(32);
}

/* Hardware Interrupt Block: '<S8>/Hardware Interrupt' */
interrupt void SEQ1INT(void)
{
  /* Event: End of sequence event */
  /* Check event End of sequence event occurred */
  if (0 != (AdcRegs.ADCST.bit.INT_SEQ1==1)) {
    if (1 == runModel) {
      {
        /* S-Function (HardwareInterrupt_sfun): '<S8>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/ADC-PWM Subsystem' */
        {
          real_T CapacitorTF_tmp;
          real_T InductorTF1;
          real_T InductorTF1_tmp;
          real_T rtb_CapacitorTF;
          real_T u0;

          /* DiscreteTransferFcn: '<S4>/Inductor TF1' */
          InductorTF1 = Z_OL1_P.znum_plant_i[1L] * Z_OL1_DW.InductorTF1_states;

          /* MATLAB Function: '<S4>/IL2Iout' incorporates:
           *  Constant: '<S4>/Constant'
           *  Memory: '<S4>/Memory3'
           */
          CapacitorTF_tmp = Z_OL1_DW.Memory3_PreviousInput;

          /* MATLAB Function 'ADC-PWM Subsystem/emulated_plant/IL2Iout': '<S5>:1' */
          if (Z_OL1_DW.Memory3_PreviousInput < Z_OL1_P.VinNom) {
            /* '<S5>:1:3' */
            /* '<S5>:1:4' */
            CapacitorTF_tmp = Z_OL1_P.VinNom;
          }

          /* DiscreteTransferFcn: '<S4>/Capacitor TF' incorporates:
           *  Constant: '<S4>/Constant'
           *  MATLAB Function: '<S4>/IL2Iout'
           *  Memory: '<S4>/Memory1'
           *  Sum: '<S4>/Sum'
           */
          /* '<S5>:1:6' */
          /* '<S5>:1:7' */
          CapacitorTF_tmp = (((Z_OL1_P.VinNom - Z_OL1_P.RserL * InductorTF1) /
                              CapacitorTF_tmp * InductorTF1 -
                              Z_OL1_DW.Memory1_PreviousInput) -
                             Z_OL1_P.zden_plant_v[1L] *
                             Z_OL1_DW.CapacitorTF_states) /
            Z_OL1_P.zden_plant_v[0];
          rtb_CapacitorTF = Z_OL1_P.znum_plant_v[0] * CapacitorTF_tmp +
            Z_OL1_P.znum_plant_v[1L] * Z_OL1_DW.CapacitorTF_states;

          /* Gain: '<S1>/Gain5' incorporates:
           *  Gain: '<S1>/Gain'
           */
          InductorTF1 = Z_OL1_P.VoutMax - Z_OL1_P.VinNom;

          /* Gain: '<S1>/Gain6' incorporates:
           *  Constant: '<S1>/Constant3'
           *  Gain: '<S1>/Gain5'
           *  Sum: '<S1>/Sum2'
           */
          u0 = 1.0 / InductorTF1 * (rtb_CapacitorTF - Z_OL1_P.VinNom) *
            Z_OL1_P.ADC_mapping;

          /* Saturate: '<S1>/Saturation' */
          if (u0 > Z_OL1_P.ADC_mapping) {
            u0 = Z_OL1_P.ADC_mapping;
          } else if (u0 < Z_OL1_P.Saturation_LowerSat) {
            u0 = Z_OL1_P.Saturation_LowerSat;
          }

          /* DataTypeConversion: '<S1>/Cast To Single1' incorporates:
           *  Saturate: '<S1>/Saturation'
           */
          u0 = floor(u0);
          if (rtIsNaN(u0) || rtIsInf(u0)) {
            u0 = 0.0;
          } else {
            u0 = fmod(u0, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/Vout_emul_observer' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single1'
           */

          /*-- Update CMPA value for ePWM1 --*/
          {
            EPwm1Regs.CMPA.half.CMPA = (uint16_T)((u0 < 0.0 ? (uint16_T)
              -(int16_T)(uint16_T)-u0 : (uint16_T)u0));
          }

          /* S-Function (c280xadc): '<S1>/ADC' */
          {
            Z_OL1_B.ADC_o1 = (AdcRegs.ADCRESULT0) >> 4;
            Z_OL1_B.ADC_o2 = (AdcRegs.ADCRESULT1) >> 4;
            AdcRegs.ADCTRL2.bit.RST_SEQ1 = 0x1U;/* Sequencer reset*/
          }

          /* Sum: '<S1>/Sum' incorporates:
           *  Constant: '<S1>/Constant'
           *  Gain: '<S1>/Gain'
           *  Gain: '<S1>/Gain2'
           */
          InductorTF1 = 1.0 / Z_OL1_P.ADC_mapping * Z_OL1_B.ADC_o1 * InductorTF1
            + Z_OL1_P.VinNom;

          /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
           *  Constant: '<S4>/Constant1'
           *  Sum: '<S4>/Sum1'
           */
          /* MATLAB Function 'ADC-PWM Subsystem/MATLAB Function': '<S3>:1' */
          /* '<S3>:1:4' */
          /* '<S3>:1:8' */
          /* '<S3>:1:9' */
          /* '<S3>:1:10' */
          InductorTF1_tmp = Z_OL1_P.deadtimesw / Z_OL1_P.Tsw;
          InductorTF1 = (1.0 - (Z_OL1_P.VinNom - Z_OL1_P.IoutNom / (1.0 - (1.0 -
            Z_OL1_P.VinNom / InductorTF1)) * Z_OL1_P.RserL) / InductorTF1) +
            InductorTF1_tmp;

          /* DataTypeConversion: '<S1>/Cast To Single2' incorporates:
           *  Gain: '<S1>/Gain1'
           */
          u0 = floor(Z_OL1_P.TBPRD * InductorTF1);
          if (rtIsNaN(u0) || rtIsInf(u0)) {
            u0 = 0.0;
          } else {
            u0 = fmod(u0, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/ePWM' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single2'
           */

          /*-- Update CMPA value for ePWM2 --*/
          {
            EPwm2Regs.CMPA.half.CMPA = (uint16_T)((u0 < 0.0 ? (uint16_T)
              -(int16_T)(uint16_T)-u0 : (uint16_T)u0));
          }

          /* MATLAB Function: '<S4>/duty2VL4' incorporates:
           *  Constant: '<S4>/Constant'
           *  Memory: '<S4>/Memory3'
           *  Sum: '<S4>/Sum1'
           */
          /* MATLAB Function 'ADC-PWM Subsystem/emulated_plant/duty2VL4': '<S6>:1' */
          /* '<S6>:1:3' */
          u0 = ((InductorTF1 - InductorTF1_tmp) - 1.0) *
            Z_OL1_DW.Memory3_PreviousInput + Z_OL1_P.VinNom;

          /* Update for Memory: '<S4>/Memory3' */
          Z_OL1_DW.Memory3_PreviousInput = rtb_CapacitorTF;

          /* MATLAB Function: '<S4>/duty2VL4' incorporates:
           *  Constant: '<S4>/Constant'
           */
          if ((!(u0 <= Z_OL1_P.VinNom)) && (!rtIsNaN(Z_OL1_P.VinNom))) {
            u0 = Z_OL1_P.VinNom;
          }

          /* Update for DiscreteTransferFcn: '<S4>/Inductor TF1' incorporates:
           *  MATLAB Function: '<S4>/duty2VL4'
           */
          Z_OL1_DW.InductorTF1_states = (u0 - Z_OL1_P.zden_plant_i[1L] *
            Z_OL1_DW.InductorTF1_states) / Z_OL1_P.zden_plant_i[0];

          /* Update for Memory: '<S4>/Memory1' incorporates:
           *  Constant: '<S1>/Constant1'
           *  Gain: '<S1>/Gain3'
           *  Gain: '<S1>/Gain4'
           *  Product: '<S4>/Divide'
           *  Sum: '<S1>/Sum1'
           */
          Z_OL1_DW.Memory1_PreviousInput = rtb_CapacitorTF / (1.0 /
            Z_OL1_P.ADC_mapping * Z_OL1_B.ADC_o2 * Z_OL1_P.Rload + 0.5 *
            Z_OL1_P.Rload);

          /* Update for DiscreteTransferFcn: '<S4>/Capacitor TF' */
          Z_OL1_DW.CapacitorTF_states = CapacitorTF_tmp;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S8>/Hardware Interrupt' */
      }
    }

    /* Clear occurred End of sequence event event */
    AdcRegs.ADCST.bit.INT_SEQ1_CLR= 1;
  }

  HWI_TIC28x_AcknowledgeIrq(32);
}

void Z_OL1_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(32);
}
