/*
 * Header file for: HIL
 * Generated with : PLECS 4.8.9
 *                  PLECS RT Box 1 3.0.6
 * Generated on   : 4 Dec 2024 13:23:37
 */
#ifndef PLECS_HEADER_HIL_h_
#define PLECS_HEADER_HIL_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double HIL_FloatType;

/* Model checksum */
extern const char * const HIL_checksum;

/* Model error status */
extern const char * HIL_errorStatus;


/* Model sample time */
extern const double HIL_sampleTime;


/*
 * Model states */
typedef struct
{
   double HIL_PM0_x[4];             /* HIL */
   bool HIL_i1_PM0_s[6];            /* HIL */
   double AAF2;                     /* HIL/AAF2 */
   double AAF3;                     /* HIL/AAF3 */
   double AAF;                      /* HIL/AAF */
   double AAF1;                     /* HIL/AAF1 */
} HIL_ModelStates;
extern HIL_ModelStates HIL_X;


/* Block outputs */
typedef struct
{
   float PWMCapture3[2];            /* HIL/PWM Capture3 */
   float PWMCapture1[2];            /* HIL/PWM Capture1 */
   bool DataType1;                  /* HIL/Data Type1 */
   bool DataType;                   /* HIL/Data Type */
   float PWMCapture2[2];            /* HIL/PWM Capture2 */
   double AAF2;                     /* HIL/AAF2 */
   double AAF3;                     /* HIL/AAF3 */
} HIL_BlockOutputs;
extern HIL_BlockOutputs HIL_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define HIL_NumExtModeSignals 8
extern const double * const HIL_ExtModeSignals[];
/* Tunable parameters */
#define HIL_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void HIL_initialize(double time);
void HIL_step(void);
void HIL_terminate(void);

#endif /* PLECS_HEADER_HIL_h_ */
