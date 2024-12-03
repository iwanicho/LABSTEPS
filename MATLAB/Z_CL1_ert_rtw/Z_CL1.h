/*
 * Z_CL1.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_CL1".
 *
 * Model version              : 9.21
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Nov 28 13:53:50 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Z_CL1_h_
#define Z_CL1_h_
#ifndef Z_CL1_COMMON_INCLUDES_
#define Z_CL1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "IQmathLib.h"
#endif                                 /* Z_CL1_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "Z_CL1_types.h"
#include <stddef.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals (default storage) */
typedef struct {
  real_T analogdial_o1;                /* '<S1>/analog dial' */
  real_T analogdial_o2;                /* '<S1>/analog dial' */
  real_T analogdial_o3;                /* '<S1>/analog dial' */
  real_T analogdial_o4;                /* '<S1>/analog dial' */
  real_T Gain3_e;                      /* '<S7>/Gain3' */
  real_T Sum;                          /* '<S5>/Sum' */
  real_T CapacitorTF;                  /* '<S5>/Capacitor TF' */
  real_T discreteintegrator;           /* '<S7>/discrete integrator' */
  real_T Gain1_i;                      /* '<S1>/Gain1' */
  real_T Vout_ref_b;                   /* '<S1>/Sum' */
  real_T Gain4;                        /* '<S3>/Gain4' */
} B_Z_CL1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T InductorTF1_states;           /* '<S5>/Inductor TF1' */
  real_T CapacitorTF_states;           /* '<S5>/Capacitor TF' */
  real_T CommunicationInterfaceDelay_DST[2];
                                      /* '<S3>/Communication Interface Delay' */
  real_T AAFTF_states[2];              /* '<S3>/AAF TF' */
  real_T discreteintegrator_states;    /* '<S4>/discrete integrator' */
  real_T CommunicationInterfaceDelay1_DS[2];
                                     /* '<S3>/Communication Interface Delay1' */
  real_T AAFTF1_states[2];             /* '<S3>/AAF TF1' */
  real_T discreteintegrator_states_l;  /* '<S7>/discrete integrator' */
  real_T Memory1_PreviousInput;        /* '<S5>/Memory1' */
  real_T Memory3_PreviousInput;        /* '<S5>/Memory3' */
  real_T Memory3_PreviousInput_a;      /* '<S7>/Memory3' */
  real_T Memory2_PreviousInput;        /* '<S4>/Memory2' */
  real_T Memory3_PreviousInput_c;      /* '<S4>/Memory3' */
} DW_Z_CL1_T;

