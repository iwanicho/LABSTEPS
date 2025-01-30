/*
 * Z_OL1_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_OL1".
 *
 * Model version              : 9.43
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Jan 16 12:41:38 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Z_OL1_private_h_
#define Z_OL1_private_h_
#include "rtwtypes.h"
#include "Z_OL1_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

void config_ADC_A(uint16_T maxconvReg , uint16_T adcChselSEQ1Reg, uint16_T
                  adcChselSEQ2Reg, uint16_T adcChselSEQ3Reg, uint16_T
                  adcChselSEQ4Reg);
extern uint16_T MW_adcInitFlag;

#endif                                 /* Z_OL1_private_h_ */
