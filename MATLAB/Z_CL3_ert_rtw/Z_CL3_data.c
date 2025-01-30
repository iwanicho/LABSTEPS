/*
 * Z_CL3_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_CL3".
 *
 * Model version              : 9.112
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Jan 16 23:13:39 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Z_CL3.h"

/* Block parameters (default storage) */
P_Z_CL3_T Z_CL3_P = {
  /* Variable: ADC_mapping
   * Referenced by:
   *   '<S1>/Gain10'
   *   '<S1>/Gain11'
   *   '<S1>/Gain2'
   *   '<S1>/Gain8'
   *   '<S1>/Gain9'
   */
  4095.0,

  /* Variable: ILmax
   * Referenced by: '<S3>/Saturation2'
   */
  3.0,

  /* Variable: RserL
   * Referenced by: '<S3>/Iout2IL2'
   */
  0.5,

  /* Variable: TBPRD
   * Referenced by:
   *   '<S1>/Gain1'
   *   '<S1>/Gain6'
   *   '<S1>/Gain7'
   */
  7500.0,

  /* Variable: VLlim
   * Referenced by:
   *   '<S5>/Gain3'
   *   '<S6>/Gain3'
   *   '<S7>/Gain3'
   */
  0.5,

  /* Variable: VfbMax
   * Referenced by: '<S1>/Gain12'
   */
  750.0,

  /* Variable: VinNom
   * Referenced by: '<S1>/Constant'
   */
  30.0,

  /* Variable: kaw_i
   * Referenced by:
   *   '<S5>/Gain2'
   *   '<S6>/Gain2'
   *   '<S7>/Gain2'
   */
  0.25222105101457981,

  /* Variable: kaw_v
   * Referenced by: '<S3>/Gain8'
   */
  3.8206407192046723,

  /* Variable: ki_i
   * Referenced by:
   *   '<S5>/Gain'
   *   '<S6>/Gain'
   *   '<S7>/Gain'
   */
  4918.7541312437006,

  /* Variable: ki_v
   * Referenced by: '<S3>/Gain13'
   */
  41.029092978462266,

  /* Variable: kp_i
   * Referenced by:
   *   '<S5>/Gain1'
   *   '<S6>/Gain1'
   *   '<S7>/Gain1'
   */
  3.9647761199052107,

  /* Variable: kp_v
   * Referenced by: '<S3>/Gain15'
   */
  0.26173620434223033,

  /* Variable: zden_Integrator
   * Referenced by:
   *   '<S3>/discrete integrator'
   *   '<S5>/discrete integrator'
   *   '<S6>/discrete integrator'
   *   '<S7>/discrete integrator'
   */
  { 1.0, -1.0 },

  /* Variable: znum_Integrator
   * Referenced by:
   *   '<S3>/discrete integrator'
   *   '<S5>/discrete integrator'
   *   '<S6>/discrete integrator'
   *   '<S7>/discrete integrator'
   */
  { 5.0E-5, 5.0E-5 },

  /* Expression: 1000
   * Referenced by: '<S1>/Gain18'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Gain19'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S6>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Memory2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/discrete integrator'
   */
  0.0,

  /* Expression: 1/3
   * Referenced by: '<S3>/Gain6'
   */
  0.33333333333333331,

  /* Expression: -1
   * Referenced by: '<S1>/Gain13'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S6>/discrete integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Memory'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain5'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S5>/discrete integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Memory'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain14'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S7>/discrete integrator'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Gain4'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Gain17'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Gain15'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Gain20'
   */
  1000.0
};
