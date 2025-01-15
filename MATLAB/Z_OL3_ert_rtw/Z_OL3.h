/*
 * Z_OL3.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_OL3".
 *
 * Model version              : 9.33
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Wed Jan  8 18:21:01 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Z_OL3_h_
#define Z_OL3_h_
#ifndef Z_OL3_COMMON_INCLUDES_
#define Z_OL3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "IQmathLib.h"
#endif                                 /* Z_OL3_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "Z_OL3_types.h"
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
  real_T ADC_o1;                       /* '<S1>/ADC' */
  real_T ADC_o2;                       /* '<S1>/ADC' */
} B_Z_OL3_T;

/* Parameters (default storage) */
struct P_Z_OL3_T_ {
  real_T IoutNom;                      /* Variable: IoutNom
                                        * Referenced by: '<S1>/MATLAB Function'
                                        */
  real_T RserL;                        /* Variable: RserL
                                        * Referenced by: '<S1>/MATLAB Function'
                                        */
  real_T TBPRD;                        /* Variable: TBPRD
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T VinNom;                       /* Variable: VinNom
                                        * Referenced by: '<S1>/MATLAB Function'
                                        */
  real_T VoutNom;                      /* Variable: VoutNom
                                        * Referenced by: '<S1>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Z_OL3_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Z_OL3_T Z_OL3_P;

/* Block signals (default storage) */
extern B_Z_OL3_T Z_OL3_B;

/* Model entry point functions */
extern void Z_OL3_initialize(void);
extern void Z_OL3_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Z_OL3_T *const Z_OL3_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void SEQ1INT(void);
  void Z_OL3_configure_interrupts (void);
  void Z_OL3_unconfigure_interrupts (void);

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
 * '<Root>' : 'Z_OL3'
 * '<S1>'   : 'Z_OL3/ADC-PWM Subsystem'
 * '<S2>'   : 'Z_OL3/HWI_SEQ1INT'
 * '<S3>'   : 'Z_OL3/ADC-PWM Subsystem/MATLAB Function'
 * '<S4>'   : 'Z_OL3/HWI_SEQ1INT/ECSoC'
 * '<S5>'   : 'Z_OL3/HWI_SEQ1INT/ECSoC/ECSimCodegen'
 */
#endif                                 /* Z_OL3_h_ */
