/*
 * Z_CL1.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_CL1".
 *
 * Model version              : 9.22
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Wed Dec  4 18:43:16 2024
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
  Z_CL1_DW.InductorTF1_states = 0.0;
  Z_CL1_DW.CapacitorTF_states = 0.0;
  Z_CL1_DW.CommunicationInterfaceDelay_DST[0] = 0.0;
  Z_CL1_DW.CommunicationInterfaceDelay_DST[1] = 0.0;
  Z_CL1_DW.AAFTF_states[0] = 0.0;
  Z_CL1_DW.AAFTF_states[1] = 0.0;
  Z_CL1_DW.discreteintegrator_states = 0.0;
  Z_CL1_DW.CommunicationInterfaceDelay1_DS[0] = 0.0;
  Z_CL1_DW.CommunicationInterfaceDelay1_DS[1] = 0.0;
  Z_CL1_DW.AAFTF1_states[0] = 0.0;
  Z_CL1_DW.AAFTF1_states[1] = 0.0;
  Z_CL1_DW.discreteintegrator_states_l = 0.0;
  Z_CL1_DW.Memory1_PreviousInput = 0.0;
  Z_CL1_DW.Memory3_PreviousInput = 0.0;
  Z_CL1_DW.Memory3_PreviousInput_a = 0.0;
  Z_CL1_DW.Memory2_PreviousInput = 0.0;
  Z_CL1_DW.Memory3_PreviousInput_c = 0.0;

  /* Start for S-Function (HardwareInterrupt_sfun): '<S13>/Hardware Interrupt' incorporates:
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

  /* Start for S-Function (c280xadc): '<S1>/analog dial' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_B (3U, 0U, 0U, 47768U, 0U);

  /* Start for S-Function (c280xpwm): '<S1>/ePWM1' */

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
    EPwm2Regs.AQCTLB.all = 96;

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
       EPwm2Regs.DBCTL.bit.IN_MODE    = 3;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL     = 2;          // Polarity Select Control
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x3F) | 0x3B;
    EPwm2Regs.DBRED = 420;
    EPwm2Regs.DBFED = 420;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASEL    = 2;          // Start of conversion A Select
       EPwm2Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM2SOCA Period Select
       EPwm2Regs.ETSEL.bit.SOCBEN     = 1;          // Start of conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSEL    = 2;          // Start of conversion B Select
       EPwm2Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSEL.bit.INTEN      = 0;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSEL     = 4;          // EPWM2INTn Select
       EPwm2Regs.ETPS.bit.INTPRD      = 1;          // EPWM2INTn Period Select
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0F) | 0xA204;
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

  /* End of Start for S-Function (HardwareInterrupt_sfun): '<S13>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S13>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC-PWM Subsystem'
   */

  /* System initialize for function-call system: '<Root>/ADC-PWM Subsystem' */

  /* InitializeConditions for Memory: '<S5>/Memory1' */
  Z_CL1_DW.Memory1_PreviousInput = Z_CL1_P.Memory1_InitialCondition;

  /* InitializeConditions for DiscreteTransferFcn: '<S5>/Inductor TF1' */
  Z_CL1_DW.InductorTF1_states = Z_CL1_P.InductorTF1_InitialStates;

  /* InitializeConditions for Memory: '<S5>/Memory3' */
  Z_CL1_DW.Memory3_PreviousInput = Z_CL1_P.Memory3_InitialCondition;

  /* InitializeConditions for DiscreteTransferFcn: '<S5>/Capacitor TF' */
  Z_CL1_DW.CapacitorTF_states = Z_CL1_P.CapacitorTF_InitialStates;

  /* InitializeConditions for Memory: '<S7>/Memory3' */
  Z_CL1_DW.Memory3_PreviousInput_a = Z_CL1_P.Memory3_InitialCondition_h;

  /* InitializeConditions for Memory: '<S4>/Memory2' */
  Z_CL1_DW.Memory2_PreviousInput = Z_CL1_P.Memory2_InitialCondition;

  /* InitializeConditions for Memory: '<S4>/Memory3' */
  Z_CL1_DW.Memory3_PreviousInput_c = Z_CL1_P.Memory3_InitialCondition_p;

  /* InitializeConditions for DiscreteTransferFcn: '<S4>/discrete integrator' */
  Z_CL1_DW.discreteintegrator_states = Z_CL1_P.discreteintegrator_InitialState;

  /* InitializeConditions for Delay: '<S3>/Communication Interface Delay' */
  Z_CL1_DW.CommunicationInterfaceDelay_DST[0] =
    Z_CL1_P.CommunicationInterfaceDelay_Ini;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/AAF TF' */
  Z_CL1_DW.AAFTF_states[0] = Z_CL1_P.AAFTF_InitialStates;

  /* InitializeConditions for Delay: '<S3>/Communication Interface Delay1' */
  Z_CL1_DW.CommunicationInterfaceDelay1_DS[0] =
    Z_CL1_P.CommunicationInterfaceDelay1_In;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/AAF TF1' */
  Z_CL1_DW.AAFTF1_states[0] = Z_CL1_P.AAFTF1_InitialStates;

  /* InitializeConditions for Delay: '<S3>/Communication Interface Delay' */
  Z_CL1_DW.CommunicationInterfaceDelay_DST[1] =
    Z_CL1_P.CommunicationInterfaceDelay_Ini;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/AAF TF' */
  Z_CL1_DW.AAFTF_states[1] = Z_CL1_P.AAFTF_InitialStates;

  /* InitializeConditions for Delay: '<S3>/Communication Interface Delay1' */
  Z_CL1_DW.CommunicationInterfaceDelay1_DS[1] =
    Z_CL1_P.CommunicationInterfaceDelay1_In;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/AAF TF1' */
  Z_CL1_DW.AAFTF1_states[1] = Z_CL1_P.AAFTF1_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S7>/discrete integrator' */
  Z_CL1_DW.discreteintegrator_states_l = Z_CL1_P.discreteintegrator_InitialSta_j;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S13>/Hardware Interrupt' */
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

