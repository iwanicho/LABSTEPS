/*
 * ert_main.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Z_OL3".
 *
 * Model version              : 9.51
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Jan 16 12:51:50 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Z_OL3.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.0001;
  float systemClock = 150;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  HWI_TIC28x_EnablePeripheralInterrupt();
  c2000_flash_init();
  init_board();

#if defined(MW_EXEC_PROFILER_ON) || (defined(MW_EXTMODE_RUNNING) && !defined(XCP_TIMESTAMP_BASED_ON_SIMULATION_TIME))

  hardwareTimer1Init();

#endif

  ;
  rtmSetErrorStatus(Z_OL3_M, 0);
  Z_OL3_initialize();
  globalInterruptDisable();
  configureTimer0(modelBaseRate, systemClock);
  runModel =
    rtmGetErrorStatus(Z_OL3_M) == (NULL);
  enableTimer0Interrupt();
  config_ePWM_TBSync();
  Z_OL3_configure_interrupts();
  globalInterruptEnable();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(Z_OL3_M) == (NULL));
  }

  Z_OL3_unconfigure_interrupts();

  /* Terminate model */
  Z_OL3_terminate();
  HWI_TIC28x_DisablePeripheralInterrupt();
  globalInterruptDisable();
  return 0;
}
