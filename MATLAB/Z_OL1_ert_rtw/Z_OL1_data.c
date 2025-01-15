/*
 * Z_OL1_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_OL1".
 *
 * Model version              : 9.41
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Wed Jan 15 09:51:04 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Z_OL1.h"

/* Block parameters (default storage) */
P_Z_OL1_T Z_OL1_P = {
  /* Variable: ADC_mapping
   * Referenced by:
   *   '<S1>/Gain10'
   *   '<S1>/Gain11'
   */
  4095.0,

  /* Variable: IoutNom
   * Referenced by: '<S1>/MATLAB Function'
   */
  1.5,

  /* Variable: RserL
   * Referenced by: '<S1>/MATLAB Function'
   */
  0.5,

  /* Variable: TBPRD
   * Referenced by: '<S1>/Gain1'
   */
  7500.0,

  /* Variable: VfbMax
   * Referenced by: '<S1>/Gain12'
   */
  750.0,

  /* Variable: VinNom
   * Referenced by: '<S1>/MATLAB Function'
   */
  30.0,

  /* Variable: VoutNom
   * Referenced by: '<S1>/Constant2'
   */
  50.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Gain'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Gain4'
   */
  1000.0
};
