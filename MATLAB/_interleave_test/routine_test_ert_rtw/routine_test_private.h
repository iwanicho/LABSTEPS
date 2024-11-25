/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: routine_test_private.h
 *
 * Code generated for Simulink model 'routine_test'.
 *
 * Model version                  : 9.11
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Nov 21 13:22:55 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef routine_test_private_h_
#define routine_test_private_h_
#include "rtwtypes.h"
#include "routine_test_types.h"

void config_ADC_A(uint16_T maxconvReg , uint16_T adcChselSEQ1Reg, uint16_T
                  adcChselSEQ2Reg, uint16_T adcChselSEQ3Reg, uint16_T
                  adcChselSEQ4Reg);
extern uint16_T MW_adcInitFlag;

#endif                                 /* routine_test_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
