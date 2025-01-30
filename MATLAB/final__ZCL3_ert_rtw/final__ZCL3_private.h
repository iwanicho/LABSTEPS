/*
 * final__ZCL3_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "final__ZCL3".
 *
 * Model version              : 9.48
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Fri Jan 17 13:13:55 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef final__ZCL3_private_h_
#define final__ZCL3_private_h_
#include "rtwtypes.h"
#include "final__ZCL3.h"
#include "final__ZCL3_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

void config_ADC_A(uint16_T maxconvReg , uint16_T adcChselSEQ1Reg, uint16_T
                  adcChselSEQ2Reg, uint16_T adcChselSEQ3Reg, uint16_T
                  adcChselSEQ4Reg);
extern uint16_T MW_adcInitFlag;
extern void final__ZCL3_VL2duty(real_T rtu_VLref, real_T rtu_Vin_fb, real_T
  rtu_Vout_fb, B_VL2duty_final__ZCL3_T *localB);

#endif                                 /* final__ZCL3_private_h_ */
