/*
 * Z_inCL1_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_inCL1".
 *
 * Model version              : 9.35
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Jan 16 13:20:38 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Z_inCL1.h"

/* Block parameters (default storage) */
P_Z_inCL1_T Z_inCL1_P = {
  /* Variable: ADC_mapping
   * Referenced by:
   *   '<S1>/Gain10'
   *   '<S1>/Gain11'
   *   '<S1>/Gain8'
   *   '<S1>/Gain9'
   */
  4095.0,

  /* Variable: TBPRD
   * Referenced by:
   *   '<S1>/Gain1'
   *   '<S1>/Gain14'
   *   '<S1>/Gain3'
   */
  7500.0,

  /* Variable: VLlim
   * Referenced by:
   *   '<S3>/Gain3'
   *   '<S4>/Gain3'
   *   '<S5>/Gain3'
   */
  0.5,

  /* Variable: VfbMax
   * Referenced by: '<S1>/Gain12'
   */
  750.0,

  /* Variable: kaw_i
   * Referenced by:
   *   '<S3>/Gain2'
   *   '<S4>/Gain2'
   *   '<S5>/Gain2'
   */
  0.25222105101457981,

  /* Variable: ki_i
   * Referenced by:
   *   '<S3>/Gain'
   *   '<S4>/Gain'
   *   '<S5>/Gain'
   */
  4918.7541312437006,

  /* Variable: kp_i
   * Referenced by:
   *   '<S3>/Gain1'
   *   '<S4>/Gain1'
   *   '<S5>/Gain1'
   */
  3.9647761199052107,

  /* Variable: zden_Integrator
   * Referenced by:
   *   '<S3>/discrete integrator'
   *   '<S4>/discrete integrator'
   *   '<S5>/discrete integrator'
   */
  { 1.0, -1.0 },

  /* Variable: znum_Integrator
   * Referenced by:
   *   '<S3>/discrete integrator'
   *   '<S4>/discrete integrator'
   *   '<S5>/discrete integrator'
   */
  { 5.0E-5, 5.0E-5 },

  /* Expression: 15
   * Referenced by: '<S1>/Constant2'
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<S4>/Memory3'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Constant'
   */
  0.5,

  /* Expression: 1/3
   * Referenced by: '<S1>/Gain15'
   */
  0.33333333333333331,

  /* Expression: -1
   * Referenced by: '<S1>/Gain7'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S4>/discrete integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Memory3'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S3>/discrete integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Memory3'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain6'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S5>/discrete integrator'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Gain5'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Gain13'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Gain4'
   */
  1000.0
};
