/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: routine_test.h
 *
 * Code generated for Simulink model 'routine_test'.
 *
 * Model version                  : 9.12
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Nov 25 18:50:12 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef routine_test_h_
#define routine_test_h_
#ifndef routine_test_COMMON_INCLUDES_
#define routine_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "IQmathLib.h"
#endif                                 /* routine_test_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "routine_test_types.h"
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
} BlockIO_routine_test;

/* Parameters (default storage) */
struct Parameters_routine_test_ {
  real_T ADC_mapping;                  /* Variable: ADC_mapping
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T TBPRD;                        /* Variable: TBPRD
                                        * Referenced by: '<S1>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_routine_test {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern Parameters_routine_test routine_test_P;

/* Block signals (default storage) */
extern BlockIO_routine_test routine_test_B;

/* Model entry point functions */
extern void routine_test_initialize(void);
extern void routine_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_routine_test *const routine_test_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void SEQ1INT(void);
  void routine_test_configure_interrupts (void);
  void routine_test_unconfigure_interrupts (void);

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
 * '<Root>' : 'routine_test'
 * '<S1>'   : 'routine_test/ADC-PWM Subsystem'
 * '<S2>'   : 'routine_test/HWI_SEQ1INT'
 * '<S3>'   : 'routine_test/HWI_SEQ1INT/ECSoC'
 * '<S4>'   : 'routine_test/HWI_SEQ1INT/ECSoC/ECSimCodegen'
 */
#endif                                 /* routine_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