/* Parameters (default storage) */
struct P_Z_CL1_T_ {
  real_T ADC_mapping;                  /* Variable: ADC_mapping
                                        * Referenced by:
                                        *   '<S1>/Gain2'
                                        *   '<S1>/Gain3'
                                        *   '<S1>/Gain6'
                                        *   '<S1>/Saturation'
                                        */
  real_T ILmax;                        /* Variable: ILmax
                                        * Referenced by: '<S4>/Saturation2'
                                        */
  real_T Rload;                        /* Variable: Rload
                                        * Referenced by:
                                        *   '<S1>/Constant1'
                                        *   '<S1>/Gain4'
                                        */
  real_T RserL;                        /* Variable: RserL
                                        * Referenced by:
                                        *   '<S4>/Iout2IL2'
                                        *   '<S5>/IL2Iout'
                                        */
  real_T TBPRD;                        /* Variable: TBPRD
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Tsw;                          /* Variable: Tsw
                                        * Referenced by:
                                        *   '<S5>/Constant1'
                                        *   '<S7>/VL2duty'
                                        */
  real_T VLlim;                        /* Variable: VLlim
                                        * Referenced by: '<S7>/Gain3'
                                        */
  real_T VinNom;                       /* Variable: VinNom
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S1>/Constant3'
                                        *   '<S1>/Gain'
                                        *   '<S1>/Gain5'
                                        *   '<S4>/Constant1'
                                        *   '<S4>/Constant3'
                                        *   '<S5>/Constant'
                                        */
  real_T VoutMax;                      /* Variable: VoutMax
                                        * Referenced by:
                                        *   '<S1>/Gain'
                                        *   '<S1>/Gain5'
                                        */
  real_T deadtimesw;                   /* Variable: deadtimesw
                                        * Referenced by:
                                        *   '<S5>/Constant1'
                                        *   '<S7>/VL2duty'
                                        */
  real_T kaw_i;                        /* Variable: kaw_i
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real_T kaw_v;                        /* Variable: kaw_v
                                        * Referenced by: '<S4>/Gain8'
                                        */
  real_T ki_i;                         /* Variable: ki_i
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T ki_v;                         /* Variable: ki_v
                                        * Referenced by: '<S4>/Gain13'
                                        */
  real_T kp_i;                         /* Variable: kp_i
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T kp_v;                         /* Variable: kp_v
                                        * Referenced by: '<S4>/Gain15'
                                        */
  real_T zden_Integrator[2];           /* Variable: zden_Integrator
                                        * Referenced by:
                                        *   '<S4>/discrete integrator'
                                        *   '<S7>/discrete integrator'
                                        */
  real_T zden_aaf[3];                  /* Variable: zden_aaf
                                        * Referenced by:
                                        *   '<S3>/AAF TF'
                                        *   '<S3>/AAF TF1'
                                        */
  real_T zden_plant_i[2];              /* Variable: zden_plant_i
                                        * Referenced by: '<S5>/Inductor TF1'
                                        */
  real_T zden_plant_v[2];              /* Variable: zden_plant_v
                                        * Referenced by: '<S5>/Capacitor TF'
                                        */
  real_T znum_Integrator[2];           /* Variable: znum_Integrator
                                        * Referenced by:
                                        *   '<S4>/discrete integrator'
                                        *   '<S7>/discrete integrator'
                                        */
  real_T znum_aaf[3];                  /* Variable: znum_aaf
                                        * Referenced by:
                                        *   '<S3>/AAF TF'
                                        *   '<S3>/AAF TF1'
                                        */
  real_T znum_plant_i[2];              /* Variable: znum_plant_i
                                        * Referenced by: '<S5>/Inductor TF1'
                                        */
  real_T znum_plant_v[2];              /* Variable: znum_plant_v
                                        * Referenced by: '<S5>/Capacitor TF'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S5>/Memory1'
                                        */
  real_T InductorTF1_InitialStates;    /* Expression: 0
                                        * Referenced by: '<S5>/Inductor TF1'
                                        */
  real_T Memory3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  real_T CapacitorTF_InitialStates;    /* Expression: 0
                                        * Referenced by: '<S5>/Capacitor TF'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Memory3_InitialCondition_h;   /* Expression: 0
                                        * Referenced by: '<S7>/Memory3'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory3_InitialCondition_p;   /* Expression: 0
                                        * Referenced by: '<S4>/Memory3'
                                        */
  real_T CommunicationInterfaceDelay_Ini;/* Expression: 0.0
                                          * Referenced by: '<S3>/Communication Interface Delay'
                                          */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<S3>/Gain4'
                                        */
  real_T AAFTF_InitialStates;          /* Expression: 0
                                        * Referenced by: '<S3>/AAF TF'
                                        */
  real_T discreteintegrator_InitialState;/* Expression: 0
                                          * Referenced by: '<S4>/discrete integrator'
                                          */
  real_T CommunicationInterfaceDelay1_In;/* Expression: 0.0
                                          * Referenced by: '<S3>/Communication Interface Delay1'
                                          */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T AAFTF1_InitialStates;         /* Expression: 0
                                        * Referenced by: '<S3>/AAF TF1'
                                        */
  real_T discreteintegrator_InitialSta_j;/* Expression: 0
                                          * Referenced by: '<S7>/discrete integrator'
                                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_Z_CL1_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Z_CL1_T Z_CL1_P;

/* Block signals (default storage) */
extern B_Z_CL1_T Z_CL1_B;

/* Block states (default storage) */
extern DW_Z_CL1_T Z_CL1_DW;

/* Model entry point functions */
extern void Z_CL1_initialize(void);
extern void Z_CL1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Z_CL1_T *const Z_CL1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void SEQ1INT(void);
  void Z_CL1_configure_interrupts (void);
  void Z_CL1_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Z_CL1'
 * '<S1>'   : 'Z_CL1/ADC-PWM Subsystem'
 * '<S2>'   : 'Z_CL1/HWI_SEQ1INT'
 * '<S3>'   : 'Z_CL1/ADC-PWM Subsystem/Feedback'
 * '<S4>'   : 'Z_CL1/ADC-PWM Subsystem/control'
 * '<S5>'   : 'Z_CL1/ADC-PWM Subsystem/emulated_plant'
 * '<S6>'   : 'Z_CL1/ADC-PWM Subsystem/control/Iout2IL2'
 * '<S7>'   : 'Z_CL1/ADC-PWM Subsystem/control/innerLoop_currentControl7'
 * '<S8>'   : 'Z_CL1/ADC-PWM Subsystem/control/innerLoop_currentControl7/Saturation Dynamic'
 * '<S9>'   : 'Z_CL1/ADC-PWM Subsystem/control/innerLoop_currentControl7/VL2duty'
 * '<S10>'  : 'Z_CL1/ADC-PWM Subsystem/emulated_plant/IL2Iout'
 * '<S11>'  : 'Z_CL1/ADC-PWM Subsystem/emulated_plant/duty2VL4'
 * '<S12>'  : 'Z_CL1/HWI_SEQ1INT/ECSoC'
 * '<S13>'  : 'Z_CL1/HWI_SEQ1INT/ECSoC/ECSimCodegen'
 */
#endif                                 /* Z_CL1_h_ */
