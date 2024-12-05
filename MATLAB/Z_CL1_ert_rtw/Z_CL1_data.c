/*
 * Z_CL1_data.c
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

/* Block parameters (default storage) */
P_Z_CL1_T Z_CL1_P = {
  /* Variable: ADC_mapping
   * Referenced by:
   *   '<S1>/Gain2'
   *   '<S1>/Gain3'
   *   '<S1>/Gain6'
   *   '<S1>/Saturation'
   */
  4095.0,

  /* Variable: ILmax
   * Referenced by: '<S4>/Saturation2'
   */
  10.0,

  /* Variable: Rload
   * Referenced by:
   *   '<S1>/Bias3'
   *   '<S1>/Gain4'
   */
  33.333333333333336,

  /* Variable: RserL
   * Referenced by:
   *   '<S4>/Iout2IL2'
   *   '<S5>/IL2Iout'
   */
  0.00878,

  /* Variable: TBPRD
   * Referenced by: '<S1>/Gain1'
   */
  7500.0,

  /* Variable: Tsw
   * Referenced by:
   *   '<S5>/Constant1'
   *   '<S7>/VL2duty'
   */
  0.0001,

  /* Variable: VLlim
   * Referenced by: '<S7>/Gain3'
   */
  0.5,

  /* Variable: VinNom
   * Referenced by:
   *   '<S1>/Bias4'
   *   '<S1>/Constant3'
   *   '<S1>/Gain'
   *   '<S1>/Gain5'
   *   '<S4>/Constant1'
   *   '<S4>/Constant3'
   *   '<S5>/Constant'
   */
  25.0,

  /* Variable: VoutMax
   * Referenced by:
   *   '<S1>/Gain'
   *   '<S1>/Gain5'
   */
  70.0,

  /* Variable: deadtimesw
   * Referenced by:
   *   '<S5>/Constant1'
   *   '<S7>/VL2duty'
   */
  2.8E-6,

  /* Variable: kaw_i
   * Referenced by: '<S7>/Gain2'
   */
  0.12915612411392344,

  /* Variable: kaw_v
   * Referenced by: '<S4>/Gain8'
   */
  156.75742330554746,

  /* Variable: ki_i
   * Referenced by: '<S7>/Gain'
   */
  8539.5037000758675,

  /* Variable: ki_v
   * Referenced by: '<S4>/Gain13'
   */
  41.029092978462266,

  /* Variable: kp_i
   * Referenced by: '<S7>/Gain1'
   */
  7.74256743039099,

  /* Variable: kp_v
   * Referenced by: '<S4>/Gain15'
   */
  0.26173620434223033,

  /* Variable: zden_Integrator
   * Referenced by:
   *   '<S4>/discrete integrator'
   *   '<S7>/discrete integrator'
   */
  { 1.0, -1.0 },

  /* Variable: zden_aaf
   * Referenced by:
   *   '<S3>/AAF TF'
   *   '<S3>/AAF TF1'
   */
  { 1.0, -0.93913827956629947, 0.35680037422523669 },

  /* Variable: zden_plant_i
   * Referenced by: '<S5>/Inductor TF1'
   */
  { 1.0, -0.99985952986685311 },

  /* Variable: zden_plant_v
   * Referenced by: '<S5>/Capacitor TF'
   */
  { 1.0, -1.0 },

  /* Variable: znum_Integrator
   * Referenced by:
   *   '<S4>/discrete integrator'
   *   '<S7>/discrete integrator'
   */
  { 5.0E-5, 5.0E-5 },

  /* Variable: znum_aaf
   * Referenced by:
   *   '<S3>/AAF TF'
   *   '<S3>/AAF TF1'
   */
  { -0.10441552366473428, -0.20883104732946856, -0.10441552366473428 },

  /* Variable: znum_plant_i
   * Referenced by: '<S5>/Inductor TF1'
   */
  { 0.0, 0.015998876212623834 },

  /* Variable: znum_plant_v
   * Referenced by: '<S5>/Capacitor TF'
   */
  { 0.060000000000000012, 0.040000000000000015 },

  /* Expression: 0
   * Referenced by: '<S5>/Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Inductor TF1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Memory3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Capacitor TF'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Memory3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Memory2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Memory3'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Communication Interface Delay'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S3>/Gain4'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S3>/AAF TF'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/discrete integrator'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Communication Interface Delay1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S3>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S3>/AAF TF1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/discrete integrator'
   */
  0.0
};
