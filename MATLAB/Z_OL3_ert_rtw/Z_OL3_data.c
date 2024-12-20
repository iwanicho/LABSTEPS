/*
 * Z_OL3_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_OL3".
 *
 * Model version              : 9.21
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Wed Dec  4 19:44:34 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Z_OL3.h"

/* Block parameters (default storage) */
P_Z_OL3_T Z_OL3_P = {
  /* Variable: ADC_mapping
   * Referenced by:
   *   '<S1>/Gain2'
   *   '<S1>/Gain3'
   *   '<S1>/Gain6'
   *   '<S1>/Saturation'
   */
  4095.0,

  /* Variable: IoutNom
   * Referenced by: '<S1>/MATLAB Function'
   */
  1.5,

  /* Variable: Rload
   * Referenced by:
   *   '<S1>/Bias3'
   *   '<S1>/Gain4'
   */
  33.333333333333336,

  /* Variable: RserL
   * Referenced by:
   *   '<S1>/MATLAB Function'
   *   '<S4>/IL2Iout'
   */
  0.00878,

  /* Variable: TBPRD
   * Referenced by: '<S1>/Gain1'
   */
  7500.0,

  /* Variable: Tsw
   * Referenced by:
   *   '<S1>/MATLAB Function'
   *   '<S4>/Constant1'
   */
  0.0001,

  /* Variable: VinNom
   * Referenced by:
   *   '<S1>/MATLAB Function'
   *   '<S1>/Bias1'
   *   '<S1>/Bias4'
   *   '<S1>/Gain'
   *   '<S1>/Gain5'
   *   '<S4>/Constant'
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
   *   '<S1>/MATLAB Function'
   *   '<S4>/Constant1'
   */
  2.8E-6,

  /* Variable: zden_plant_i
   * Referenced by:
   *   '<S4>/Inductor TF1'
   *   '<S4>/Inductor TF2'
   *   '<S4>/Inductor TF3'
   */
  { 1.0, -0.99985952986685311 },

  /* Variable: zden_plant_v
   * Referenced by: '<S4>/Capacitor TF'
   */
  { 1.0, -1.0 },

  /* Variable: znum_plant_i
   * Referenced by:
   *   '<S4>/Inductor TF1'
   *   '<S4>/Inductor TF2'
   *   '<S4>/Inductor TF3'
   */
  { 0.0, 0.015998876212623834 },

  /* Variable: znum_plant_v
   * Referenced by: '<S4>/Capacitor TF'
   */
  { 0.060000000000000012, 0.040000000000000015 },

  /* Expression: 0
   * Referenced by: '<S4>/Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Inductor TF1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Inductor TF2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Inductor TF3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Memory3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Capacitor TF'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Saturation'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain7'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Bias'
   */
  1.0
};
