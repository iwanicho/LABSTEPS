/*
 * Header file for: HIL
 * Generated with : PLECS 4.8.9
 *                  PLECS RT Box 1 3.0.6
 * Generated on   : 8 Jan 2025 17:45:17
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
   double AAFCurrentV[2];           /* HIL/AAF currentV */
   double AAFVoltage[2];            /* HIL/AAF voltage */
   double AAFCurrentU[2];           /* HIL/AAF currentU */
   double AAFCurrentW[2];           /* HIL/AAF currentW */
} HIL_ModelStates;
extern HIL_ModelStates HIL_X;


/* Block outputs */
typedef struct
{
   double maxMeasCurrentV;          /* HIL/maxMeas currentV */
   double maxMeasVoltage;           /* HIL/maxMeas voltage */
   double maxMeasCurrentU;          /* HIL/maxMeas currentU */
   double maxMeasCurrentW;          /* HIL/maxMeas currentW */
   double Vnoise;                   /* HIL/Vnoise */
   float fromEPWM3[2];              /* HIL/from ePWM3 */
   bool DataType2;                  /* HIL/Data Type2 */
   bool DataType3;                  /* HIL/Data Type3 */
   float fromEPWM2[2];              /* HIL/from ePWM2 */
   bool DataType1;                  /* HIL/Data Type1 */
   float fromEPWM6[2];              /* HIL/from ePWM6 */
   bool DataType5;                  /* HIL/Data Type5 */
   double AAFCurrentV;              /* HIL/AAF currentV */
   double AAFVoltage;               /* HIL/AAF voltage */
} HIL_BlockOutputs;
extern HIL_BlockOutputs HIL_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define HIL_NumExtModeSignals 17
extern const double * const HIL_ExtModeSignals[];
/* Tunable parameters */
#define HIL_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void HIL_initialize(double time);
void HIL_step(void);
void HIL_terminate(void);

#endif /* PLECS_HEADER_HIL_h_ */