/* Hardware Interrupt Block: '<S13>/Hardware Interrupt' */
interrupt void SEQ1INT(void)
{
  /* Event: End of sequence event */
  /* Check event End of sequence event occurred */
  if (0 != (AdcRegs.ADCST.bit.INT_SEQ1==1)) {
    if (1 == runModel) {
      {
        /* S-Function (HardwareInterrupt_sfun): '<S13>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/ADC-PWM Subsystem' */
        {
          real_T AAFTF;
          real_T AAFTF1_tmp;
          real_T CapacitorTF_tmp;
          real_T InductorTF1;
          real_T rtb_Gain1;
          real_T rtb_Gain13;
          real_T rtb_IL;
          real_T x_idx_1_tmp;

          /* DiscreteTransferFcn: '<S5>/Inductor TF1' */
          InductorTF1 = Z_CL1_P.znum_plant_i[1L] * Z_CL1_DW.InductorTF1_states;

          /* MATLAB Function: '<S5>/IL2Iout' incorporates:
           *  Constant: '<S5>/Constant'
           *  Memory: '<S5>/Memory1'
           */
          CapacitorTF_tmp = Z_CL1_DW.Memory1_PreviousInput;

          /* MATLAB Function 'ADC-PWM Subsystem/emulated_plant/IL2Iout': '<S10>:1' */
          if (Z_CL1_DW.Memory1_PreviousInput < Z_CL1_P.VinNom) {
            /* '<S10>:1:3' */
            /* '<S10>:1:4' */
            CapacitorTF_tmp = Z_CL1_P.VinNom;
          }

          /* DiscreteTransferFcn: '<S5>/Capacitor TF' incorporates:
           *  Constant: '<S5>/Constant'
           *  MATLAB Function: '<S5>/IL2Iout'
           *  Memory: '<S5>/Memory3'
           *  Sum: '<S5>/Sum'
           */
          /* '<S10>:1:6' */
          /* '<S10>:1:7' */
          CapacitorTF_tmp = (((Z_CL1_P.VinNom - Z_CL1_P.RserL * InductorTF1) /
                              CapacitorTF_tmp * InductorTF1 -
                              Z_CL1_DW.Memory3_PreviousInput) -
                             Z_CL1_P.zden_plant_v[1L] *
                             Z_CL1_DW.CapacitorTF_states) /
            Z_CL1_P.zden_plant_v[0];
          Z_CL1_B.CapacitorTF = Z_CL1_P.znum_plant_v[0] * CapacitorTF_tmp +
            Z_CL1_P.znum_plant_v[1L] * Z_CL1_DW.CapacitorTF_states;

          /* Gain: '<S1>/Gain5' incorporates:
           *  Gain: '<S1>/Gain'
           */
          Z_CL1_B.Vout_ref_n = Z_CL1_P.VoutMax - Z_CL1_P.VinNom;

          /* Gain: '<S1>/Gain6' incorporates:
           *  Constant: '<S1>/Constant3'
           *  Gain: '<S1>/Gain5'
           *  Sum: '<S1>/Sum2'
           */
          Z_CL1_B.Gain1_i = 1.0 / Z_CL1_B.Vout_ref_n * (Z_CL1_B.CapacitorTF -
            Z_CL1_P.VinNom) * Z_CL1_P.ADC_mapping;

          /* Saturate: '<S1>/Saturation' */
          if (Z_CL1_B.Gain1_i > Z_CL1_P.ADC_mapping) {
            Z_CL1_B.Gain1_i = Z_CL1_P.ADC_mapping;
          } else if (Z_CL1_B.Gain1_i < Z_CL1_P.Saturation_LowerSat) {
            Z_CL1_B.Gain1_i = Z_CL1_P.Saturation_LowerSat;
          }

          /* DataTypeConversion: '<S1>/Cast To Single1' incorporates:
           *  Saturate: '<S1>/Saturation'
           */
          Z_CL1_B.Gain1_i = floor(Z_CL1_B.Gain1_i);
          if (rtIsNaN(Z_CL1_B.Gain1_i) || rtIsInf(Z_CL1_B.Gain1_i)) {
            Z_CL1_B.Gain1_i = 0.0;
          } else {
            Z_CL1_B.Gain1_i = fmod(Z_CL1_B.Gain1_i, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/Vout_emul_observer' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single1'
           */

          /*-- Update CMPA value for ePWM1 --*/
          {
            EPwm1Regs.CMPA.half.CMPA = (uint16_T)((Z_CL1_B.Gain1_i < 0.0 ?
              (uint16_T)-(int16_T)(uint16_T)-Z_CL1_B.Gain1_i : (uint16_T)
              Z_CL1_B.Gain1_i));
          }

          /* Gain: '<S7>/Gain3' incorporates:
           *  Constant: '<S4>/Constant1'
           */
          Z_CL1_B.Gain3_e = Z_CL1_P.VLlim * Z_CL1_P.VinNom;

          /* S-Function (c280xadc): '<S1>/analog dial' */
          {
            Z_CL1_B.analogdial_o1 = (AdcRegs.ADCRESULT8) >> 4;
            Z_CL1_B.analogdial_o2 = (AdcRegs.ADCRESULT9) >> 4;
            Z_CL1_B.analogdial_o3 = (AdcRegs.ADCRESULT10) >> 4;
            Z_CL1_B.analogdial_o4 = (AdcRegs.ADCRESULT11) >> 4;
            AdcRegs.ADCTRL2.bit.RST_SEQ2 = 0x1U;/* Sequencer SEQ2 reset*/
          }

          /* Bias: '<S1>/Bias4' incorporates:
           *  Gain: '<S1>/Gain'
           *  Gain: '<S1>/Gain2'
           */
          Z_CL1_B.Vout_ref_n = 1.0 / Z_CL1_P.ADC_mapping * Z_CL1_B.analogdial_o1
            * Z_CL1_B.Vout_ref_n + Z_CL1_P.VinNom;

          /* DiscreteTransferFcn: '<S3>/AAF TF' incorporates:
           *  Delay: '<S3>/Communication Interface Delay'
           *  Gain: '<S3>/Gain4'
           */
          Z_CL1_B.Sum = ((Z_CL1_P.Gain4_Gain *
                          Z_CL1_DW.CommunicationInterfaceDelay_DST[0] -
                          Z_CL1_DW.AAFTF_states[0L] * Z_CL1_P.zden_aaf[1L]) -
                         Z_CL1_DW.AAFTF_states[1L] * Z_CL1_P.zden_aaf[2L]) /
            Z_CL1_P.zden_aaf[0];
          AAFTF = (Z_CL1_P.znum_aaf[0] * Z_CL1_B.Sum + Z_CL1_DW.AAFTF_states[0L]
                   * Z_CL1_P.znum_aaf[1L]) + Z_CL1_DW.AAFTF_states[1L] *
            Z_CL1_P.znum_aaf[2L];

          /* DiscreteTransferFcn: '<S4>/discrete integrator' incorporates:
           *  Gain: '<S4>/Gain13'
           *  Memory: '<S4>/Memory3'
           *  Sum: '<S4>/Sum14'
           *  Sum: '<S4>/Sum8'
           */
          Z_CL1_B.Gain4 = (((Z_CL1_B.Vout_ref_n - AAFTF) -
                            Z_CL1_DW.Memory3_PreviousInput_c) * Z_CL1_P.ki_v -
                           Z_CL1_P.zden_Integrator[1L] *
                           Z_CL1_DW.discreteintegrator_states) /
            Z_CL1_P.zden_Integrator[0];

          /* Sum: '<S4>/Sum9' incorporates:
           *  DiscreteTransferFcn: '<S4>/discrete integrator'
           *  Gain: '<S4>/Gain15'
           */
          rtb_Gain13 = (Z_CL1_P.znum_Integrator[0] * Z_CL1_B.Gain4 +
                        Z_CL1_P.znum_Integrator[1L] *
                        Z_CL1_DW.discreteintegrator_states) - Z_CL1_P.kp_v *
            AAFTF;

          /* MATLAB Function: '<S4>/Iout2IL2' incorporates:
           *  Constant: '<S4>/Constant3'
           *  Memory: '<S4>/Memory2'
           */
          /* MATLAB Function 'ADC-PWM Subsystem/control/Iout2IL2': '<S6>:1' */
          if (Z_CL1_B.Vout_ref_n < Z_CL1_P.VinNom) {
            /* '<S6>:1:3' */
            /* '<S6>:1:4' */
            Z_CL1_B.Vout_ref_n = Z_CL1_P.VinNom;
          }

          /* '<S6>:1:6' */
          Z_CL1_B.Vout_ref_n = (Z_CL1_P.VinNom - Z_CL1_P.RserL *
                                Z_CL1_DW.Memory2_PreviousInput) /
            Z_CL1_B.Vout_ref_n;

          /* '<S6>:1:7' */
          rtb_IL = rtb_Gain13 / Z_CL1_B.Vout_ref_n;

          /* Saturate: '<S4>/Saturation2' */
          if (rtb_IL > Z_CL1_P.ILmax) {
            rtb_IL = Z_CL1_P.ILmax;
          } else if (rtb_IL < -Z_CL1_P.ILmax) {
            rtb_IL = -Z_CL1_P.ILmax;
          }

          /* End of Saturate: '<S4>/Saturation2' */

          /* DiscreteTransferFcn: '<S3>/AAF TF1' incorporates:
           *  Delay: '<S3>/Communication Interface Delay1'
           *  Gain: '<S3>/Gain1'
           */
          AAFTF1_tmp = ((Z_CL1_P.Gain1_Gain *
                         Z_CL1_DW.CommunicationInterfaceDelay1_DS[0] -
                         Z_CL1_DW.AAFTF1_states[0L] * Z_CL1_P.zden_aaf[1L]) -
                        Z_CL1_DW.AAFTF1_states[1L] * Z_CL1_P.zden_aaf[2L]) /
            Z_CL1_P.zden_aaf[0];
          Z_CL1_B.Gain1_i = (Z_CL1_P.znum_aaf[0] * AAFTF1_tmp +
                             Z_CL1_DW.AAFTF1_states[0L] * Z_CL1_P.znum_aaf[1L])
            + Z_CL1_DW.AAFTF1_states[1L] * Z_CL1_P.znum_aaf[2L];

          /* DiscreteTransferFcn: '<S7>/discrete integrator' incorporates:
           *  Gain: '<S7>/Gain'
           *  Memory: '<S7>/Memory3'
           *  Sum: '<S7>/Sum'
           *  Sum: '<S7>/Sum3'
           */
          rtb_Gain1 = (((rtb_IL - Z_CL1_B.Gain1_i) -
                        Z_CL1_DW.Memory3_PreviousInput_a) * Z_CL1_P.ki_i -
                       Z_CL1_P.zden_Integrator[1L] *
                       Z_CL1_DW.discreteintegrator_states_l) /
            Z_CL1_P.zden_Integrator[0];

          /* Sum: '<S7>/Sum1' incorporates:
           *  DiscreteTransferFcn: '<S7>/discrete integrator'
           *  Gain: '<S7>/Gain1'
           */
          Z_CL1_B.discreteintegrator = (Z_CL1_P.znum_Integrator[0] * rtb_Gain1 +
            Z_CL1_P.znum_Integrator[1L] * Z_CL1_DW.discreteintegrator_states_l)
            - Z_CL1_P.kp_i * Z_CL1_B.Gain1_i;

          /* Switch: '<S8>/Switch2' incorporates:
           *  RelationalOperator: '<S8>/LowerRelop1'
           */
          if (!(Z_CL1_B.discreteintegrator > Z_CL1_B.Gain3_e)) {
            /* Sum: '<S7>/Sum4' incorporates:
             *  Constant: '<S4>/Constant1'
             */
            Z_CL1_B.Gain3_e = Z_CL1_P.VinNom - AAFTF;

            /* Switch: '<S8>/Switch' incorporates:
             *  RelationalOperator: '<S8>/UpperRelop'
             */
            if (!(Z_CL1_B.discreteintegrator < Z_CL1_B.Gain3_e)) {
              Z_CL1_B.Gain3_e = Z_CL1_B.discreteintegrator;
            }

            /* End of Switch: '<S8>/Switch' */
          }

          /* End of Switch: '<S8>/Switch2' */

          /* MATLAB Function: '<S7>/VL2duty' incorporates:
           *  Constant: '<S4>/Constant1'
           *  Constant: '<S5>/Constant1'
           *  Sum: '<S5>/Sum1'
           */
          /* MATLAB Function 'ADC-PWM Subsystem/control/innerLoop_currentControl7/VL2duty': '<S9>:1' */
          /* '<S9>:1:3' */
          x_idx_1_tmp = Z_CL1_P.deadtimesw / Z_CL1_P.Tsw;
          AAFTF = ((Z_CL1_B.Gain3_e - Z_CL1_P.VinNom) / AAFTF + 1.0) +
            x_idx_1_tmp;
          if (!(AAFTF > 0.0)) {
            AAFTF = 0.0;
          }

          if (!(AAFTF < 1.0)) {
            AAFTF = 1.0;
          }

          /* End of MATLAB Function: '<S7>/VL2duty' */

          /* DataTypeConversion: '<S1>/Cast To Single2' incorporates:
           *  Gain: '<S1>/Gain1'
           */
          Z_CL1_B.Gain1_i = floor(Z_CL1_P.TBPRD * AAFTF);
          if (rtIsNaN(Z_CL1_B.Gain1_i) || rtIsInf(Z_CL1_B.Gain1_i)) {
            Z_CL1_B.Gain1_i = 0.0;
          } else {
            Z_CL1_B.Gain1_i = fmod(Z_CL1_B.Gain1_i, 65536.0);
          }

          /* S-Function (c280xpwm): '<S1>/ePWM1' incorporates:
           *  DataTypeConversion: '<S1>/Cast To Single2'
           */

          /*-- Update CMPB value for ePWM2 --*/
          {
            EPwm2Regs.CMPB = (uint16_T)((Z_CL1_B.Gain1_i < 0.0 ? (uint16_T)
              -(int16_T)(uint16_T)-Z_CL1_B.Gain1_i : (uint16_T)Z_CL1_B.Gain1_i));
          }

          /* MATLAB Function: '<S5>/duty2VL4' incorporates:
           *  Constant: '<S5>/Constant'
           *  Memory: '<S5>/Memory1'
           *  Sum: '<S5>/Sum1'
           */
          /* MATLAB Function 'ADC-PWM Subsystem/emulated_plant/duty2VL4': '<S11>:1' */
          /* '<S11>:1:3' */
          Z_CL1_B.Gain1_i = ((AAFTF - x_idx_1_tmp) - 1.0) *
            Z_CL1_DW.Memory1_PreviousInput + Z_CL1_P.VinNom;

          /* Update for Memory: '<S5>/Memory1' */
          Z_CL1_DW.Memory1_PreviousInput = Z_CL1_B.CapacitorTF;

          /* MATLAB Function: '<S5>/duty2VL4' incorporates:
           *  Constant: '<S5>/Constant'
           */
          if ((!(Z_CL1_B.Gain1_i <= Z_CL1_P.VinNom)) && (!rtIsNaN(Z_CL1_P.VinNom)))
          {
            Z_CL1_B.Gain1_i = Z_CL1_P.VinNom;
          }

          /* Update for DiscreteTransferFcn: '<S5>/Inductor TF1' incorporates:
           *  MATLAB Function: '<S5>/duty2VL4'
           */
          Z_CL1_DW.InductorTF1_states = (Z_CL1_B.Gain1_i - Z_CL1_P.zden_plant_i
            [1L] * Z_CL1_DW.InductorTF1_states) / Z_CL1_P.zden_plant_i[0];

          /* Update for Memory: '<S5>/Memory3' incorporates:
           *  Bias: '<S1>/Bias3'
           *  Gain: '<S1>/Gain3'
           *  Gain: '<S1>/Gain4'
           *  Product: '<S5>/Divide'
           */
          Z_CL1_DW.Memory3_PreviousInput = Z_CL1_B.CapacitorTF / (1.0 /
            Z_CL1_P.ADC_mapping * Z_CL1_B.analogdial_o2 * Z_CL1_P.Rload + 0.5 *
            Z_CL1_P.Rload);

          /* Update for DiscreteTransferFcn: '<S5>/Capacitor TF' */
          Z_CL1_DW.CapacitorTF_states = CapacitorTF_tmp;

          /* Update for Memory: '<S7>/Memory3' incorporates:
           *  Gain: '<S7>/Gain2'
           *  Sum: '<S7>/Sum2'
           */
          Z_CL1_DW.Memory3_PreviousInput_a = (Z_CL1_B.discreteintegrator -
            Z_CL1_B.Gain3_e) * Z_CL1_P.kaw_i;

          /* Update for Memory: '<S4>/Memory2' */
          Z_CL1_DW.Memory2_PreviousInput = rtb_IL;

          /* Update for Memory: '<S4>/Memory3' incorporates:
           *  Gain: '<S4>/Gain8'
           *  MATLAB Function: '<S4>/Iout2IL2'
           *  Product: '<S4>/Product2'
           *  Sum: '<S4>/Sum13'
           */
          Z_CL1_DW.Memory3_PreviousInput_c = (rtb_Gain13 - rtb_IL *
            Z_CL1_B.Vout_ref_n) * Z_CL1_P.kaw_v;

          /* Update for Delay: '<S3>/Communication Interface Delay' */
          Z_CL1_DW.CommunicationInterfaceDelay_DST[0] =
            Z_CL1_DW.CommunicationInterfaceDelay_DST[1];
          Z_CL1_DW.CommunicationInterfaceDelay_DST[1] = Z_CL1_B.CapacitorTF;

          /* Update for DiscreteTransferFcn: '<S3>/AAF TF' */
          Z_CL1_DW.AAFTF_states[1L] = Z_CL1_DW.AAFTF_states[0L];
          Z_CL1_DW.AAFTF_states[0L] = Z_CL1_B.Sum;

          /* Update for DiscreteTransferFcn: '<S4>/discrete integrator' */
          Z_CL1_DW.discreteintegrator_states = Z_CL1_B.Gain4;

          /* Update for Delay: '<S3>/Communication Interface Delay1' */
          Z_CL1_DW.CommunicationInterfaceDelay1_DS[0] =
            Z_CL1_DW.CommunicationInterfaceDelay1_DS[1];
          Z_CL1_DW.CommunicationInterfaceDelay1_DS[1] = InductorTF1;

          /* Update for DiscreteTransferFcn: '<S3>/AAF TF1' */
          Z_CL1_DW.AAFTF1_states[1L] = Z_CL1_DW.AAFTF1_states[0L];
          Z_CL1_DW.AAFTF1_states[0L] = AAFTF1_tmp;

          /* Update for DiscreteTransferFcn: '<S7>/discrete integrator' */
          Z_CL1_DW.discreteintegrator_states_l = rtb_Gain1;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S13>/Hardware Interrupt' */
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
