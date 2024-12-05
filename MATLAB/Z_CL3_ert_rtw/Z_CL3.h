/*
 * Z_CL3.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_CL3".
 *
 * Model version              : 9.45
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Wed Dec  4 13:18:47 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Z_CL3_h_
#define Z_CL3_h_
#ifndef Z_CL3_COMMON_INCLUDES_
#define Z_CL3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "IQmathLib.h"
#endif                                 /* Z_CL3_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "Z_CL3_types.h"
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

/* Block signals for system '<S5>/VL2duty' */
typedef struct {
  real_T D;                            /* '<S5>/VL2duty' */
} B_VL2duty_Z_CL3_T;

/* Block signals (default storage) */
typedef struct {
  real_T analogdial_o1;                /* '<S1>/analog dial' */
  real_T analogdial_o2;                /* '<S1>/analog dial' */
  real_T analogdial_o3;                /* '<S1>/analog dial' */
  real_T analogdial_o4;                /* '<S1>/analog dial' */
  real_T analogdial_o5;                /* '<S1>/analog dial' */
  real_T analogdial_o6;                /* '<S1>/analog dial' */
  real_T VoutRef;
  real_T Sum3_c;                       /* '<S1>/Sum3' */
  real_T Memory;                       /* '<S7>/Memory' */
  real_T discreteintegrator;           /* '<S7>/discrete integrator' */
  real_T Gain12;                       /* '<S1>/Gain12' */
  real_T Gain13;                       /* '<S3>/Gain13' */
  real_T IL;                           /* '<S3>/Saturation2' */
  real_T Gain7;                        /* '<S1>/Gain7' */
  real_T Gain;                         /* '<S5>/Gain' */
  B_VL2duty_Z_CL3_T sf_VL2duty_j;      /* '<S7>/VL2duty' */
  B_VL2duty_Z_CL3_T sf_VL2duty_h;      /* '<S6>/VL2duty' */
  B_VL2duty_Z_CL3_T sf_VL2duty;        /* '<S5>/VL2duty' */
} B_Z_CL3_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T discreteintegrator_states;    /* '<S3>/discrete integrator' */
  real_T discreteintegrator_states_a;  /* '<S5>/discrete integrator' */
  real_T discreteintegrator_states_l;  /* '<S6>/discrete integrator' */
  real_T discreteintegrator_states_c;  /* '<S7>/discrete integrator' */
  real_T Memory_PreviousInput;         /* '<S5>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S3>/Memory2' */
  real_T Memory_PreviousInput_g;       /* '<S3>/Memory' */
  real_T Memory_PreviousInput_c;       /* '<S6>/Memory' */
  real_T Memory_PreviousInput_p;       /* '<S7>/Memory' */
} DW_Z_CL3_T;

