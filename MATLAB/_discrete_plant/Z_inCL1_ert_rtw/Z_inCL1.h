/*
 * Z_inCL1.h
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

#ifndef Z_inCL1_h_
#define Z_inCL1_h_
#ifndef Z_inCL1_COMMON_INCLUDES_
#define Z_inCL1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "IQmathLib.h"
#endif                                 /* Z_inCL1_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "Z_inCL1_types.h"
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
  real_T analogdial_o5;                /* '<S1>/analog dial' */
  real_T analogdial_o6;                /* '<S1>/analog dial' */
} B_Z_inCL1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T discreteintegrator_states;    /* '<S3>/discrete integrator' */
  real_T Memory3_PreviousInput;        /* '<S3>/Memory3' */
} DW_Z_inCL1_T;

/* Parameters (default storage) */
struct P_Z_inCL1_T_ {
  real_T ADC_mapping;                  /* Variable: ADC_mapping
                                        * Referenced by:
                                        *   '<S1>/Gain8'
                                        *   '<S1>/Gain9'
                                        */
  real_T TBPRD;                        /* Variable: TBPRD
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T VLlim;                        /* Variable: VLlim
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real_T VfbMax;                       /* Variable: VfbMax
                                        * Referenced by: '<S1>/Gain12'
                                        */
  real_T kaw_i;                        /* Variable: kaw_i
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T ki_i;                         /* Variable: ki_i
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T kp_i;                         /* Variable: kp_i
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T zden_Integrator[2];           /* Variable: zden_Integrator
                                        * Referenced by: '<S3>/discrete integrator'
                                        */
  real_T znum_Integrator[2];           /* Variable: znum_Integrator
                                        * Referenced by: '<S3>/discrete integrator'
                                        */
  real_T Constant2_Value;              /* Expression: 15
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Memory3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/Memory3'
                                        */
  real_T Constant_Value;               /* Expression: 0.5
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T discreteintegrator_InitialState;/* Expression: 0
                                          * Referenced by: '<S3>/discrete integrator'
                                          */
  real_T Gain5_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S1>/Gain5'
                                        */
  real_T Gain13_Gain;                  /* Expression: 1000
                                        * Referenced by: '<S1>/Gain13'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S1>/Gain4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Z_inCL1_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Z_inCL1_T Z_inCL1_P;

/* Block signals (default storage) */
extern B_Z_inCL1_T Z_inCL1_B;

/* Block states (default storage) */
extern DW_Z_inCL1_T Z_inCL1_DW;

/* Model entry point functions */
extern void Z_inCL1_initialize(void);
extern void Z_inCL1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Z_inCL1_T *const Z_inCL1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void SEQ1INT(void);
  void Z_inCL1_configure_interrupts (void);
  void Z_inCL1_unconfigure_interrupts (void);

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
 * '<Root>' : 'Z_inCL1'
 * '<S1>'   : 'Z_inCL1/ADC-PWM Subsystem'
 * '<S2>'   : 'Z_inCL1/HWI_SEQ1INT'
 * '<S3>'   : 'Z_inCL1/ADC-PWM Subsystem/control'
 * '<S4>'   : 'Z_inCL1/ADC-PWM Subsystem/control/Saturation Dynamic'
 * '<S5>'   : 'Z_inCL1/ADC-PWM Subsystem/control/VL2duty'
 * '<S6>'   : 'Z_inCL1/HWI_SEQ1INT/ECSoC'
 * '<S7>'   : 'Z_inCL1/HWI_SEQ1INT/ECSoC/ECSimCodegen'
 */
#endif                                 /* Z_inCL1_h_ */