/* Parameters (default storage) */
struct P_Z_CL3_T_ {
  real_T ADC_mapping;                  /* Variable: ADC_mapping
                                        * Referenced by:
                                        *   '<S1>/Gain10'
                                        *   '<S1>/Gain11'
                                        *   '<S1>/Gain8'
                                        *   '<S1>/Gain9'
                                        */
  real_T ILmax;                        /* Variable: ILmax
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  real_T IfbMax;                       /* Variable: IfbMax
                                        * Referenced by:
                                        *   '<S1>/Constant2'
                                        *   '<S1>/Gain13'
                                        *   '<S1>/Gain14'
                                        *   '<S1>/Gain15'
                                        */
  real_T RserL;                        /* Variable: RserL
                                        * Referenced by: '<S3>/Iout2IL2'
                                        */
  real_T TBPRD;                        /* Variable: TBPRD
                                        * Referenced by:
                                        *   '<S1>/Gain1'
                                        *   '<S1>/Gain6'
                                        *   '<S1>/Gain7'
                                        */
  real_T Tsw;                          /* Variable: Tsw
                                        * Referenced by:
                                        *   '<S5>/VL2duty'
                                        *   '<S6>/VL2duty'
                                        *   '<S7>/VL2duty'
                                        */
  real_T VLlim;                        /* Variable: VLlim
                                        * Referenced by:
                                        *   '<S5>/Gain3'
                                        *   '<S6>/Gain3'
                                        *   '<S7>/Gain3'
                                        */
  real_T VfbMax;                       /* Variable: VfbMax
                                        * Referenced by: '<S1>/Gain12'
                                        */
  real_T VinNom;                       /* Variable: VinNom
                                        * Referenced by:
                                        *   '<S3>/Constant1'
                                        *   '<S3>/Constant2'
                                        *   '<S3>/Constant3'
                                        *   '<S3>/Constant4'
                                        */
  real_T VoutNom;                      /* Variable: VoutNom
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T deadtimesw;                   /* Variable: deadtimesw
                                        * Referenced by:
                                        *   '<S5>/VL2duty'
                                        *   '<S6>/VL2duty'
                                        *   '<S7>/VL2duty'
                                        */
  real_T kaw_i;                        /* Variable: kaw_i
                                        * Referenced by:
                                        *   '<S5>/Gain2'
                                        *   '<S6>/Gain2'
                                        *   '<S7>/Gain2'
                                        */
  real_T kaw_v;                        /* Variable: kaw_v
                                        * Referenced by: '<S3>/Gain8'
                                        */
  real_T ki_i;                         /* Variable: ki_i
                                        * Referenced by:
                                        *   '<S5>/Gain'
                                        *   '<S6>/Gain'
                                        *   '<S7>/Gain'
                                        */
  real_T ki_v;                         /* Variable: ki_v
                                        * Referenced by: '<S3>/Gain13'
                                        */
  real_T kp_i;                         /* Variable: kp_i
                                        * Referenced by:
                                        *   '<S5>/Gain1'
                                        *   '<S6>/Gain1'
                                        *   '<S7>/Gain1'
                                        */
  real_T kp_v;                         /* Variable: kp_v
                                        * Referenced by: '<S3>/Gain15'
                                        */
  real_T zden_Integrator[2];           /* Variable: zden_Integrator
                                        * Referenced by:
                                        *   '<S3>/discrete integrator'
                                        *   '<S5>/discrete integrator'
                                        *   '<S6>/discrete integrator'
                                        *   '<S7>/discrete integrator'
                                        */
  real_T znum_Integrator[2];           /* Variable: znum_Integrator
                                        * Referenced by:
                                        *   '<S3>/discrete integrator'
                                        *   '<S5>/discrete integrator'
                                        *   '<S6>/discrete integrator'
                                        *   '<S7>/discrete integrator'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S5>/Memory'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/Memory2'
                                        */
  real_T Memory_InitialCondition_f;    /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */
  real_T discreteintegrator_InitialState;/* Expression: 0
                                          * Referenced by: '<S3>/discrete integrator'
                                          */
  real_T Gain6_Gain;                   /* Expression: 1/3
                                        * Referenced by: '<S3>/Gain6'
                                        */
  real_T discreteintegrator_InitialSta_m;/* Expression: 0
                                          * Referenced by: '<S5>/discrete integrator'
                                          */
  real_T Memory_InitialCondition_fe;   /* Expression: 0
                                        * Referenced by: '<S6>/Memory'
                                        */
  real_T discreteintegrator_InitialSta_e;/* Expression: 0
                                          * Referenced by: '<S6>/discrete integrator'
                                          */
  real_T Memory_InitialCondition_i;    /* Expression: 0
                                        * Referenced by: '<S7>/Memory'
                                        */
  real_T discreteintegrator_InitialSt_me;/* Expression: 0
                                          * Referenced by: '<S7>/discrete integrator'
                                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_Z_CL3_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Z_CL3_T Z_CL3_P;

/* Block signals (default storage) */
extern B_Z_CL3_T Z_CL3_B;

/* Block states (default storage) */
extern DW_Z_CL3_T Z_CL3_DW;

/* Model entry point functions */
extern void Z_CL3_initialize(void);
extern void Z_CL3_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Z_CL3_T *const Z_CL3_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void SEQ1INT(void);
  void Z_CL3_configure_interrupts (void);
  void Z_CL3_unconfigure_interrupts (void);

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
 * '<Root>' : 'Z_CL3'
 * '<S1>'   : 'Z_CL3/ADC-PWM Subsystem'
 * '<S2>'   : 'Z_CL3/HWI_SEQ1INT'
 * '<S3>'   : 'Z_CL3/ADC-PWM Subsystem/control'
 * '<S4>'   : 'Z_CL3/ADC-PWM Subsystem/control/Iout2IL2'
 * '<S5>'   : 'Z_CL3/ADC-PWM Subsystem/control/innerLoop_currentControl7'
 * '<S6>'   : 'Z_CL3/ADC-PWM Subsystem/control/innerLoop_currentControl8'
 * '<S7>'   : 'Z_CL3/ADC-PWM Subsystem/control/innerLoop_currentControl9'
 * '<S8>'   : 'Z_CL3/ADC-PWM Subsystem/control/innerLoop_currentControl7/Saturation Dynamic'
 * '<S9>'   : 'Z_CL3/ADC-PWM Subsystem/control/innerLoop_currentControl7/VL2duty'
 * '<S10>'  : 'Z_CL3/ADC-PWM Subsystem/control/innerLoop_currentControl8/Saturation Dynamic'
 * '<S11>'  : 'Z_CL3/ADC-PWM Subsystem/control/innerLoop_currentControl8/VL2duty'
 * '<S12>'  : 'Z_CL3/ADC-PWM Subsystem/control/innerLoop_currentControl9/Saturation Dynamic'
 * '<S13>'  : 'Z_CL3/ADC-PWM Subsystem/control/innerLoop_currentControl9/VL2duty'
 * '<S14>'  : 'Z_CL3/HWI_SEQ1INT/ECSoC'
 * '<S15>'  : 'Z_CL3/HWI_SEQ1INT/ECSoC/ECSimCodegen'
 */
#endif                                 /* Z_CL3_h_ */
