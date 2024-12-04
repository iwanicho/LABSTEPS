/*
 * Implementation file for: HIL
 * Generated with         : PLECS 4.8.9
 *                          PLECS RT Box 1 3.0.6
 * Generated on           : 4 Dec 2024 13:23:37
 */
#include "HIL.h"
#ifndef PLECS_HEADER_HIL_h_
#error The wrong header file "HIL.h" was included. Please check your
#error include path to see whether this file name conflicts with the name
#error of another header file.
#endif /* PLECS_HEADER_HIL_h_ */
#if defined(__GNUC__) && (__GNUC__ > 4)
#   define _ALIGNMENT 16
#   define _RESTRICT __restrict
#   define _ALIGN __attribute__((aligned(_ALIGNMENT)))
#   if defined(__clang__)
#      if __has_builtin(__builtin_assume_aligned)
#         define _ASSUME_ALIGNED(a) __builtin_assume_aligned(a, _ALIGNMENT)
#      else
#         define _ASSUME_ALIGNED(a) a
#      endif
#   else
#      define _ASSUME_ALIGNED(a) __builtin_assume_aligned(a, _ALIGNMENT)
#   endif
#else
#   ifndef _RESTRICT
#      define _RESTRICT
#   endif
#   ifndef _ALIGN
#      define _ALIGN
#   endif
#   ifndef _ASSUME_ALIGNED
#      define _ASSUME_ALIGNED(a) a
#   endif
#endif
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "plexim/DigitalIn.h"
#include "plexim/AnalogOut.h"
#include "plexim/hw_wrapper.h"
#include "plexim/DigitalOut.h"
#include "plexim/AnalogIn.h"
#include "plexim/SFP.h"
#include "plexim/HIL_Framework.h"
#include "plexim/DigitalOverride.h"
#include "plexim/DataCapture.h"
#include "plexim/ProgrammableValue.h"
#include "plexim/ToFile.h"
#define PLECSRunTimeError(msg) HIL_errorStatus = msg
#define HIL_UNCONNECTED 0
static int HIL_D_int[3];
static size_t HIL_D_size_t[3];
static double * _RESTRICT HIL_PM0_x;
static double HIL_PM0_tmpX[4] _ALIGN;
static double HIL_PM0_prevX[4] _ALIGN;
static double HIL_PM0_u[1] _ALIGN;
static double HIL_PM0_prevU[1] _ALIGN;
static double HIL_PM0_y[4] _ALIGN;
static double HIL_PM0_gateSignalBuffer[6] _ALIGN;
static size_t HIL_PM0_topoIdx;
static char HIL_PM0_withDiracs;
static const size_t PM0_Ad_0_rowPtr[] = {
   0,2,3,4,5
};
static const size_t PM0_Ad_0_colIdx[] = {
   1,2,1,2,3
};
static const double PM0_Ad_0_data[] _ALIGN = {
   -0.995123042277094694,-0.995123042277094694,0.995123042277094694,
   0.995123042277094694,0.835541599035716676
};
static const size_t PM0_Bd0_0_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_Bd0_0_colIdx[] = {
   0
};
static const double PM0_Bd0_0_data[] _ALIGN = {
   0
};
static const size_t PM0_Bd1_0_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_Bd1_0_colIdx[] = {
   0
};
static const double PM0_Bd1_0_data[] _ALIGN = {
   0
};
static const size_t PM0_C_0_0_rowPtr[] = {
   0,2,3,4,5
};
static const size_t PM0_C_0_0_colIdx[] = {
   1,2,1,2,3
};
static const double PM0_C_0_0_data[] _ALIGN = {
   -1.,-1.,1.,1.,0.998203248526663756
};
static const size_t PM0_D_0_0_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_0_colIdx[] = {
   0
};
static const double PM0_D_0_0_data[] _ALIGN = {
   0
};
static void PM0_collision_0()
{
   double * _RESTRICT x = HIL_PM0_x;
   double * _RESTRICT tmpX = HIL_PM0_tmpX;
   tmpX[0] = 0.66666666666666663*x[0]-0.333333333333333315*x[1]-
             0.333333333333333315*x[2];
   tmpX[1] = -0.333333333333333315*x[0]+0.66666666666666663*x[1]-
             0.333333333333333315*x[2];
   tmpX[2] = -0.333333333333333315*x[0]-0.333333333333333315*x[1]+
             0.66666666666666663*x[2];
   x[0] = tmpX[0];
   x[1] = tmpX[1];
   x[2] = tmpX[2];
}
static size_t PM0_natPreComm_0_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   return 0; /* 0_0 */
}
static size_t PM0_natPostComm_0_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (!HIL_PM0_gateSignalBuffer[0])
   {
      if (-x[3]+1.00179998560011496*u[0] > 0)
      {
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
            {
               return 1; /* 2_0 */
            }
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
            {
               return 1; /* 2_0 */
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-u[0] > 0)
         {
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
            {
               return 2; /* 4_0 */
            }
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
            {
               return 2; /* 4_0 */
            }
         }
      }
   }
   if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
   {
      if (-x[3]+1.00179998560011496*u[0] > 0)
      {
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 1; /* 2_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 1; /* 2_0 */
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-u[0] > 0)
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 2; /* 4_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 2; /* 4_0 */
            }
         }
      }
   }
   if (-x[3] > 0)
   {
      return 15; /* 63_0 */
   }
   return 0; /* 0_0 */
}
static size_t PM0_forcedComm_0_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond1 = !HIL_PM0_gateSignalBuffer[1];
      if (cond1)
      {
         {
            const char cond2 = !HIL_PM0_gateSignalBuffer[2];
            if (cond2)
            {
               {
                  const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                  if (cond0)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[3];
                        if (cond3)
                        {
                           {
                              const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                              if (cond4)
                              {
                                 if (!HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 0; /* 0_0 */
                                 }
                              }
                              else if (!cond4)
                              {
                                 return 0; /* 0_0 */
                              }
                              if (HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 0; /* 0_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 0; /* 0_0 */
                           }
                           else
                           {
                              return 4; /* 24_0 */
                           }
                        }
                        {
                           const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                           if (cond4)
                           {
                              if (HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 0; /* 0_0 */
                              }
                           }
                           else if (!cond4)
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 4; /* 24_0 */
                              }
                           }
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[4])
                                 {
                                    return 4; /* 24_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
                  else if (!cond0)
                  {
                     {
                        const char cond5 = !HIL_PM0_gateSignalBuffer[5];
                        if (cond5)
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 0; /* 0_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 0; /* 0_0 */
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 4; /* 24_0 */
                              }
                           }
                        }
                        else if (!cond5)
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 8; /* 33_0 */
                           }
                           else
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 12; /* 57_0 */
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 12; /* 57_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 8; /* 33_0 */
                           }
                           else
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 12; /* 57_0 */
                              }
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 12; /* 57_0 */
                              }
                           }
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 8; /* 33_0 */
                           }
                           else
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 12; /* 57_0 */
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 12; /* 57_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 8; /* 33_0 */
                           }
                           else
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 12; /* 57_0 */
                              }
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 12; /* 57_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond3)
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 0; /* 0_0 */
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 8; /* 33_0 */
                              }
                           }
                        }
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              return 8; /* 33_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        {
                           const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                           if (cond4)
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 0; /* 0_0 */
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 8; /* 33_0 */
                                 }
                              }
                           }
                           else if (!cond4)
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 4; /* 24_0 */
                              }
                              else
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 12; /* 57_0 */
                                 }
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 12; /* 57_0 */
                                 }
                              }
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 4; /* 24_0 */
                              }
                              else
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 12; /* 57_0 */
                                 }
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 12; /* 57_0 */
                                 }
                              }
                           }
                        }
                     }
                     {
                        const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond4)
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 8; /* 33_0 */
                              }
                           }
                        }
                        else if (!cond4)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 4; /* 24_0 */
                              }
                              else
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 12; /* 57_0 */
                                 }
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 12; /* 57_0 */
                                 }
                              }
                           }
                        }
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 12; /* 57_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
            else if (!cond2)
            {
               {
                  const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                  if (cond0)
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 2; /* 4_0 */
                     }
                     else
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           return 6; /* 28_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 2; /* 4_0 */
                     }
                     else
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                  }
                  else if (!cond0)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[3];
                        if (cond3)
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 10; /* 37_0 */
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                        else if (!cond3)
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              if (HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              if (HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                        {
                           const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                           if (cond4)
                           {
                              if (HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 10; /* 37_0 */
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 10; /* 37_0 */
                              }
                           }
                           else if (!cond4)
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 14; /* 61_0 */
                                 }
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 if (HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 14; /* 61_0 */
                                 }
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond5 = !HIL_PM0_gateSignalBuffer[5];
                     if (cond5)
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 2; /* 4_0 */
                        }
                        else
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 6; /* 28_0 */
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 2; /* 4_0 */
                        }
                        else
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                     else if (!cond5)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 10; /* 37_0 */
                           }
                           else
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 10; /* 37_0 */
                           }
                           else
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 10; /* 37_0 */
                           }
                           else
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 10; /* 37_0 */
                           }
                           else
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
            {
               {
                  const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                  if (cond0)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[3];
                        if (cond3)
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 2; /* 4_0 */
                           }
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 2; /* 4_0 */
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 2; /* 4_0 */
                           }
                           else
                           {
                              return 6; /* 28_0 */
                           }
                        }
                        {
                           const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                           if (cond4)
                           {
                              if (HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 2; /* 4_0 */
                              }
                           }
                           else if (!cond4)
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 6; /* 28_0 */
                              }
                           }
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[4])
                                 {
                                    return 6; /* 28_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
                  else if (!cond0)
                  {
                     {
                        const char cond5 = !HIL_PM0_gateSignalBuffer[5];
                        if (cond5)
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 2; /* 4_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 2; /* 4_0 */
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 6; /* 28_0 */
                              }
                           }
                        }
                        else if (!cond5)
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 10; /* 37_0 */
                           }
                           else
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 10; /* 37_0 */
                           }
                           else
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 10; /* 37_0 */
                           }
                           else
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 10; /* 37_0 */
                           }
                           else
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond3)
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 2; /* 4_0 */
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 10; /* 37_0 */
                              }
                           }
                        }
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        {
                           const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                           if (cond4)
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 2; /* 4_0 */
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 10; /* 37_0 */
                                 }
                              }
                           }
                           else if (!cond4)
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 6; /* 28_0 */
                              }
                              else
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 6; /* 28_0 */
                              }
                              else
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                     }
                     {
                        const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond4)
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 10; /* 37_0 */
                              }
                           }
                        }
                        else if (!cond4)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 6; /* 28_0 */
                              }
                              else
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      else if (!cond1)
      {
         {
            const char cond2 = !HIL_PM0_gateSignalBuffer[2];
            if (cond2)
            {
               {
                  const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                  if (cond0)
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 1; /* 2_0 */
                     }
                     else
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           return 5; /* 26_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 1; /* 2_0 */
                     }
                     else
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                  }
                  else if (!cond0)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[3];
                        if (cond3)
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 9; /* 35_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                        else if (!cond3)
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              if (HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                        {
                           const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                           if (cond4)
                           {
                              if (HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 9; /* 35_0 */
                              }
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 9; /* 35_0 */
                              }
                           }
                           else if (!cond4)
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 13; /* 59_0 */
                                 }
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 if (HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 13; /* 59_0 */
                                 }
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond5 = !HIL_PM0_gateSignalBuffer[5];
                     if (cond5)
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 1; /* 2_0 */
                        }
                        else
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 5; /* 26_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 1; /* 2_0 */
                        }
                        else
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                     }
                     else if (!cond5)
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 9; /* 35_0 */
                           }
                           else
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 9; /* 35_0 */
                           }
                           else
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 9; /* 35_0 */
                           }
                           else
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 9; /* 35_0 */
                           }
                           else
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
            else if (!cond2)
            {
               {
                  const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                  if (cond0)
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 3; /* 6_0 */
                     }
                     else
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 3; /* 6_0 */
                     }
                     else
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  else if (!cond0)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[3];
                        if (cond3)
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 11; /* 39_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                        else if (!cond3)
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              if (HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                        {
                           const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                           if (cond4)
                           {
                              if (HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 11; /* 39_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                           else if (!cond4)
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 15; /* 63_0 */
                                 }
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 if (HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 15; /* 63_0 */
                                 }
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond5 = !HIL_PM0_gateSignalBuffer[5];
                     if (cond5)
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 3; /* 6_0 */
                        }
                        else
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 3; /* 6_0 */
                        }
                        else
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                     else if (!cond5)
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           else
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                           else
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           else
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                           else
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
            {
               const char cond0 = !HIL_PM0_gateSignalBuffer[0];
               if (cond0)
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (HIL_PM0_gateSignalBuffer[3])
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
               else if (!cond0)
               {
                  if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (HIL_PM0_gateSignalBuffer[3])
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
               {
                  const char cond5 = !HIL_PM0_gateSignalBuffer[5];
                  if (cond5)
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (HIL_PM0_gateSignalBuffer[3])
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 3; /* 6_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  else if (!cond5)
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (HIL_PM0_gateSignalBuffer[3])
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (HIL_PM0_gateSignalBuffer[3])
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      {
         const char cond2 = !HIL_PM0_gateSignalBuffer[2];
         if (cond2)
         {
            if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               {
                  const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                  if (cond0)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[3];
                        if (cond3)
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 1; /* 2_0 */
                           }
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 1; /* 2_0 */
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 1; /* 2_0 */
                           }
                           else
                           {
                              return 5; /* 26_0 */
                           }
                        }
                        {
                           const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                           if (cond4)
                           {
                              if (HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 1; /* 2_0 */
                              }
                           }
                           else if (!cond4)
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 5; /* 26_0 */
                              }
                           }
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[4])
                                 {
                                    return 5; /* 26_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
                  else if (!cond0)
                  {
                     {
                        const char cond5 = !HIL_PM0_gateSignalBuffer[5];
                        if (cond5)
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 1; /* 2_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 1; /* 2_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 5; /* 26_0 */
                              }
                           }
                        }
                        else if (!cond5)
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 9; /* 35_0 */
                           }
                           else
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 9; /* 35_0 */
                           }
                           else
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 9; /* 35_0 */
                           }
                           else
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 9; /* 35_0 */
                           }
                           else
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond3)
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 1; /* 2_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 9; /* 35_0 */
                              }
                           }
                        }
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        {
                           const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                           if (cond4)
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 1; /* 2_0 */
                              }
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 9; /* 35_0 */
                                 }
                              }
                           }
                           else if (!cond4)
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 5; /* 26_0 */
                              }
                              else
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 5; /* 26_0 */
                              }
                              else
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                     }
                     {
                        const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond4)
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 9; /* 35_0 */
                              }
                           }
                        }
                        else if (!cond4)
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 5; /* 26_0 */
                              }
                              else
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
         else if (!cond2)
         {
            {
               const char cond0 = !HIL_PM0_gateSignalBuffer[0];
               if (cond0)
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (HIL_PM0_gateSignalBuffer[3])
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
               else if (!cond0)
               {
                  if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (HIL_PM0_gateSignalBuffer[3])
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
               {
                  const char cond5 = !HIL_PM0_gateSignalBuffer[5];
                  if (cond5)
                  {
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (HIL_PM0_gateSignalBuffer[3])
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 3; /* 6_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  else if (!cond5)
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (HIL_PM0_gateSignalBuffer[3])
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (HIL_PM0_gateSignalBuffer[3])
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
         {
            const char cond0 = !HIL_PM0_gateSignalBuffer[0];
            if (cond0)
            {
               {
                  const char cond3 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond3)
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 3; /* 6_0 */
                           }
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 3; /* 6_0 */
                           }
                        }
                     }
                  }
                  else if (!cond3)
                  {
                     {
                        const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond4)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 3; /* 6_0 */
                              }
                           }
                        }
                        else if (!cond4)
                        {
                           if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                                  0 || HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond4)
                     {
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 3; /* 6_0 */
                              }
                           }
                        }
                     }
                     else if (!cond4)
                     {
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                     }
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[4])
                                 {
                                    return 7; /* 30_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
            else if (!cond0)
            {
               {
                  const char cond5 = !HIL_PM0_gateSignalBuffer[5];
                  if (cond5)
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 3; /* 6_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 3; /* 6_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                     }
                  }
                  else if (!cond5)
                  {
                     if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (HIL_PM0_gateSignalBuffer[3])
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (HIL_PM0_gateSignalBuffer[3])
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
               }
            }
            {
               const char cond3 = !HIL_PM0_gateSignalBuffer[3];
               if (cond3)
               {
                  if (HIL_PM0_gateSignalBuffer[4])
                  {
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 3; /* 6_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                     }
                  }
                  if (HIL_PM0_gateSignalBuffer[5])
                  {
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
               }
               else if (!cond3)
               {
                  {
                     const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond4)
                     {
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 3; /* 6_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 11; /* 39_0 */
                                 }
                              }
                           }
                        }
                     }
                     else if (!cond4)
                     {
                        {
                           const char cond5 = !HIL_PM0_gateSignalBuffer[5];
                           if (cond5)
                           {
                              if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-66.6666666666666572*
                                     x[3] >= 0 || HIL_PM0_gateSignalBuffer[2])
                                 {
                                    return 7; /* 30_0 */
                                 }
                              }
                           }
                           else if (!cond5)
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                        HIL_PM0_gateSignalBuffer[0])
                                    {
                                       return 15; /* 63_0 */
                                    }
                                 }
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                        HIL_PM0_gateSignalBuffer[0])
                                    {
                                       return 15; /* 63_0 */
                                    }
                                 }
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        {
                           const char cond5 = !HIL_PM0_gateSignalBuffer[5];
                           if (cond5)
                           {
                              if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-66.6666666666666572*
                                     x[3] >= 0 || HIL_PM0_gateSignalBuffer[2])
                                 {
                                    return 7; /* 30_0 */
                                 }
                              }
                           }
                           else if (!cond5)
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                        HIL_PM0_gateSignalBuffer[0])
                                    {
                                       return 15; /* 63_0 */
                                    }
                                 }
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                        HIL_PM0_gateSignalBuffer[0])
                                    {
                                       return 15; /* 63_0 */
                                    }
                                 }
                              }
                           }
                        }
                     }
                  }
               }
               {
                  const char cond4 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond4)
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                     }
                  }
                  else if (!cond4)
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        {
                           const char cond5 = !HIL_PM0_gateSignalBuffer[5];
                           if (cond5)
                           {
                              if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-66.6666666666666572*
                                     x[3] >= 0 || HIL_PM0_gateSignalBuffer[2])
                                 {
                                    return 7; /* 30_0 */
                                 }
                              }
                           }
                           else if (!cond5)
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                        HIL_PM0_gateSignalBuffer[0])
                                    {
                                       return 15; /* 63_0 */
                                    }
                                 }
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                        HIL_PM0_gateSignalBuffer[0])
                                    {
                                       return 15; /* 63_0 */
                                    }
                                 }
                              }
                           }
                        }
                     }
                  }
                  if (HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 0_0";
   return 0; /* 0_0 */
}
static const size_t PM0_Ad_2_rowPtr[] = {
   0,4,8,12,16
};
static const size_t PM0_Ad_2_colIdx[] = {
   0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3
};
static const double PM0_Ad_2_data[] _ALIGN = {
   0.765878552999754936,-0.229244489277339675,-0.229244489277339675,
   -0.373993367076083938,-0.229244489277339675,0.765878552999754936,
   -0.229244489277339675,-0.373993367076083938,-0.229244489277339675,
   -0.229244489277339675,0.765878552999754936,-0.373993367076083938,
   0.673188060736951033,0.673188060736951033,0.673188060736951033,
   0.200733559545571316
};
static const size_t PM0_Bd0_2_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_Bd0_2_colIdx[] = {
   0,0,0,0
};
static const double PM0_Bd0_2_data[] _ALIGN = {
   0.174401471990244666,0.174401471990244666,0.174401471990244666,
   0.434227910225040592
};
static const size_t PM0_Bd1_2_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_Bd1_2_colIdx[] = {
   0,0,0,0
};
static const double PM0_Bd1_2_data[] _ALIGN = {
   0.240928895489102374,0.240928895489102374,0.240928895489102374,
   0.243507807083782946
};
static const size_t PM0_C_0_2_rowPtr[] = {
   0,1,2,3,7
};
static const size_t PM0_C_0_2_colIdx[] = {
   0,1,2,0,1,2,3
};
static const double PM0_C_0_2_data[] _ALIGN = {
   1.,1.,1.,0.00998203248526663769,0.00998203248526663769,
   0.00998203248526663769,0.998203248526663756
};
static const size_t PM0_D_0_2_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_2_colIdx[] = {
   0
};
static const double PM0_D_0_2_data[] _ALIGN = {
   0
};
static void PM0_collision_2()
{
}
static size_t PM0_natPreComm_2_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (-x[0]-x[1]-x[2] >= 0 && !HIL_PM0_gateSignalBuffer[1])
   {
      if (x[0]+x[1]+x[2]+100.*x[3] >= 0)
      {
         return 0; /* 0_0 */
      }
   }
   return 1; /* 2_0 */
}
static size_t PM0_natPostComm_2_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (!HIL_PM0_gateSignalBuffer[0])
   {
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2] > 0)
         {
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
            {
               return 2; /* 4_0 */
            }
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
            {
               return 2; /* 4_0 */
            }
         }
      }
      if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
      {
         if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 3; /* 6_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 3; /* 6_0 */
            }
         }
      }
      if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0)
      {
         if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
         {
            if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               return 7; /* 30_0 */
            }
         }
      }
   }
   if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
   {
      if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0)
      {
         if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 11; /* 39_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 11; /* 39_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               return 7; /* 30_0 */
            }
         }
      }
      if (-x[0]-x[1]-x[2]-50.*x[3] > 0)
      {
         if (x[0]+x[1]+x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            return 15; /* 63_0 */
         }
      }
   }
   if (!HIL_PM0_gateSignalBuffer[1])
   {
      if (-x[0]-x[1]-x[2] > 0)
      {
         if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 2; /* 4_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 2; /* 4_0 */
            }
         }
         if (-x[3] > 0)
         {
            return 14; /* 61_0 */
         }
      }
   }
   if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
   {
      if (!HIL_PM0_gateSignalBuffer[5])
      {
         if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 3; /* 6_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 3; /* 6_0 */
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[2])
      {
         if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            return 13; /* 59_0 */
         }
      }
   }
   return 1; /* 2_0 */
}
static size_t PM0_forcedComm_2_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond1 = !HIL_PM0_gateSignalBuffer[2];
      if (cond1)
      {
         if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            {
               const char cond0 = !HIL_PM0_gateSignalBuffer[0];
               if (cond0)
               {
                  {
                     const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond2)
                     {
                        {
                           const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                           if (cond3)
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 1; /* 2_0 */
                              }
                           }
                           else if (!cond3)
                           {
                              return 1; /* 2_0 */
                           }
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 1; /* 2_0 */
                           }
                        }
                     }
                     else if (!cond2)
                     {
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 1; /* 2_0 */
                        }
                        else
                        {
                           return 5; /* 26_0 */
                        }
                     }
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 1; /* 2_0 */
                           }
                        }
                        else if (!cond3)
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 5; /* 26_0 */
                              }
                           }
                        }
                     }
                  }
               }
               else if (!cond0)
               {
                  {
                     const char cond4 = !HIL_PM0_gateSignalBuffer[5];
                     if (cond4)
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 1; /* 2_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 1; /* 2_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                     }
                     else if (!cond4)
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        else
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                        else
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        else
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                        else
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
               }
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 1; /* 2_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 1; /* 2_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 9; /* 35_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 5; /* 26_0 */
                           }
                           else
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 5; /* 26_0 */
                           }
                           else
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 5; /* 26_0 */
                           }
                           else
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      else if (!cond1)
      {
         {
            const char cond0 = !HIL_PM0_gateSignalBuffer[0];
            if (cond0)
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        return 2; /* 4_0 */
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        return 3; /* 6_0 */
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           return 6; /* 28_0 */
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           return 2; /* 4_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
               }
            }
            else if (!cond0)
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           return 10; /* 37_0 */
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (!HIL_PM0_gateSignalBuffer[1])
                           {
                              return 14; /* 61_0 */
                           }
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (!HIL_PM0_gateSignalBuffer[1])
                           {
                              return 10; /* 37_0 */
                           }
                           if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (!HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
            {
               const char cond4 = !HIL_PM0_gateSignalBuffer[5];
               if (cond4)
               {
                  {
                     const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond2)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           return 2; /* 4_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                     else if (!cond2)
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[1])
                           {
                              return 6; /* 28_0 */
                           }
                           if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[1])
                           {
                              return 2; /* 4_0 */
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                           {
                              return 3; /* 6_0 */
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 6; /* 28_0 */
                              }
                           }
                           if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 6; /* 28_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                     }
                  }
               }
               else if (!cond4)
               {
                  {
                     const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond2)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                     else if (!cond2)
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 10; /* 37_0 */
                              }
                           }
                           if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 10; /* 37_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      {
         const char cond0 = !HIL_PM0_gateSignalBuffer[0];
         if (cond0)
         {
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[3];
               if (cond2)
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           return 3; /* 6_0 */
                        }
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        return 2; /* 4_0 */
                     }
                  }
               }
               else if (!cond2)
               {
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 3; /* 6_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
               }
               {
                  const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond3)
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 3; /* 6_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 2; /* 4_0 */
                        }
                     }
                  }
                  else if (!cond3)
                  {
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
                  if (HIL_PM0_gateSignalBuffer[5])
                  {
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
         else if (!cond0)
         {
            {
               const char cond4 = !HIL_PM0_gateSignalBuffer[5];
               if (cond4)
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 3; /* 6_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
               }
               else if (!cond4)
               {
                  {
                     const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond2)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                     else if (!cond2)
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 10; /* 37_0 */
                              }
                           }
                           if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                                  0 || HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[3])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[4])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 10; /* 37_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
         {
            const char cond4 = !HIL_PM0_gateSignalBuffer[5];
            if (cond4)
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 3; /* 6_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 2; /* 4_0 */
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 3; /* 6_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 6; /* 28_0 */
                              }
                           }
                           if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                                  0 || HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 6; /* 28_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 2; /* 4_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 6; /* 28_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 6; /* 28_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
            else if (!cond4)
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 10; /* 37_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[3];
               if (cond2)
               {
                  if (HIL_PM0_gateSignalBuffer[4])
                  {
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                  }
               }
               else if (!cond2)
               {
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 11; /* 39_0 */
                                 }
                              }
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
               {
                  const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond3)
                  {
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 10; /* 37_0 */
                              }
                           }
                        }
                     }
                  }
                  else if (!cond3)
                  {
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 14; /* 61_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 2_0";
   return 1; /* 2_0 */
}
static const size_t PM0_Ad_4_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_Ad_4_colIdx[] = {
   0,1,2,3
};
static const double PM0_Ad_4_data[] _ALIGN = {
   0.995123042277094694,0.995123042277094694,0.995123042277094694,
   0.835541599035716676
};
static const size_t PM0_Bd0_4_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd0_4_colIdx[] = {
   0,0,0
};
static const double PM0_Bd0_4_data[] _ALIGN = {
   0.276874085629755518,0.276874085629755518,0.276874085629755518
};
static const size_t PM0_Bd1_4_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd1_4_colIdx[] = {
   0,0,0
};
static const double PM0_Bd1_4_data[] _ALIGN = {
   0.277325655609487021,0.277325655609487021,0.277325655609487021
};
static const size_t PM0_C_0_4_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_C_0_4_colIdx[] = {
   0,1,2,3
};
static const double PM0_C_0_4_data[] _ALIGN = {
   1.,1.,1.,0.998203248526663756
};
static const size_t PM0_D_0_4_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_4_colIdx[] = {
   0
};
static const double PM0_D_0_4_data[] _ALIGN = {
   0
};
static void PM0_collision_4()
{
}
static size_t PM0_natPreComm_4_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (x[0]+x[1]+x[2] >= 0 && !HIL_PM0_gateSignalBuffer[2])
   {
      if (x[3] >= 0)
      {
         return 0; /* 0_0 */
      }
   }
   return 2; /* 4_0 */
}
static size_t PM0_natPostComm_4_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (!HIL_PM0_gateSignalBuffer[0])
   {
      if (x[0]+x[1]+x[2] > 0)
      {
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (x[0]+x[1]+x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
            {
               return 1; /* 2_0 */
            }
            if (x[0]+x[1]+x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
            {
               return 1; /* 2_0 */
            }
         }
      }
      if (-x[3] > 0)
      {
         if (-x[0]-x[1]-x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 3; /* 6_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 3; /* 6_0 */
            }
         }
      }
      if (x[0]+x[1]+x[2]-200.*x[3] > 0)
      {
         if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
         {
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                HIL_PM0_gateSignalBuffer[2])
            {
               return 7; /* 30_0 */
            }
         }
      }
   }
   if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
   {
      if (x[0]+x[1]+x[2]-200.*x[3] > 0)
      {
         if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
             HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 11; /* 39_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 11; /* 39_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               return 7; /* 30_0 */
            }
         }
      }
      if (x[0]+x[1]+x[2]-100.*x[3] > 0)
      {
         if (-x[0]-x[1]-x[2]-50.*x[3] > 0 || HIL_PM0_gateSignalBuffer[2])
         {
            return 15; /* 63_0 */
         }
      }
   }
   if (x[0]+x[1]+x[2] > 0)
   {
      if (!HIL_PM0_gateSignalBuffer[2])
      {
         if (x[0]+x[1]+x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 1; /* 2_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 1; /* 2_0 */
            }
         }
         if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
         {
            return 13; /* 59_0 */
         }
      }
   }
   if (-x[3] > 0)
   {
      if (!HIL_PM0_gateSignalBuffer[5])
      {
         if (-x[0]-x[1]-x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 3; /* 6_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 3; /* 6_0 */
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
         {
            return 14; /* 61_0 */
         }
      }
   }
   return 2; /* 4_0 */
}
static size_t PM0_forcedComm_4_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond1 = !HIL_PM0_gateSignalBuffer[1];
      if (cond1)
      {
         if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
         {
            {
               const char cond0 = !HIL_PM0_gateSignalBuffer[0];
               if (cond0)
               {
                  {
                     const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond2)
                     {
                        {
                           const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                           if (cond3)
                           {
                              if (!HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 2; /* 4_0 */
                              }
                           }
                           else if (!cond3)
                           {
                              return 2; /* 4_0 */
                           }
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 2; /* 4_0 */
                           }
                        }
                     }
                     else if (!cond2)
                     {
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 2; /* 4_0 */
                        }
                        else
                        {
                           return 6; /* 28_0 */
                        }
                     }
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 2; /* 4_0 */
                           }
                        }
                        else if (!cond3)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 6; /* 28_0 */
                              }
                           }
                        }
                     }
                  }
               }
               else if (!cond0)
               {
                  {
                     const char cond4 = !HIL_PM0_gateSignalBuffer[5];
                     if (cond4)
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 2; /* 4_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 2; /* 4_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                     else if (!cond4)
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        else
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                        else
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        else
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                        else
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
               }
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 2; /* 4_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 2; /* 4_0 */
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 10; /* 37_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 6; /* 28_0 */
                           }
                           else
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 6; /* 28_0 */
                           }
                           else
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 6; /* 28_0 */
                           }
                           else
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      else if (!cond1)
      {
         {
            const char cond0 = !HIL_PM0_gateSignalBuffer[0];
            if (cond0)
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        return 1; /* 2_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        return 3; /* 6_0 */
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           return 5; /* 26_0 */
                        }
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           return 1; /* 2_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
               }
            }
            else if (!cond0)
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           return 9; /* 35_0 */
                        }
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (!HIL_PM0_gateSignalBuffer[2])
                           {
                              return 13; /* 59_0 */
                           }
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (!HIL_PM0_gateSignalBuffer[2])
                           {
                              return 9; /* 35_0 */
                           }
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           if (!HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
            {
               const char cond4 = !HIL_PM0_gateSignalBuffer[5];
               if (cond4)
               {
                  {
                     const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond2)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           return 1; /* 2_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                     else if (!cond2)
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[2])
                           {
                              return 5; /* 26_0 */
                           }
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[2])
                           {
                              return 1; /* 2_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 3; /* 6_0 */
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 5; /* 26_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 5; /* 26_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                     }
                  }
               }
               else if (!cond4)
               {
                  {
                     const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond2)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                     else if (!cond2)
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 9; /* 35_0 */
                              }
                           }
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 9; /* 35_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      {
         const char cond0 = !HIL_PM0_gateSignalBuffer[0];
         if (cond0)
         {
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[3];
               if (cond2)
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           return 3; /* 6_0 */
                        }
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        return 1; /* 2_0 */
                     }
                  }
               }
               else if (!cond2)
               {
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 3; /* 6_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
               }
               {
                  const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond3)
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 3; /* 6_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                  }
                  else if (!cond3)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
                  if (HIL_PM0_gateSignalBuffer[5])
                  {
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
         else if (!cond0)
         {
            {
               const char cond4 = !HIL_PM0_gateSignalBuffer[5];
               if (cond4)
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 3; /* 6_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
               }
               else if (!cond4)
               {
                  {
                     const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond2)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                     else if (!cond2)
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[2])
                           {
                              if (x[0]+x[1]+x[2] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[2])
                           {
                              if (x[0]+x[1]+x[2] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 return 9; /* 35_0 */
                              }
                           }
                           if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                                  0 || HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[2])
                           {
                              if (x[0]+x[1]+x[2] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[3])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[4])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 9; /* 35_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[5])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[2])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
         {
            const char cond4 = !HIL_PM0_gateSignalBuffer[5];
            if (cond4)
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 3; /* 6_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 3; /* 6_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[2])
                           {
                              if (x[0]+x[1]+x[2] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 return 5; /* 26_0 */
                              }
                           }
                           if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                                  0 || HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 5; /* 26_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 1; /* 2_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 5; /* 26_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 5; /* 26_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
            else if (!cond4)
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 9; /* 35_0 */
                              }
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[3];
               if (cond2)
               {
                  if (HIL_PM0_gateSignalBuffer[4])
                  {
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                  }
               }
               else if (!cond2)
               {
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 11; /* 39_0 */
                                 }
                              }
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
               {
                  const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond3)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 9; /* 35_0 */
                              }
                           }
                        }
                     }
                  }
                  else if (!cond3)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 15; /* 63_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                     HIL_PM0_gateSignalBuffer[0])
                                 {
                                    return 13; /* 59_0 */
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 4_0";
   return 2; /* 4_0 */
}
static const size_t PM0_Ad_6_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_Ad_6_colIdx[] = {
   0,1,2,3
};
static const double PM0_Ad_6_data[] _ALIGN = {
   0.995123042277094694,0.995123042277094694,0.995123042277094694,
   0.0252912239635718593
};
static const size_t PM0_Bd0_6_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd0_6_colIdx[] = {
   0,0,0
};
static const double PM0_Bd0_6_data[] _ALIGN = {
   0.276874085629755518,0.276874085629755518,0.276874085629755518
};
static const size_t PM0_Bd1_6_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd1_6_colIdx[] = {
   0,0,0
};
static const double PM0_Bd1_6_data[] _ALIGN = {
   0.277325655609487021,0.277325655609487021,0.277325655609487021
};
static const size_t PM0_C_0_6_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_C_0_6_colIdx[] = {
   0,1,2
};
static const double PM0_C_0_6_data[] _ALIGN = {
   1.,1.,1.
};
static const size_t PM0_D_0_6_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_6_colIdx[] = {
   0
};
static const double PM0_D_0_6_data[] _ALIGN = {
   0
};
static void PM0_collision_6()
{
}
static size_t PM0_natPreComm_6_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[1])
   {
      if (x[0]+x[1]+x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[2])
      {
         return 0; /* 0_0 */
      }
   }
   return 3; /* 6_0 */
}
static size_t PM0_natPostComm_6_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (!HIL_PM0_gateSignalBuffer[0])
   {
      if (!HIL_PM0_gateSignalBuffer[2])
      {
         if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (x[0]+x[1]+x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
            {
               return 1; /* 2_0 */
            }
            if (x[0]+x[1]+x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
            {
               return 1; /* 2_0 */
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
            {
               return 2; /* 4_0 */
            }
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
            {
               return 2; /* 4_0 */
            }
         }
      }
      if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
      {
         if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                HIL_PM0_gateSignalBuffer[2])
            {
               return 7; /* 30_0 */
            }
         }
      }
   }
   if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
   {
      if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
             HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 11; /* 39_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 11; /* 39_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               return 7; /* 30_0 */
            }
         }
      }
      if (x[0]+x[1]+x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2]-50.*x[3] > 0 || HIL_PM0_gateSignalBuffer[2])
         {
            return 15; /* 63_0 */
         }
      }
   }
   if (!HIL_PM0_gateSignalBuffer[2])
   {
      if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
      {
         if (x[0]+x[1]+x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 1; /* 2_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 1; /* 2_0 */
            }
         }
         if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
         {
            return 13; /* 59_0 */
         }
      }
   }
   if (!HIL_PM0_gateSignalBuffer[1])
   {
      if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
      {
         if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 2; /* 4_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 2; /* 4_0 */
            }
         }
         if (-x[3] > 0)
         {
            return 14; /* 61_0 */
         }
      }
   }
   return 3; /* 6_0 */
}
static size_t PM0_forcedComm_6_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond0 = !HIL_PM0_gateSignalBuffer[0];
      if (cond0)
      {
         {
            const char cond1 = !HIL_PM0_gateSignalBuffer[3];
            if (cond1)
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     {
                        const char cond2 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond2)
                        {
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 3; /* 6_0 */
                           }
                        }
                        else if (!cond2)
                        {
                           return 3; /* 6_0 */
                        }
                        if (HIL_PM0_gateSignalBuffer[5])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     return 1; /* 2_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
            else if (!cond1)
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond2)
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
               }
            }
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[4];
               if (cond2)
               {
                  if (HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        return 1; /* 2_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        return 2; /* 4_0 */
                     }
                  }
               }
               else if (!cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
               }
               if (HIL_PM0_gateSignalBuffer[5])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                  }
               }
            }
         }
      }
      else if (!cond0)
      {
         {
            const char cond3 = !HIL_PM0_gateSignalBuffer[5];
            if (cond3)
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
               }
            }
            else if (!cond3)
            {
               {
                  const char cond1 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond1)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  else if (!cond1)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
                  {
                     const char cond2 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond2)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                     else if (!cond2)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
            {
               const char cond1 = !HIL_PM0_gateSignalBuffer[3];
               if (cond1)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
               else if (!cond1)
               {
                  if (HIL_PM0_gateSignalBuffer[4])
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      {
         const char cond3 = !HIL_PM0_gateSignalBuffer[5];
         if (cond3)
         {
            {
               const char cond1 = !HIL_PM0_gateSignalBuffer[3];
               if (cond1)
               {
                  if (HIL_PM0_gateSignalBuffer[4])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        return 1; /* 2_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        return 2; /* 4_0 */
                     }
                  }
               }
               else if (!cond1)
               {
                  {
                     const char cond2 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond2)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 3; /* 6_0 */
                           }
                        }
                     }
                     else if (!cond2)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                        if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >=
                               0 || HIL_PM0_gateSignalBuffer[2])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
               }
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 2; /* 4_0 */
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
         else if (!cond3)
         {
            {
               const char cond1 = !HIL_PM0_gateSignalBuffer[3];
               if (cond1)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
               else if (!cond1)
               {
                  if (HIL_PM0_gateSignalBuffer[4])
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
         {
            const char cond1 = !HIL_PM0_gateSignalBuffer[3];
            if (cond1)
            {
               if (HIL_PM0_gateSignalBuffer[4])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
               }
            }
            else if (!cond1)
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond2)
                  {
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[4];
               if (cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                  }
               }
               else if (!cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 6_0";
   return 3; /* 6_0 */
}
static const size_t PM0_Ad_24_rowPtr[] = {
   0,2,3,4,5
};
static const size_t PM0_Ad_24_colIdx[] = {
   1,2,1,2,3
};
static const double PM0_Ad_24_data[] _ALIGN = {
   -0.995123042277094694,-0.995123042277094694,0.995123042277094694,
   0.995123042277094694,0.0252912239635718593
};
static const size_t PM0_Bd0_24_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_Bd0_24_colIdx[] = {
   0
};
static const double PM0_Bd0_24_data[] _ALIGN = {
   0
};
static const size_t PM0_Bd1_24_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_Bd1_24_colIdx[] = {
   0
};
static const double PM0_Bd1_24_data[] _ALIGN = {
   0
};
static const size_t PM0_C_0_24_rowPtr[] = {
   0,2,3,4,4
};
static const size_t PM0_C_0_24_colIdx[] = {
   1,2,1,2
};
static const double PM0_C_0_24_data[] _ALIGN = {
   -1.,-1.,1.,1.
};
static const size_t PM0_D_0_24_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_24_colIdx[] = {
   0
};
static const double PM0_D_0_24_data[] _ALIGN = {
   0
};
static void PM0_collision_24()
{
   double * _RESTRICT x = HIL_PM0_x;
   double * _RESTRICT tmpX = HIL_PM0_tmpX;
   tmpX[0] = 0.66666666666666663*x[0]-0.333333333333333315*x[1]-
             0.333333333333333315*x[2];
   tmpX[1] = -0.333333333333333315*x[0]+0.66666666666666663*x[1]-
             0.333333333333333315*x[2];
   tmpX[2] = -0.333333333333333315*x[0]-0.333333333333333315*x[1]+
             0.66666666666666663*x[2];
   x[0] = tmpX[0];
   x[1] = tmpX[1];
   x[2] = tmpX[2];
}
static size_t PM0_natPreComm_24_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   return 4; /* 24_0 */
}
static size_t PM0_natPostComm_24_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond4 = !HIL_PM0_gateSignalBuffer[4];
      if (cond4)
      {
         if (x[3]-1.00179998560011518*u[0] >= 0 &&
             !HIL_PM0_gateSignalBuffer[1])
         {
            if (u[0] >= 0 && !HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  return 0; /* 0_0 */
               }
               if (HIL_PM0_gateSignalBuffer[3])
               {
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 0; /* 0_0 */
                  }
               }
            }
         }
         if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
         {
            if (-x[3]+1.00179998560011496*u[0] > 0)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  return 1; /* 2_0 */
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-u[0] > 0)
               {
                  return 2; /* 4_0 */
               }
            }
         }
      }
      else if (!cond4)
      {
         if (!HIL_PM0_gateSignalBuffer[0])
         {
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[3]+1.00179998560011496*u[0] > 0)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     return 1; /* 2_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-u[0] > 0)
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
            if (x[3]-1.00179998560011518*u[0] >= 0 &&
                !HIL_PM0_gateSignalBuffer[1])
            {
               if (u[0] >= 0 && !HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 0; /* 0_0 */
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[3])
         {
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
            {
               if (-x[3]+1.00179998560011496*u[0] > 0)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     return 1; /* 2_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-u[0] > 0)
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
         }
      }
      {
         const char cond14 = -x[3] > 0 || HIL_PM0_gateSignalBuffer[4];
         if (cond14)
         {
            if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
            {
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (u[0] > 0)
                     {
                        return 5; /* 26_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-u[0] > 0)
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (u[0] > 0)
                     {
                        return 5; /* 26_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-u[0] > 0)
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
            }
         }
         else if (!cond14)
         {
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[3]+1.00179998560011496*u[0] > 0)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     return 1; /* 2_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-u[0] > 0)
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
         }
         if (x[3]-1.00179998560011518*u[0] >= 0 &&
             !HIL_PM0_gateSignalBuffer[1])
         {
            if (u[0] >= 0 && !HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 0; /* 0_0 */
                  }
               }
            }
         }
         if (-x[3] > 0)
         {
            return 15; /* 63_0 */
         }
      }
   }
   return 4; /* 24_0 */
}
static size_t PM0_forcedComm_24_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond1 = !HIL_PM0_gateSignalBuffer[1];
      if (cond1)
      {
         {
            const char cond2 = !HIL_PM0_gateSignalBuffer[2];
            if (cond2)
            {
               {
                  const char cond3 = !HIL_PM0_gateSignalBuffer[5];
                  if (cond3)
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 4; /* 24_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 0; /* 0_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 0; /* 0_0 */
                     }
                  }
                  else if (!cond3)
                  {
                     {
                        const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                        if (cond0)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 4; /* 24_0 */
                              }
                           }
                        }
                        else if (!cond0)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 12; /* 57_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 8; /* 33_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 8; /* 33_0 */
                           }
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 12; /* 57_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 8; /* 33_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 8; /* 33_0 */
                           }
                        }
                     }
                  }
                  {
                     const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                     if (cond0)
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 0; /* 0_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 0; /* 0_0 */
                        }
                     }
                     else if (!cond0)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 12; /* 57_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 8; /* 33_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 8; /* 33_0 */
                           }
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 8; /* 33_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 8; /* 33_0 */
                           }
                        }
                     }
                  }
               }
            }
            else if (!cond2)
            {
               {
                  const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                  if (cond0)
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 2; /* 4_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 2; /* 4_0 */
                     }
                  }
                  else if (!cond0)
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[5];
                     if (cond3)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 2; /* 4_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 2; /* 4_0 */
                        }
                     }
                     else if (!cond3)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 10; /* 37_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 10; /* 37_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
            {
               {
                  const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                  if (cond0)
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 2; /* 4_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 2; /* 4_0 */
                     }
                  }
                  else if (!cond0)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[5];
                        if (cond3)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 6; /* 28_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 10; /* 37_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 10; /* 37_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[5];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 2; /* 4_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 2; /* 4_0 */
                        }
                     }
                     else if (!cond3)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 10; /* 37_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 10; /* 37_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      else if (!cond1)
      {
         {
            const char cond2 = !HIL_PM0_gateSignalBuffer[2];
            if (cond2)
            {
               {
                  const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                  if (cond0)
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 1; /* 2_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 1; /* 2_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                  }
                  else if (!cond0)
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[5];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 1; /* 2_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 1; /* 2_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 9; /* 35_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 9; /* 35_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 9; /* 35_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 9; /* 35_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
            else if (!cond2)
            {
               {
                  const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                  if (cond0)
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 3; /* 6_0 */
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  else if (!cond0)
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[5];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 3; /* 6_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 3; /* 6_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                HIL_PM0_gateSignalBuffer[2])
            {
               {
                  const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                  if (cond0)
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  else if (!cond0)
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
               }
            }
            {
               const char cond0 = !HIL_PM0_gateSignalBuffer[0];
               if (cond0)
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
               else if (!cond0)
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               {
                  const char cond3 = !HIL_PM0_gateSignalBuffer[5];
                  if (cond3)
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 3; /* 6_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  else if (!cond3)
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      {
         const char cond2 = !HIL_PM0_gateSignalBuffer[2];
         if (cond2)
         {
            if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               {
                  const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                  if (cond0)
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 1; /* 2_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 1; /* 2_0 */
                     }
                  }
                  else if (!cond0)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[5];
                        if (cond3)
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 5; /* 26_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 9; /* 35_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 9; /* 35_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 9; /* 35_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 9; /* 35_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[5];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 1; /* 2_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                     else if (!cond3)
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 9; /* 35_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 9; /* 35_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 9; /* 35_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
         else if (!cond2)
         {
            if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               {
                  const char cond0 = !HIL_PM0_gateSignalBuffer[0];
                  if (cond0)
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  else if (!cond0)
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
               }
            }
            {
               const char cond0 = !HIL_PM0_gateSignalBuffer[0];
               if (cond0)
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
               else if (!cond0)
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               {
                  const char cond3 = !HIL_PM0_gateSignalBuffer[5];
                  if (cond3)
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 3; /* 6_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  else if (!cond3)
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[0])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
         {
            const char cond0 = !HIL_PM0_gateSignalBuffer[0];
            if (cond0)
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
               if (HIL_PM0_gateSignalBuffer[5])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
               }
            }
            else if (!cond0)
            {
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[5];
                        if (cond3)
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[3])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[4])
                              {
                                 return 7; /* 30_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
            {
               const char cond3 = !HIL_PM0_gateSignalBuffer[5];
               if (cond3)
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 3; /* 6_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
               }
               else if (!cond3)
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (!HIL_PM0_gateSignalBuffer[3])
                           {
                              return 11; /* 39_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[4])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 24_0";
   return 4; /* 24_0 */
}
static const size_t PM0_Ad_26_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_Ad_26_colIdx[] = {
   0,1,2,3
};
static const double PM0_Ad_26_data[] _ALIGN = {
   0.995123042277094694,0.995123042277094694,0.995123042277094694,
   0.0252912239635718593
};
static const size_t PM0_Bd0_26_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd0_26_colIdx[] = {
   0,0,0
};
static const double PM0_Bd0_26_data[] _ALIGN = {
   0.276874085629755518,0.276874085629755518,0.276874085629755518
};
static const size_t PM0_Bd1_26_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd1_26_colIdx[] = {
   0,0,0
};
static const double PM0_Bd1_26_data[] _ALIGN = {
   0.277325655609487021,0.277325655609487021,0.277325655609487021
};
static const size_t PM0_C_0_26_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_C_0_26_colIdx[] = {
   0,1,2
};
static const double PM0_C_0_26_data[] _ALIGN = {
   1.,1.,1.
};
static const size_t PM0_D_0_26_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_26_colIdx[] = {
   0
};
static const double PM0_D_0_26_data[] _ALIGN = {
   0
};
static void PM0_collision_26()
{
}
static size_t PM0_natPreComm_26_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (-x[0]-x[1]-x[2] >= 0 && !HIL_PM0_gateSignalBuffer[1])
   {
      {
         const char cond1 = -x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[3];
         if (cond1)
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
            {
               return 4; /* 24_0 */
            }
         }
         else if (!cond1)
         {
            if (HIL_PM0_gateSignalBuffer[4])
            {
               return 0; /* 0_0 */
            }
         }
         if (x[0]+x[1]+x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
         {
            return 0; /* 0_0 */
         }
      }
   }
   return 5; /* 26_0 */
}
static size_t PM0_natPostComm_26_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond3 = !HIL_PM0_gateSignalBuffer[4];
      if (cond3)
      {
         if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
         {
            if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  return 3; /* 6_0 */
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (x[0]+x[1]+x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
            {
               if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  return 1; /* 2_0 */
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2] > 0)
            {
               if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
               {
                  return 2; /* 4_0 */
               }
            }
         }
         if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0)
         {
            if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
               {
                  return 11; /* 39_0 */
               }
            }
         }
      }
      else if (!cond3)
      {
         if (!HIL_PM0_gateSignalBuffer[3])
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
            {
               if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                   !HIL_PM0_gateSignalBuffer[5])
               {
                  if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     return 1; /* 2_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] > 0)
               {
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0)
            {
               if (x[0]+x[1]+x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
                  {
                     return 11; /* 39_0 */
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[0])
         {
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] > 0)
               {
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[0])
      {
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2] > 0)
            {
               if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     return 6; /* 28_0 */
                  }
               }
               else
               {
                  return 2; /* 4_0 */
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                   !HIL_PM0_gateSignalBuffer[4])
               {
                  return 1; /* 2_0 */
               }
            }
         }
         if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0)
         {
            if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 7; /* 30_0 */
                  }
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2] > 0)
         {
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     return 6; /* 28_0 */
                  }
               }
            }
            if (-x[3] > 0)
            {
               return 14; /* 61_0 */
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[2])
      {
         if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
            {
               return 13; /* 59_0 */
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[5])
      {
         if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0)
         {
            if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 7; /* 30_0 */
                  }
               }
            }
         }
      }
      if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
      {
         if (-x[0]-x[1]-x[2]-50.*x[3] > 0)
         {
            if (x[0]+x[1]+x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               return 15; /* 63_0 */
            }
         }
      }
   }
   return 5; /* 26_0 */
}
static size_t PM0_forcedComm_26_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond1 = !HIL_PM0_gateSignalBuffer[2];
      if (cond1)
      {
         if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            {
               const char cond0 = !HIL_PM0_gateSignalBuffer[0];
               if (cond0)
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 1; /* 2_0 */
                  }
               }
               else if (!cond0)
               {
                  {
                     const char cond2 = !HIL_PM0_gateSignalBuffer[5];
                     if (cond2)
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                     }
                     else if (!cond2)
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                  }
               }
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[5];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 1; /* 2_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 1; /* 2_0 */
                     }
                  }
                  else if (!cond2)
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                  }
               }
            }
         }
      }
      else if (!cond1)
      {
         {
            const char cond0 = !HIL_PM0_gateSignalBuffer[0];
            if (cond0)
            {
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
            }
            else if (!cond0)
            {
               if (HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 10; /* 37_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 10; /* 37_0 */
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 11; /* 39_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 11; /* 39_0 */
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 10; /* 37_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 10; /* 37_0 */
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 11; /* 39_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 11; /* 39_0 */
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[5];
               if (cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 2; /* 4_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 2; /* 4_0 */
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                  }
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 3; /* 6_0 */
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
               }
               else if (!cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      {
         const char cond0 = !HIL_PM0_gateSignalBuffer[0];
         if (cond0)
         {
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
            }
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (HIL_PM0_gateSignalBuffer[5])
            {
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
               }
            }
         }
         else if (!cond0)
         {
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[5];
               if (cond2)
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
               }
               else if (!cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
         {
            const char cond2 = !HIL_PM0_gateSignalBuffer[5];
            if (cond2)
            {
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 2; /* 4_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 2; /* 4_0 */
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                  }
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
            }
            else if (!cond2)
            {
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
               }
            }
            if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 26_0";
   return 5; /* 26_0 */
}
static const size_t PM0_Ad_28_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_Ad_28_colIdx[] = {
   0,1,2,3
};
static const double PM0_Ad_28_data[] _ALIGN = {
   0.995123042277094694,0.995123042277094694,0.995123042277094694,
   0.0252912239635718593
};
static const size_t PM0_Bd0_28_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd0_28_colIdx[] = {
   0,0,0
};
static const double PM0_Bd0_28_data[] _ALIGN = {
   0.276874085629755518,0.276874085629755518,0.276874085629755518
};
static const size_t PM0_Bd1_28_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd1_28_colIdx[] = {
   0,0,0
};
static const double PM0_Bd1_28_data[] _ALIGN = {
   0.277325655609487021,0.277325655609487021,0.277325655609487021
};
static const size_t PM0_C_0_28_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_C_0_28_colIdx[] = {
   0,1,2
};
static const double PM0_C_0_28_data[] _ALIGN = {
   1.,1.,1.
};
static const size_t PM0_D_0_28_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_28_colIdx[] = {
   0
};
static const double PM0_D_0_28_data[] _ALIGN = {
   0
};
static void PM0_collision_28()
{
}
static size_t PM0_natPreComm_28_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (x[0]+x[1]+x[2] >= 0 && !HIL_PM0_gateSignalBuffer[2])
   {
      {
         const char cond1 = -x[3] > 0 || HIL_PM0_gateSignalBuffer[3];
         if (cond1)
         {
            if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
            {
               return 4; /* 24_0 */
            }
         }
         else if (!cond1)
         {
            if (HIL_PM0_gateSignalBuffer[4])
            {
               return 0; /* 0_0 */
            }
         }
         if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
         {
            return 0; /* 0_0 */
         }
      }
   }
   return 6; /* 28_0 */
}
static size_t PM0_natPostComm_28_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond4 = !HIL_PM0_gateSignalBuffer[4];
      if (cond4)
      {
         if (HIL_PM0_gateSignalBuffer[3])
         {
            if (x[0]+x[1]+x[2] > 0)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[5])
                  {
                     return 1; /* 2_0 */
                  }
               }
            }
            if (x[0]+x[1]+x[2]-200.*x[3] > 0)
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
                  {
                     return 11; /* 39_0 */
                  }
               }
            }
         }
         if (-x[3] > 0)
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  return 3; /* 6_0 */
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
            {
               if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  return 2; /* 4_0 */
               }
            }
         }
      }
      else if (!cond4)
      {
         if (!HIL_PM0_gateSignalBuffer[0])
         {
            if (x[0]+x[1]+x[2] > 0)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[3] > 0)
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[3])
         {
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
            if (-x[3] > 0)
            {
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
         }
      }
      if (x[0]+x[1]+x[2] > 0)
      {
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            {
               const char cond13 = -x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                                   HIL_PM0_gateSignalBuffer[4];
               if (cond13)
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 5; /* 26_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
               else if (!cond13)
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 1; /* 2_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[5])
                  {
                     return 1; /* 2_0 */
                  }
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
               {
                  return 13; /* 59_0 */
               }
            }
         }
      }
      if (x[0]+x[1]+x[2]-200.*x[3] > 0)
      {
         if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
             HIL_PM0_gateSignalBuffer[2])
         {
            if (-x[0]-x[1]-x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 7; /* 30_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 7; /* 30_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
               {
                  return 11; /* 39_0 */
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
               {
                  return 2; /* 4_0 */
               }
            }
            if (-x[3] > 0)
            {
               return 14; /* 61_0 */
            }
         }
      }
      if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
      {
         if (x[0]+x[1]+x[2]-100.*x[3] > 0)
         {
            if (-x[0]-x[1]-x[2]-50.*x[3] > 0 || HIL_PM0_gateSignalBuffer[2])
            {
               return 15; /* 63_0 */
            }
         }
      }
   }
   return 6; /* 28_0 */
}
static size_t PM0_forcedComm_28_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond1 = !HIL_PM0_gateSignalBuffer[1];
      if (cond1)
      {
         if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
         {
            {
               const char cond0 = !HIL_PM0_gateSignalBuffer[0];
               if (cond0)
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
               }
               else if (!cond0)
               {
                  {
                     const char cond2 = !HIL_PM0_gateSignalBuffer[5];
                     if (cond2)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                     else if (!cond2)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
               }
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[5];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 2; /* 4_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 2; /* 4_0 */
                     }
                  }
                  else if (!cond2)
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 10; /* 37_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
               }
            }
         }
      }
      else if (!cond1)
      {
         {
            const char cond0 = !HIL_PM0_gateSignalBuffer[0];
            if (cond0)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 1; /* 2_0 */
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
            }
            else if (!cond0)
            {
               if (HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 9; /* 35_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 9; /* 35_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 11; /* 39_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 11; /* 39_0 */
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 9; /* 35_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 9; /* 35_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 11; /* 39_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 11; /* 39_0 */
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[5];
               if (cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 1; /* 2_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 1; /* 2_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 3; /* 6_0 */
                     }
                  }
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
               }
               else if (!cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      {
         const char cond0 = !HIL_PM0_gateSignalBuffer[0];
         if (cond0)
         {
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 1; /* 2_0 */
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
            }
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (HIL_PM0_gateSignalBuffer[5])
            {
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
               }
            }
         }
         else if (!cond0)
         {
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[5];
               if (cond2)
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
               }
               else if (!cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
         {
            const char cond2 = !HIL_PM0_gateSignalBuffer[5];
            if (cond2)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 1; /* 2_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 1; /* 2_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                  }
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
            }
            else if (!cond2)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 9; /* 35_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
               }
            }
            if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (!HIL_PM0_gateSignalBuffer[3])
                        {
                           return 11; /* 39_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 28_0";
   return 6; /* 28_0 */
}
static const size_t PM0_Ad_30_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_Ad_30_colIdx[] = {
   0,1,2,3
};
static const double PM0_Ad_30_data[] _ALIGN = {
   0.995123042277094694,0.995123042277094694,0.995123042277094694,
   0.0252912239635718593
};
static const size_t PM0_Bd0_30_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd0_30_colIdx[] = {
   0,0,0
};
static const double PM0_Bd0_30_data[] _ALIGN = {
   0.276874085629755518,0.276874085629755518,0.276874085629755518
};
static const size_t PM0_Bd1_30_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd1_30_colIdx[] = {
   0,0,0
};
static const double PM0_Bd1_30_data[] _ALIGN = {
   0.277325655609487021,0.277325655609487021,0.277325655609487021
};
static const size_t PM0_C_0_30_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_C_0_30_colIdx[] = {
   0,1,2
};
static const double PM0_C_0_30_data[] _ALIGN = {
   1.,1.,1.
};
static const size_t PM0_D_0_30_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_30_colIdx[] = {
   0
};
static const double PM0_D_0_30_data[] _ALIGN = {
   0
};
static void PM0_collision_30()
{
}
static size_t PM0_natPreComm_30_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (-x[0]-x[1]-x[2]+200.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[1])
   {
      if (x[0]+x[1]+x[2]+66.6666666666666572*x[3] >= 0 &&
          !HIL_PM0_gateSignalBuffer[2])
      {
         if (HIL_PM0_gateSignalBuffer[4])
         {
            if (HIL_PM0_gateSignalBuffer[3])
            {
               return 4; /* 24_0 */
            }
            else
            {
               return 0; /* 0_0 */
            }
         }
         else
         {
            return 0; /* 0_0 */
         }
      }
   }
   return 7; /* 30_0 */
}
static size_t PM0_natPostComm_30_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond3 = !HIL_PM0_gateSignalBuffer[4];
      if (cond3)
      {
         if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  return 3; /* 6_0 */
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (x[0]+x[1]+x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
            {
               if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  return 1; /* 2_0 */
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
            {
               if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  return 2; /* 4_0 */
               }
            }
         }
         if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
         {
            if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  return 11; /* 39_0 */
               }
            }
         }
      }
      else if (!cond3)
      {
         if (!HIL_PM0_gateSignalBuffer[3])
         {
            if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                   !HIL_PM0_gateSignalBuffer[5])
               {
                  if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     return 1; /* 2_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
            {
               if (x[0]+x[1]+x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     return 11; /* 39_0 */
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[0])
         {
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[0])
      {
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     return 5; /* 26_0 */
                  }
               }
               else
               {
                  return 1; /* 2_0 */
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     return 6; /* 28_0 */
                  }
               }
               else
               {
                  return 2; /* 4_0 */
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[2])
      {
         if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 5; /* 26_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
            {
               return 13; /* 59_0 */
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     return 6; /* 28_0 */
                  }
               }
            }
            if (-x[3] > 0)
            {
               return 14; /* 61_0 */
            }
         }
      }
      if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
      {
         if (x[0]+x[1]+x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-50.*x[3] > 0 || HIL_PM0_gateSignalBuffer[2])
            {
               return 15; /* 63_0 */
            }
         }
      }
   }
   return 7; /* 30_0 */
}
static size_t PM0_forcedComm_30_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond0 = !HIL_PM0_gateSignalBuffer[0];
      if (cond0)
      {
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 1; /* 2_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 1; /* 2_0 */
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 5; /* 26_0 */
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 2; /* 4_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 2; /* 4_0 */
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     return 6; /* 28_0 */
                  }
               }
            }
         }
         if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 3; /* 6_0 */
               }
            }
         }
         if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 7; /* 30_0 */
                  }
               }
            }
         }
      }
      else if (!cond0)
      {
         {
            const char cond1 = !HIL_PM0_gateSignalBuffer[5];
            if (cond1)
            {
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
               }
            }
            else if (!cond1)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 9; /* 35_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 9; /* 35_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 10; /* 37_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 10; /* 37_0 */
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                  }
               }
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 11; /* 39_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 11; /* 39_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 9; /* 35_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 9; /* 35_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 10; /* 37_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 10; /* 37_0 */
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
            {
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 11; /* 39_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 11; /* 39_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
         }
      }
      {
         const char cond1 = !HIL_PM0_gateSignalBuffer[5];
         if (cond1)
         {
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 1; /* 2_0 */
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
            }
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
         }
         else if (!cond1)
         {
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 9; /* 35_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 9; /* 35_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 10; /* 37_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 10; /* 37_0 */
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 11; /* 39_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 11; /* 39_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 9; /* 35_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 9; /* 35_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 10; /* 37_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 10; /* 37_0 */
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                  }
               }
            }
         }
         if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 11; /* 39_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 11; /* 39_0 */
                     }
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 30_0";
   return 7; /* 30_0 */
}
static const size_t PM0_Ad_33_rowPtr[] = {
   0,2,3,4,5
};
static const size_t PM0_Ad_33_colIdx[] = {
   1,2,1,2,3
};
static const double PM0_Ad_33_data[] _ALIGN = {
   -0.995123042277094694,-0.995123042277094694,0.995123042277094694,
   0.995123042277094694,0.0252912239635718593
};
static const size_t PM0_Bd0_33_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_Bd0_33_colIdx[] = {
   0
};
static const double PM0_Bd0_33_data[] _ALIGN = {
   0
};
static const size_t PM0_Bd1_33_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_Bd1_33_colIdx[] = {
   0
};
static const double PM0_Bd1_33_data[] _ALIGN = {
   0
};
static const size_t PM0_C_0_33_rowPtr[] = {
   0,2,3,4,4
};
static const size_t PM0_C_0_33_colIdx[] = {
   1,2,1,2
};
static const double PM0_C_0_33_data[] _ALIGN = {
   -1.,-1.,1.,1.
};
static const size_t PM0_D_0_33_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_33_colIdx[] = {
   0
};
static const double PM0_D_0_33_data[] _ALIGN = {
   0
};
static void PM0_collision_33()
{
   double * _RESTRICT x = HIL_PM0_x;
   double * _RESTRICT tmpX = HIL_PM0_tmpX;
   tmpX[0] = 0.66666666666666663*x[0]-0.333333333333333315*x[1]-
             0.333333333333333315*x[2];
   tmpX[1] = -0.333333333333333315*x[0]+0.66666666666666663*x[1]-
             0.333333333333333315*x[2];
   tmpX[2] = -0.333333333333333315*x[0]-0.333333333333333315*x[1]+
             0.66666666666666663*x[2];
   x[0] = tmpX[0];
   x[1] = tmpX[1];
   x[2] = tmpX[2];
}
static size_t PM0_natPreComm_33_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   return 8; /* 33_0 */
}
static size_t PM0_natPostComm_33_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond8 = x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5];
      if (cond8)
      {
         if (!HIL_PM0_gateSignalBuffer[3])
         {
            if (-x[3]+1.00179998560011496*u[0] > 0)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  return 1; /* 2_0 */
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-u[0] > 0)
               {
                  return 2; /* 4_0 */
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[4])
         {
            if (-x[3]+1.00179998560011496*u[0] > 0)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  return 1; /* 2_0 */
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-u[0] > 0)
               {
                  return 2; /* 4_0 */
               }
            }
         }
      }
      else if (!cond8)
      {
         if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (u[0] > 0)
                  {
                     return 9; /* 35_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-u[0] > 0)
                  {
                     return 10; /* 37_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (u[0] > 0)
                  {
                     return 9; /* 35_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-u[0] > 0)
                  {
                     return 10; /* 37_0 */
                  }
               }
            }
         }
      }
      {
         const char cond0 = !HIL_PM0_gateSignalBuffer[0];
         if (cond0)
         {
            if (HIL_PM0_gateSignalBuffer[5])
            {
               if (-x[3]+1.00179998560011496*u[0] > 0)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
                     {
                        return 1; /* 2_0 */
                     }
                     if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
                     {
                        return 1; /* 2_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-u[0] > 0)
                  {
                     if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
                     {
                        return 2; /* 4_0 */
                     }
                     if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
                     {
                        return 2; /* 4_0 */
                     }
                  }
               }
               if (x[3]-1.00179998560011518*u[0] >= 0 &&
                   !HIL_PM0_gateSignalBuffer[1])
               {
                  if (u[0] >= 0 && !HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 0; /* 0_0 */
                     }
                  }
               }
            }
            if (x[3]-1.00179998560011518*u[0] >= 0 &&
                !HIL_PM0_gateSignalBuffer[1])
            {
               if (u[0] >= 0 && !HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 0; /* 0_0 */
                  }
               }
            }
         }
         else if (!cond0)
         {
            if (x[3]-1.00179998560011518*u[0] >= 0 &&
                !HIL_PM0_gateSignalBuffer[1])
            {
               if (u[0] >= 0 && !HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 0; /* 0_0 */
                     }
                  }
               }
            }
         }
         if (x[3]-1.00179998560011518*u[0] >= 0 &&
             !HIL_PM0_gateSignalBuffer[1])
         {
            if (u[0] >= 0 && !HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 0; /* 0_0 */
                  }
               }
            }
         }
         if (-x[3] > 0)
         {
            return 15; /* 63_0 */
         }
      }
   }
   return 8; /* 33_0 */
}
static size_t PM0_forcedComm_33_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond0 = !HIL_PM0_gateSignalBuffer[1];
      if (cond0)
      {
         {
            const char cond1 = !HIL_PM0_gateSignalBuffer[2];
            if (cond1)
            {
               {
                  const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond3)
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           return 8; /* 33_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 0; /* 0_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 0; /* 0_0 */
                     }
                  }
                  else if (!cond3)
                  {
                     {
                        const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                        if (cond2)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 8; /* 33_0 */
                              }
                           }
                        }
                        else if (!cond2)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 12; /* 57_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 4; /* 24_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 4; /* 24_0 */
                           }
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 12; /* 57_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 4; /* 24_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 4; /* 24_0 */
                           }
                        }
                     }
                  }
                  {
                     const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond2)
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 0; /* 0_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 0; /* 0_0 */
                        }
                     }
                     else if (!cond2)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 12; /* 57_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 4; /* 24_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 4; /* 24_0 */
                           }
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 4; /* 24_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 4; /* 24_0 */
                           }
                        }
                     }
                  }
               }
            }
            else if (!cond1)
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 2; /* 4_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 2; /* 4_0 */
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 6; /* 28_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 6; /* 28_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 2; /* 4_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 2; /* 4_0 */
                        }
                     }
                     else if (!cond3)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 6; /* 28_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 6; /* 28_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 2; /* 4_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 2; /* 4_0 */
                     }
                  }
                  else if (!cond2)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 10; /* 37_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 6; /* 28_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 6; /* 28_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 2; /* 4_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 2; /* 4_0 */
                        }
                     }
                     else if (!cond3)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 14; /* 61_0 */
                              }
                           }
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 6; /* 28_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 6; /* 28_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 6; /* 28_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      else if (!cond0)
      {
         {
            const char cond1 = !HIL_PM0_gateSignalBuffer[2];
            if (cond1)
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 1; /* 2_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 1; /* 2_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 5; /* 26_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 5; /* 26_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 5; /* 26_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 5; /* 26_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 1; /* 2_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 1; /* 2_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 5; /* 26_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 5; /* 26_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 5; /* 26_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 5; /* 26_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
            else if (!cond1)
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 3; /* 6_0 */
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 3; /* 6_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 3; /* 6_0 */
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                     else if (!cond3)
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 7; /* 30_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 7; /* 30_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 7; /* 30_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 7; /* 30_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                HIL_PM0_gateSignalBuffer[2])
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
            }
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[3];
               if (cond2)
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
               else if (!cond2)
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               {
                  const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond3)
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 3; /* 6_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  else if (!cond3)
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[2])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      {
         const char cond1 = !HIL_PM0_gateSignalBuffer[2];
         if (cond1)
         {
            if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 1; /* 2_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 1; /* 2_0 */
                     }
                  }
                  else if (!cond2)
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 9; /* 35_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 5; /* 26_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 5; /* 26_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 5; /* 26_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 5; /* 26_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                  }
                  {
                     const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                     if (cond3)
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 1; /* 2_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                     else if (!cond3)
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[3])
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 5; /* 26_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 5; /* 26_0 */
                           }
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 13; /* 59_0 */
                              }
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 5; /* 26_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 5; /* 26_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
         else if (!cond1)
         {
            if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
                  else if (!cond2)
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
            }
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[3];
               if (cond2)
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
               else if (!cond2)
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               {
                  const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond3)
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 3; /* 6_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  else if (!cond3)
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
         {
            const char cond2 = !HIL_PM0_gateSignalBuffer[3];
            if (cond2)
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
               if (HIL_PM0_gateSignalBuffer[4])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
               }
            }
            else if (!cond2)
            {
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     {
                        const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                        if (cond3)
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[0])
                           {
                              if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[5])
                              {
                                 return 11; /* 39_0 */
                              }
                           }
                        }
                        else if (!cond3)
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 7; /* 30_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 7; /* 30_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (HIL_PM0_gateSignalBuffer[4])
                           {
                              return 15; /* 63_0 */
                           }
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[4])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
            {
               const char cond3 = !HIL_PM0_gateSignalBuffer[4];
               if (cond3)
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 3; /* 6_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
               }
               else if (!cond3)
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 7; /* 30_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                                  HIL_PM0_gateSignalBuffer[1])
                              {
                                 return 15; /* 63_0 */
                              }
                           }
                        }
                     }
                  }
               }
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           if (!HIL_PM0_gateSignalBuffer[0])
                           {
                              return 7; /* 30_0 */
                           }
                           if (!HIL_PM0_gateSignalBuffer[5])
                           {
                              return 7; /* 30_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 33_0";
   return 8; /* 33_0 */
}
static const size_t PM0_Ad_35_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_Ad_35_colIdx[] = {
   0,1,2,3
};
static const double PM0_Ad_35_data[] _ALIGN = {
   0.995123042277094694,0.995123042277094694,0.995123042277094694,
   0.0252912239635718593
};
static const size_t PM0_Bd0_35_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd0_35_colIdx[] = {
   0,0,0
};
static const double PM0_Bd0_35_data[] _ALIGN = {
   0.276874085629755518,0.276874085629755518,0.276874085629755518
};
static const size_t PM0_Bd1_35_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd1_35_colIdx[] = {
   0,0,0
};
static const double PM0_Bd1_35_data[] _ALIGN = {
   0.277325655609487021,0.277325655609487021,0.277325655609487021
};
static const size_t PM0_C_0_35_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_C_0_35_colIdx[] = {
   0,1,2
};
static const double PM0_C_0_35_data[] _ALIGN = {
   1.,1.,1.
};
static const size_t PM0_D_0_35_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_35_colIdx[] = {
   0
};
static const double PM0_D_0_35_data[] _ALIGN = {
   0
};
static void PM0_collision_35()
{
}
static size_t PM0_natPreComm_35_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (-x[0]-x[1]-x[2] >= 0 && !HIL_PM0_gateSignalBuffer[1])
   {
      {
         const char cond1 = -x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[0];
         if (cond1)
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[5])
            {
               return 8; /* 33_0 */
            }
         }
         else if (!cond1)
         {
            if (HIL_PM0_gateSignalBuffer[5])
            {
               return 0; /* 0_0 */
            }
         }
         if (x[0]+x[1]+x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
         {
            return 0; /* 0_0 */
         }
      }
   }
   return 9; /* 35_0 */
}
static size_t PM0_natPostComm_35_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond10 = !HIL_PM0_gateSignalBuffer[5];
      if (cond10)
      {
         if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
         {
            if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 3; /* 6_0 */
               }
            }
         }
         if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0)
         {
            if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
            {
               if (x[0]+x[1]+x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  return 7; /* 30_0 */
               }
            }
         }
      }
      else if (!cond10)
      {
         if (!HIL_PM0_gateSignalBuffer[0])
         {
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[4])
                  {
                     return 1; /* 2_0 */
                  }
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] > 0)
               {
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
            {
               if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0)
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     return 7; /* 30_0 */
                  }
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2] > 0)
         {
            {
               const char cond8 = x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5];
               if (cond8)
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
               }
               else if (!cond8)
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 10; /* 37_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 10; /* 37_0 */
                     }
                  }
               }
               if (-x[3] > 0)
               {
                  return 14; /* 61_0 */
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[2])
      {
         if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (x[0]+x[1]+x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 1; /* 2_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 1; /* 2_0 */
               }
            }
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
            {
               return 13; /* 59_0 */
            }
         }
      }
      if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0)
      {
         if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 11; /* 39_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 11; /* 39_0 */
                  }
               }
            }
         }
      }
      if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
      {
         if (-x[0]-x[1]-x[2]-50.*x[3] > 0)
         {
            if (x[0]+x[1]+x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               return 15; /* 63_0 */
            }
         }
      }
   }
   return 9; /* 35_0 */
}
static size_t PM0_forcedComm_35_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond0 = !HIL_PM0_gateSignalBuffer[2];
      if (cond0)
      {
         if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[4];
               if (cond2)
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        return 9; /* 35_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 1; /* 2_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 1; /* 2_0 */
                  }
               }
               else if (!cond2)
               {
                  {
                     const char cond1 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond1)
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                     else if (!cond1)
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 5; /* 26_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 5; /* 26_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                  }
               }
               {
                  const char cond1 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond1)
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 1; /* 2_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 1; /* 2_0 */
                     }
                  }
                  else if (!cond1)
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 5; /* 26_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 5; /* 26_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                  }
               }
            }
         }
      }
      else if (!cond0)
      {
         {
            const char cond1 = !HIL_PM0_gateSignalBuffer[3];
            if (cond1)
            {
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 2; /* 4_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 2; /* 4_0 */
                  }
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                     {
                        return 10; /* 37_0 */
                     }
                  }
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 3; /* 6_0 */
                  }
               }
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        return 11; /* 39_0 */
                     }
                  }
               }
            }
            else if (!cond1)
            {
               if (HIL_PM0_gateSignalBuffer[4])
               {
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 6; /* 28_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 6; /* 28_0 */
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 7; /* 30_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 7; /* 30_0 */
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 6; /* 28_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 6; /* 28_0 */
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 7; /* 30_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 7; /* 30_0 */
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[4];
               if (cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 2; /* 4_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 2; /* 4_0 */
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 3; /* 6_0 */
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
               else if (!cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 6; /* 28_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 6; /* 28_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 6; /* 28_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 6; /* 28_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      {
         const char cond1 = !HIL_PM0_gateSignalBuffer[3];
         if (cond1)
         {
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 2; /* 4_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 2; /* 4_0 */
                  }
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                     {
                        return 10; /* 37_0 */
                     }
                  }
               }
            }
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (HIL_PM0_gateSignalBuffer[4])
            {
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
            }
         }
         else if (!cond1)
         {
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[4];
               if (cond2)
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
               }
               else if (!cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 6; /* 28_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 6; /* 28_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 6; /* 28_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 6; /* 28_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
         {
            const char cond2 = !HIL_PM0_gateSignalBuffer[4];
            if (cond2)
            {
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 2; /* 4_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 2; /* 4_0 */
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
            }
            else if (!cond2)
            {
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 6; /* 28_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 6; /* 28_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 6; /* 28_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 6; /* 28_0 */
                        }
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
               }
            }
            if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 35_0";
   return 9; /* 35_0 */
}
static const size_t PM0_Ad_37_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_Ad_37_colIdx[] = {
   0,1,2,3
};
static const double PM0_Ad_37_data[] _ALIGN = {
   0.995123042277094694,0.995123042277094694,0.995123042277094694,
   0.0252912239635718593
};
static const size_t PM0_Bd0_37_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd0_37_colIdx[] = {
   0,0,0
};
static const double PM0_Bd0_37_data[] _ALIGN = {
   0.276874085629755518,0.276874085629755518,0.276874085629755518
};
static const size_t PM0_Bd1_37_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd1_37_colIdx[] = {
   0,0,0
};
static const double PM0_Bd1_37_data[] _ALIGN = {
   0.277325655609487021,0.277325655609487021,0.277325655609487021
};
static const size_t PM0_C_0_37_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_C_0_37_colIdx[] = {
   0,1,2
};
static const double PM0_C_0_37_data[] _ALIGN = {
   1.,1.,1.
};
static const size_t PM0_D_0_37_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_37_colIdx[] = {
   0
};
static const double PM0_D_0_37_data[] _ALIGN = {
   0
};
static void PM0_collision_37()
{
}
static size_t PM0_natPreComm_37_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (x[0]+x[1]+x[2] >= 0 && !HIL_PM0_gateSignalBuffer[2])
   {
      {
         const char cond1 = -x[3] > 0 || HIL_PM0_gateSignalBuffer[0];
         if (cond1)
         {
            if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[5])
            {
               return 8; /* 33_0 */
            }
         }
         else if (!cond1)
         {
            if (HIL_PM0_gateSignalBuffer[5])
            {
               return 0; /* 0_0 */
            }
         }
         if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
         {
            return 0; /* 0_0 */
         }
      }
   }
   return 10; /* 37_0 */
}
static size_t PM0_natPostComm_37_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond10 = !HIL_PM0_gateSignalBuffer[5];
      if (cond10)
      {
         if (-x[3] > 0)
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (HIL_PM0_gateSignalBuffer[0])
               {
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 3; /* 6_0 */
               }
            }
         }
         if (x[0]+x[1]+x[2]-200.*x[3] > 0)
         {
            if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  return 7; /* 30_0 */
               }
            }
         }
      }
      else if (!cond10)
      {
         if (!HIL_PM0_gateSignalBuffer[0])
         {
            if (x[0]+x[1]+x[2] > 0)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[4])
                  {
                     return 1; /* 2_0 */
                  }
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[3] > 0)
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (x[0]+x[1]+x[2]-200.*x[3] > 0)
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     return 7; /* 30_0 */
                  }
               }
            }
         }
      }
      if (x[0]+x[1]+x[2] > 0)
      {
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            {
               const char cond5 = x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                                  !HIL_PM0_gateSignalBuffer[5];
               if (cond5)
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 1; /* 2_0 */
                  }
               }
               else if (!cond5)
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 9; /* 35_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 9; /* 35_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
               {
                  return 13; /* 59_0 */
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[4])
      {
         if (!HIL_PM0_gateSignalBuffer[0])
         {
            if (-x[3] > 0)
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  return 3; /* 6_0 */
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
            {
               if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  return 2; /* 4_0 */
               }
            }
         }
         if (x[0]+x[1]+x[2]-200.*x[3] > 0)
         {
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     return 11; /* 39_0 */
                  }
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[3])
      {
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
            {
               if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  return 2; /* 4_0 */
               }
            }
         }
         if (x[0]+x[1]+x[2]-200.*x[3] > 0)
         {
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     return 11; /* 39_0 */
                  }
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (-x[3] > 0)
            {
               return 14; /* 61_0 */
            }
         }
      }
      if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
      {
         if (x[0]+x[1]+x[2]-100.*x[3] > 0)
         {
            if (-x[0]-x[1]-x[2]-50.*x[3] > 0 || HIL_PM0_gateSignalBuffer[2])
            {
               return 15; /* 63_0 */
            }
         }
      }
   }
   return 10; /* 37_0 */
}
static size_t PM0_forcedComm_37_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond0 = !HIL_PM0_gateSignalBuffer[1];
      if (cond0)
      {
         if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
         {
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[4];
               if (cond2)
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                     {
                        return 10; /* 37_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 2; /* 4_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 2; /* 4_0 */
                  }
               }
               else if (!cond2)
               {
                  {
                     const char cond1 = !HIL_PM0_gateSignalBuffer[3];
                     if (cond1)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                     else if (!cond1)
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 6; /* 28_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 6; /* 28_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                  }
               }
               {
                  const char cond1 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond1)
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 2; /* 4_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 2; /* 4_0 */
                     }
                  }
                  else if (!cond1)
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 6; /* 28_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                  }
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 6; /* 28_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                  }
               }
            }
         }
      }
      else if (!cond0)
      {
         {
            const char cond1 = !HIL_PM0_gateSignalBuffer[3];
            if (cond1)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 1; /* 2_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 1; /* 2_0 */
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        return 9; /* 35_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 3; /* 6_0 */
                  }
               }
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        return 11; /* 39_0 */
                     }
                  }
               }
            }
            else if (!cond1)
            {
               if (HIL_PM0_gateSignalBuffer[4])
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 5; /* 26_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 5; /* 26_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 7; /* 30_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 7; /* 30_0 */
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 5; /* 26_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 5; /* 26_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 7; /* 30_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 7; /* 30_0 */
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[4];
               if (cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 1; /* 2_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 1; /* 2_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 3; /* 6_0 */
                     }
                  }
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
               else if (!cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 5; /* 26_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 5; /* 26_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 5; /* 26_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 5; /* 26_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[2])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      {
         const char cond1 = !HIL_PM0_gateSignalBuffer[3];
         if (cond1)
         {
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 1; /* 2_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 1; /* 2_0 */
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        return 9; /* 35_0 */
                     }
                  }
               }
            }
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (HIL_PM0_gateSignalBuffer[4])
            {
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
            }
         }
         else if (!cond1)
         {
            {
               const char cond2 = !HIL_PM0_gateSignalBuffer[4];
               if (cond2)
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 11; /* 39_0 */
                           }
                        }
                     }
                  }
               }
               else if (!cond2)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 5; /* 26_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 5; /* 26_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 5; /* 26_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 5; /* 26_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
         {
            const char cond2 = !HIL_PM0_gateSignalBuffer[4];
            if (cond2)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 1; /* 2_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 1; /* 2_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                  }
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 3; /* 6_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
            }
            else if (!cond2)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 5; /* 26_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 5; /* 26_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[1])
                           {
                              return 15; /* 63_0 */
                           }
                        }
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 5; /* 26_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 5; /* 26_0 */
                        }
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                               HIL_PM0_gateSignalBuffer[5])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
               }
            }
            if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[0])
                        {
                           return 7; /* 30_0 */
                        }
                        if (!HIL_PM0_gateSignalBuffer[5])
                        {
                           return 7; /* 30_0 */
                        }
                     }
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 37_0";
   return 10; /* 37_0 */
}
static const size_t PM0_Ad_39_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_Ad_39_colIdx[] = {
   0,1,2,3
};
static const double PM0_Ad_39_data[] _ALIGN = {
   0.995123042277094694,0.995123042277094694,0.995123042277094694,
   0.0252912239635718593
};
static const size_t PM0_Bd0_39_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd0_39_colIdx[] = {
   0,0,0
};
static const double PM0_Bd0_39_data[] _ALIGN = {
   0.276874085629755518,0.276874085629755518,0.276874085629755518
};
static const size_t PM0_Bd1_39_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd1_39_colIdx[] = {
   0,0,0
};
static const double PM0_Bd1_39_data[] _ALIGN = {
   0.277325655609487021,0.277325655609487021,0.277325655609487021
};
static const size_t PM0_C_0_39_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_C_0_39_colIdx[] = {
   0,1,2
};
static const double PM0_C_0_39_data[] _ALIGN = {
   1.,1.,1.
};
static const size_t PM0_D_0_39_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_39_colIdx[] = {
   0
};
static const double PM0_D_0_39_data[] _ALIGN = {
   0
};
static void PM0_collision_39()
{
}
static size_t PM0_natPreComm_39_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (-x[0]-x[1]-x[2]+200.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[1])
   {
      if (x[0]+x[1]+x[2]+66.6666666666666572*x[3] >= 0 &&
          !HIL_PM0_gateSignalBuffer[2])
      {
         if (HIL_PM0_gateSignalBuffer[5])
         {
            if (HIL_PM0_gateSignalBuffer[0])
            {
               return 8; /* 33_0 */
            }
            else
            {
               return 0; /* 0_0 */
            }
         }
         else
         {
            return 0; /* 0_0 */
         }
      }
   }
   return 11; /* 39_0 */
}
static size_t PM0_natPostComm_39_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond9 = !HIL_PM0_gateSignalBuffer[5];
      if (cond9)
      {
         if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 3; /* 6_0 */
               }
            }
         }
         if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
         {
            if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  return 7; /* 30_0 */
               }
            }
         }
      }
      else if (!cond9)
      {
         if (!HIL_PM0_gateSignalBuffer[0])
         {
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[4])
                  {
                     return 1; /* 2_0 */
                  }
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
            if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
            {
               if (x[0]+x[1]+x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     return 7; /* 30_0 */
                  }
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[2])
      {
         if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            {
               const char cond4 = x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                                  !HIL_PM0_gateSignalBuffer[5];
               if (cond4)
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 1; /* 2_0 */
                  }
               }
               else if (!cond4)
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 9; /* 35_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 9; /* 35_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
               {
                  return 13; /* 59_0 */
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
         {
            {
               const char cond7 = x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5];
               if (cond7)
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
               }
               else if (!cond7)
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 10; /* 37_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 10; /* 37_0 */
                     }
                  }
               }
               if (-x[3] > 0)
               {
                  return 14; /* 61_0 */
               }
            }
         }
      }
      if (-x[0]-x[1]-x[2]-200.*x[3] > 0)
      {
         if (x[0]+x[1]+x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-50.*x[3] > 0 || HIL_PM0_gateSignalBuffer[2])
            {
               return 15; /* 63_0 */
            }
         }
      }
   }
   return 11; /* 39_0 */
}
static size_t PM0_forcedComm_39_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond0 = !HIL_PM0_gateSignalBuffer[3];
      if (cond0)
      {
         if (!HIL_PM0_gateSignalBuffer[0])
         {
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  return 1; /* 2_0 */
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  return 2; /* 4_0 */
               }
            }
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  return 3; /* 6_0 */
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[5])
         {
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  return 1; /* 2_0 */
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  return 2; /* 4_0 */
               }
            }
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  return 3; /* 6_0 */
               }
            }
         }
         if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
         {
            if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     return 11; /* 39_0 */
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     return 9; /* 35_0 */
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                  {
                     return 10; /* 37_0 */
                  }
               }
            }
         }
      }
      else if (!cond0)
      {
         {
            const char cond1 = !HIL_PM0_gateSignalBuffer[4];
            if (cond1)
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
            }
            else if (!cond1)
            {
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        return 7; /* 30_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        return 5; /* 26_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        return 7; /* 30_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        return 5; /* 26_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                  }
               }
            }
         }
      }
      {
         const char cond1 = !HIL_PM0_gateSignalBuffer[4];
         if (cond1)
         {
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     return 1; /* 2_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     return 2; /* 4_0 */
                  }
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     return 1; /* 2_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     return 2; /* 4_0 */
                  }
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        return 9; /* 35_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                     {
                        return 10; /* 37_0 */
                     }
                  }
               }
            }
         }
         else if (!cond1)
         {
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (x[0]+x[1]+x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[0])
         {
            if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[5])
         {
            if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 39_0";
   return 11; /* 39_0 */
}
static const size_t PM0_Ad_57_rowPtr[] = {
   0,2,3,4,5
};
static const size_t PM0_Ad_57_colIdx[] = {
   1,2,1,2,3
};
static const double PM0_Ad_57_data[] _ALIGN = {
   -0.995123042277094694,-0.995123042277094694,0.995123042277094694,
   0.995123042277094694,0.0252912239635718593
};
static const size_t PM0_Bd0_57_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_Bd0_57_colIdx[] = {
   0
};
static const double PM0_Bd0_57_data[] _ALIGN = {
   0
};
static const size_t PM0_Bd1_57_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_Bd1_57_colIdx[] = {
   0
};
static const double PM0_Bd1_57_data[] _ALIGN = {
   0
};
static const size_t PM0_C_0_57_rowPtr[] = {
   0,2,3,4,4
};
static const size_t PM0_C_0_57_colIdx[] = {
   1,2,1,2
};
static const double PM0_C_0_57_data[] _ALIGN = {
   -1.,-1.,1.,1.
};
static const size_t PM0_D_0_57_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_57_colIdx[] = {
   0
};
static const double PM0_D_0_57_data[] _ALIGN = {
   0
};
static void PM0_collision_57()
{
   double * _RESTRICT x = HIL_PM0_x;
   double * _RESTRICT tmpX = HIL_PM0_tmpX;
   tmpX[0] = 0.66666666666666663*x[0]-0.333333333333333315*x[1]-
             0.333333333333333315*x[2];
   tmpX[1] = -0.333333333333333315*x[0]+0.66666666666666663*x[1]-
             0.333333333333333315*x[2];
   tmpX[2] = -0.333333333333333315*x[0]-0.333333333333333315*x[1]+
             0.66666666666666663*x[2];
   x[0] = tmpX[0];
   x[1] = tmpX[1];
   x[2] = tmpX[2];
}
static size_t PM0_natPreComm_57_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   return 12; /* 57_0 */
}
static size_t PM0_natPostComm_57_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond0 = !HIL_PM0_gateSignalBuffer[0];
      if (cond0)
      {
         if (HIL_PM0_gateSignalBuffer[5])
         {
            {
               const char cond13 = -x[3] > 0 || HIL_PM0_gateSignalBuffer[3];
               if (cond13)
               {
                  if (u[0] >= 0 && !HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-u[0] >= 0 && !HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 4; /* 24_0 */
                        }
                     }
                  }
               }
               else if (!cond13)
               {
                  if (HIL_PM0_gateSignalBuffer[4])
                  {
                     if (-x[3]+1.00179998560011496*u[0] > 0)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-u[0] > 0)
                        {
                           return 2; /* 4_0 */
                        }
                     }
                  }
               }
               if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
               {
                  if (-x[3]+1.00179998560011496*u[0] > 0)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        return 1; /* 2_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-u[0] > 0)
                     {
                        return 2; /* 4_0 */
                     }
                  }
               }
            }
         }
         if (x[3]-1.00179998560011518*u[0] >= 0 &&
             !HIL_PM0_gateSignalBuffer[1])
         {
            if (u[0] >= 0 && !HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 0; /* 0_0 */
               }
               else
               {
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 0; /* 0_0 */
                  }
               }
            }
         }
         if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
         {
            if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (u[0] > 0)
                  {
                     return 5; /* 26_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-u[0] > 0)
                  {
                     return 6; /* 28_0 */
                  }
               }
            }
         }
      }
      else if (!cond0)
      {
         if (!HIL_PM0_gateSignalBuffer[5])
         {
            if (x[3]-1.00179998560011518*u[0] >= 0 &&
                !HIL_PM0_gateSignalBuffer[1])
            {
               if (u[0] >= 0 && !HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 0; /* 0_0 */
                  }
                  else
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 0; /* 0_0 */
                     }
                  }
               }
            }
            if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (u[0] > 0)
                     {
                        return 5; /* 26_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-u[0] > 0)
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
            }
         }
      }
      {
         const char cond8 = x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5];
         if (cond8)
         {
            {
               const char cond3 = !HIL_PM0_gateSignalBuffer[3];
               if (cond3)
               {
                  if (HIL_PM0_gateSignalBuffer[4])
                  {
                     if (-x[3]+1.00179998560011496*u[0] > 0)
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-u[0] > 0)
                     {
                        return 2; /* 4_0 */
                     }
                  }
               }
               else if (!cond3)
               {
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-u[0] > 0)
                        {
                           return 2; /* 4_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  if (-x[3]+1.00179998560011496*u[0] > 0)
                  {
                     if (!HIL_PM0_gateSignalBuffer[2])
                     {
                        return 1; /* 2_0 */
                     }
                  }
               }
            }
         }
         else if (!cond8)
         {
            if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
            {
               {
                  const char cond3 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond3)
                  {
                     if (u[0] >= 0 && !HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-u[0] >= 0 && !HIL_PM0_gateSignalBuffer[1])
                        {
                           return 8; /* 33_0 */
                        }
                     }
                     if (HIL_PM0_gateSignalBuffer[4])
                     {
                        if (!HIL_PM0_gateSignalBuffer[2])
                        {
                           if (u[0] > 0)
                           {
                              return 9; /* 35_0 */
                           }
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-u[0] > 0)
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
                  else if (!cond3)
                  {
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        if (u[0] >= 0 && !HIL_PM0_gateSignalBuffer[2])
                        {
                           if (-u[0] >= 0 && !HIL_PM0_gateSignalBuffer[1])
                           {
                              return 8; /* 33_0 */
                           }
                        }
                        if (!HIL_PM0_gateSignalBuffer[1])
                        {
                           if (-u[0] > 0)
                           {
                              return 10; /* 37_0 */
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (u[0] > 0)
                     {
                        if (!HIL_PM0_gateSignalBuffer[4])
                        {
                           return 9; /* 35_0 */
                        }
                        if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 13; /* 59_0 */
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-u[0] > 0)
                     {
                        if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
               }
            }
         }
         if (u[0] >= 0 && !HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (-u[0] >= 0 && !HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 4; /* 24_0 */
                     }
                  }
               }
            }
         }
         if (-x[3] > 0)
         {
            return 15; /* 63_0 */
         }
      }
   }
   return 12; /* 57_0 */
}
static size_t PM0_forcedComm_57_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond0 = !HIL_PM0_gateSignalBuffer[1];
      if (cond0)
      {
         {
            const char cond1 = !HIL_PM0_gateSignalBuffer[2];
            if (cond1)
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 12; /* 57_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 8; /* 33_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 8; /* 33_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 4; /* 24_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 0; /* 0_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 0; /* 0_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 4; /* 24_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 0; /* 0_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 0; /* 0_0 */
                  }
               }
            }
            else if (!cond1)
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 10; /* 37_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 10; /* 37_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 2; /* 4_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 10; /* 37_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 10; /* 37_0 */
                     }
                  }
               }
            }
         }
      }
      else if (!cond0)
      {
         {
            const char cond1 = !HIL_PM0_gateSignalBuffer[2];
            if (cond1)
            {
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 1; /* 2_0 */
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 1; /* 2_0 */
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 9; /* 35_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 9; /* 35_0 */
                     }
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
               }
            }
            else if (!cond1)
            {
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 11; /* 39_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 11; /* 39_0 */
                     }
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 7; /* 30_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 11; /* 39_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 11; /* 39_0 */
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
         }
      }
      {
         const char cond1 = !HIL_PM0_gateSignalBuffer[2];
         if (cond1)
         {
            if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 1; /* 2_0 */
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 1; /* 2_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 1; /* 2_0 */
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 9; /* 35_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 9; /* 35_0 */
                     }
                  }
               }
            }
         }
         else if (!cond1)
         {
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 7; /* 30_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 11; /* 39_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 11; /* 39_0 */
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
         }
         if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[0])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 3; /* 6_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
         }
         if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     if (!HIL_PM0_gateSignalBuffer[0])
                     {
                        return 7; /* 30_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[5])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        return 11; /* 39_0 */
                     }
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 11; /* 39_0 */
                     }
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 57_0";
   return 12; /* 57_0 */
}
static const size_t PM0_Ad_59_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_Ad_59_colIdx[] = {
   0,1,2,3
};
static const double PM0_Ad_59_data[] _ALIGN = {
   0.995123042277094694,0.995123042277094694,0.995123042277094694,
   0.0252912239635718593
};
static const size_t PM0_Bd0_59_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd0_59_colIdx[] = {
   0,0,0
};
static const double PM0_Bd0_59_data[] _ALIGN = {
   0.276874085629755518,0.276874085629755518,0.276874085629755518
};
static const size_t PM0_Bd1_59_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd1_59_colIdx[] = {
   0,0,0
};
static const double PM0_Bd1_59_data[] _ALIGN = {
   0.277325655609487021,0.277325655609487021,0.277325655609487021
};
static const size_t PM0_C_0_59_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_C_0_59_colIdx[] = {
   0,1,2
};
static const double PM0_C_0_59_data[] _ALIGN = {
   1.,1.,1.
};
static const size_t PM0_D_0_59_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_59_colIdx[] = {
   0
};
static const double PM0_D_0_59_data[] _ALIGN = {
   0
};
static void PM0_collision_59()
{
}
static size_t PM0_natPreComm_59_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (-x[0]-x[1]-x[2] >= 0 && !HIL_PM0_gateSignalBuffer[1])
   {
      {
         const char cond6 = HIL_PM0_gateSignalBuffer[4];
         if (cond6)
         {
            {
               const char cond5 = HIL_PM0_gateSignalBuffer[3];
               if (cond5)
               {
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[0])
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        return 4; /* 24_0 */
                     }
                  }
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[5])
                  {
                     return 4; /* 24_0 */
                  }
               }
               else if (!cond5)
               {
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[5])
                  {
                     return 0; /* 0_0 */
                  }
               }
               if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                   !HIL_PM0_gateSignalBuffer[3])
               {
                  if (HIL_PM0_gateSignalBuffer[5])
                  {
                     if (HIL_PM0_gateSignalBuffer[0])
                     {
                        return 8; /* 33_0 */
                     }
                     else
                     {
                        return 0; /* 0_0 */
                     }
                  }
               }
            }
         }
         else if (!cond6)
         {
            if (x[0]+x[1]+x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
            {
               return 0; /* 0_0 */
            }
         }
         if (-x[0]-x[1]-x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     return 12; /* 57_0 */
                  }
               }
            }
         }
         else
         {
            if (HIL_PM0_gateSignalBuffer[5])
            {
               if (HIL_PM0_gateSignalBuffer[0])
               {
                  return 8; /* 33_0 */
               }
               else
               {
                  return 0; /* 0_0 */
               }
            }
         }
      }
   }
   return 13; /* 59_0 */
}
static size_t PM0_natPostComm_59_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond0 = !HIL_PM0_gateSignalBuffer[0];
      if (cond0)
      {
         if (HIL_PM0_gateSignalBuffer[5])
         {
            {
               const char cond3 = !HIL_PM0_gateSignalBuffer[4];
               if (cond3)
               {
                  if (HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
                     {
                        if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
               }
               else if (!cond3)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                            !HIL_PM0_gateSignalBuffer[3])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] > 0)
                     {
                        if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
                        {
                           return 2; /* 4_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                         !HIL_PM0_gateSignalBuffer[4])
                     {
                        return 1; /* 2_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
                  {
                     if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] > 0)
                  {
                     if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
                     {
                        return 2; /* 4_0 */
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               {
                  const char cond3 = !HIL_PM0_gateSignalBuffer[4];
                  if (cond3)
                  {
                     if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                         !HIL_PM0_gateSignalBuffer[5])
                     {
                        return 1; /* 2_0 */
                     }
                  }
                  else if (!cond3)
                  {
                     if (!HIL_PM0_gateSignalBuffer[3])
                     {
                        if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                            !HIL_PM0_gateSignalBuffer[5])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2] > 0)
            {
               if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     return 6; /* 28_0 */
                  }
               }
            }
         }
         if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0)
         {
            if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 7; /* 30_0 */
                  }
               }
            }
         }
      }
      else if (!cond0)
      {
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                         !HIL_PM0_gateSignalBuffer[5])
                     {
                        return 1; /* 2_0 */
                     }
                  }
                  else if (!cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                            !HIL_PM0_gateSignalBuffer[5])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[5])
         {
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] > 0)
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0)
            {
               if (x[0]+x[1]+x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
            }
         }
      }
      {
         const char cond2 = !HIL_PM0_gateSignalBuffer[3];
         if (cond2)
         {
            if (HIL_PM0_gateSignalBuffer[4])
            {
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] > 0)
                  {
                     if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
                     {
                        return 2; /* 4_0 */
                     }
                     else
                     {
                        if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        return 9; /* 35_0 */
                     }
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
            {
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0)
            {
               if (x[0]+x[1]+x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        return 11; /* 39_0 */
                     }
                  }
               }
            }
         }
         else if (!cond2)
         {
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] > 0)
               {
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0)
               {
                  if (x[0]+x[1]+x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2] > 0)
            {
               if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 2; /* 4_0 */
                  }
               }
               else
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
                  {
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 10; /* 37_0 */
                     }
                     if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 14; /* 61_0 */
                        }
                     }
                  }
               }
            }
         }
         if (-x[0]-x[1]-x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
         {
            if (-x[0]-x[1]-x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-50.*x[3] > 0)
                     {
                        if (x[0]+x[1]+x[2]-100.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[1])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
         }
      }
   }
   return 13; /* 59_0 */
}
static size_t PM0_forcedComm_59_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond0 = !HIL_PM0_gateSignalBuffer[2];
      if (cond0)
      {
         if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 13; /* 59_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 9; /* 35_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 9; /* 35_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 5; /* 26_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 1; /* 2_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 1; /* 2_0 */
               }
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 5; /* 26_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 1; /* 2_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 1; /* 2_0 */
               }
            }
         }
      }
      else if (!cond0)
      {
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 2; /* 4_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 2; /* 4_0 */
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     return 6; /* 28_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 2; /* 4_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 2; /* 4_0 */
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     return 6; /* 28_0 */
                  }
               }
            }
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 10; /* 37_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 10; /* 37_0 */
                  }
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 14; /* 61_0 */
                     }
                  }
               }
            }
         }
         if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 3; /* 6_0 */
               }
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 3; /* 6_0 */
               }
            }
         }
         if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 7; /* 30_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 7; /* 30_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 11; /* 39_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 11; /* 39_0 */
                  }
               }
            }
         }
         if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
         {
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (x[0]+x[1]+x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[1])
                     {
                        return 15; /* 63_0 */
                     }
                  }
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 2; /* 4_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 2; /* 4_0 */
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     return 6; /* 28_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 2; /* 4_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 2; /* 4_0 */
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     return 6; /* 28_0 */
                  }
               }
            }
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 10; /* 37_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 10; /* 37_0 */
                  }
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 14; /* 61_0 */
                     }
                  }
               }
            }
         }
      }
      if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 3; /* 6_0 */
               }
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 3; /* 6_0 */
               }
            }
         }
      }
      if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
             HIL_PM0_gateSignalBuffer[2])
         {
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 7; /* 30_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 7; /* 30_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 11; /* 39_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 11; /* 39_0 */
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 59_0";
   return 13; /* 59_0 */
}
static const size_t PM0_Ad_61_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_Ad_61_colIdx[] = {
   0,1,2,3
};
static const double PM0_Ad_61_data[] _ALIGN = {
   0.995123042277094694,0.995123042277094694,0.995123042277094694,
   0.0252912239635718593
};
static const size_t PM0_Bd0_61_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd0_61_colIdx[] = {
   0,0,0
};
static const double PM0_Bd0_61_data[] _ALIGN = {
   0.276874085629755518,0.276874085629755518,0.276874085629755518
};
static const size_t PM0_Bd1_61_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd1_61_colIdx[] = {
   0,0,0
};
static const double PM0_Bd1_61_data[] _ALIGN = {
   0.277325655609487021,0.277325655609487021,0.277325655609487021
};
static const size_t PM0_C_0_61_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_C_0_61_colIdx[] = {
   0,1,2
};
static const double PM0_C_0_61_data[] _ALIGN = {
   1.,1.,1.
};
static const size_t PM0_D_0_61_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_61_colIdx[] = {
   0
};
static const double PM0_D_0_61_data[] _ALIGN = {
   0
};
static void PM0_collision_61()
{
}
static size_t PM0_natPreComm_61_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (x[0]+x[1]+x[2] >= 0 && !HIL_PM0_gateSignalBuffer[2])
   {
      {
         const char cond6 = HIL_PM0_gateSignalBuffer[4];
         if (cond6)
         {
            {
               const char cond5 = HIL_PM0_gateSignalBuffer[3];
               if (cond5)
               {
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[0])
                  {
                     if (HIL_PM0_gateSignalBuffer[5])
                     {
                        return 4; /* 24_0 */
                     }
                  }
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
                  {
                     return 4; /* 24_0 */
                  }
               }
               else if (!cond5)
               {
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
                  {
                     return 0; /* 0_0 */
                  }
               }
               if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
               {
                  if (HIL_PM0_gateSignalBuffer[5])
                  {
                     if (HIL_PM0_gateSignalBuffer[0])
                     {
                        return 8; /* 33_0 */
                     }
                     else
                     {
                        return 0; /* 0_0 */
                     }
                  }
               }
            }
         }
         else if (!cond6)
         {
            if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
            {
               return 0; /* 0_0 */
            }
         }
         if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
         {
            if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[5])
                  {
                     return 12; /* 57_0 */
                  }
               }
            }
         }
         else
         {
            if (HIL_PM0_gateSignalBuffer[5])
            {
               if (HIL_PM0_gateSignalBuffer[0])
               {
                  return 8; /* 33_0 */
               }
               else
               {
                  return 0; /* 0_0 */
               }
            }
         }
      }
   }
   return 14; /* 61_0 */
}
static size_t PM0_natPostComm_61_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond0 = !HIL_PM0_gateSignalBuffer[0];
      if (cond0)
      {
         if (HIL_PM0_gateSignalBuffer[5])
         {
            if (x[0]+x[1]+x[2] > 0)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  {
                     const char cond12 = -x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                                         HIL_PM0_gateSignalBuffer[3];
                     if (cond12)
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                     else if (!cond12)
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                     if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                         !HIL_PM0_gateSignalBuffer[4])
                     {
                        return 1; /* 2_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  {
                     const char cond14 = -x[3] > 0 ||
                                         HIL_PM0_gateSignalBuffer[3];
                     if (cond14)
                     {
                        if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                     else if (!cond14)
                     {
                        if (HIL_PM0_gateSignalBuffer[4])
                        {
                           return 2; /* 4_0 */
                        }
                     }
                     if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[4])
                     {
                        return 2; /* 4_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[3] > 0)
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            else
            {
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  if (-x[3] > 0)
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
            }
         }
         if (x[0]+x[1]+x[2] > 0)
         {
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[5])
                  {
                     return 1; /* 2_0 */
                  }
               }
               else
               {
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                         !HIL_PM0_gateSignalBuffer[5])
                     {
                        return 1; /* 2_0 */
                     }
                  }
               }
            }
         }
         if (x[0]+x[1]+x[2]-200.*x[3] > 0)
         {
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 7; /* 30_0 */
                  }
               }
            }
         }
      }
      else if (!cond0)
      {
         if (x[0]+x[1]+x[2] > 0)
         {
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[5])
                  {
                     return 1; /* 2_0 */
                  }
               }
               else
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                         !HIL_PM0_gateSignalBuffer[5])
                     {
                        return 1; /* 2_0 */
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[5])
         {
            if (x[0]+x[1]+x[2]-200.*x[3] > 0)
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
            }
         }
      }
      {
         const char cond3 = !HIL_PM0_gateSignalBuffer[3];
         if (cond3)
         {
            if (HIL_PM0_gateSignalBuffer[4])
            {
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        return 2; /* 4_0 */
                     }
                  }
               }
               if (-x[3] > 0)
               {
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
            }
            if (x[0]+x[1]+x[2] > 0)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        return 9; /* 35_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        return 10; /* 37_0 */
                     }
                  }
               }
            }
            if (x[0]+x[1]+x[2]-200.*x[3] > 0)
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        return 11; /* 39_0 */
                     }
                  }
               }
            }
         }
         else if (!cond3)
         {
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               if (x[0]+x[1]+x[2] > 0)
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
               }
               if (x[0]+x[1]+x[2]-200.*x[3] > 0)
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[5])
         {
            if (x[0]+x[1]+x[2] > 0)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               if (-x[3] > 0)
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 6; /* 28_0 */
                     }
                  }
               }
            }
         }
         if (x[0]+x[1]+x[2] > 0)
         {
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[4])
         {
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     return 2; /* 4_0 */
                  }
               }
            }
         }
         if (-x[0]-x[1]-x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
         {
            if (-x[0]-x[1]-x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (x[0]+x[1]+x[2]-100.*x[3] > 0)
                     {
                        if (-x[0]-x[1]-x[2]-50.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 15; /* 63_0 */
                        }
                     }
                  }
               }
            }
         }
      }
   }
   return 14; /* 61_0 */
}
static size_t PM0_forcedComm_61_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond0 = !HIL_PM0_gateSignalBuffer[1];
      if (cond0)
      {
         if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        return 14; /* 61_0 */
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 10; /* 37_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 10; /* 37_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     return 6; /* 28_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 2; /* 4_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 2; /* 4_0 */
               }
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     return 6; /* 28_0 */
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 2; /* 4_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 2; /* 4_0 */
               }
            }
         }
      }
      else if (!cond0)
      {
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 1; /* 2_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 1; /* 2_0 */
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 5; /* 26_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 1; /* 2_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 1; /* 2_0 */
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 5; /* 26_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 9; /* 35_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 9; /* 35_0 */
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 13; /* 59_0 */
                     }
                  }
               }
            }
         }
         if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 3; /* 6_0 */
               }
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 3; /* 6_0 */
               }
            }
         }
         if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
             HIL_PM0_gateSignalBuffer[2])
         {
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 7; /* 30_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 7; /* 30_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 11; /* 39_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 11; /* 39_0 */
                  }
               }
            }
         }
         if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
         {
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[0])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        return 15; /* 63_0 */
                     }
                  }
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[2])
      {
         if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 1; /* 2_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 1; /* 2_0 */
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 5; /* 26_0 */
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 1; /* 2_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 1; /* 2_0 */
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 5; /* 26_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 9; /* 35_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 9; /* 35_0 */
                  }
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 13; /* 59_0 */
                     }
                  }
               }
            }
         }
      }
      if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[0])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 3; /* 6_0 */
               }
            }
            if (!HIL_PM0_gateSignalBuffer[5])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 3; /* 6_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 3; /* 6_0 */
               }
            }
         }
      }
      if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
             HIL_PM0_gateSignalBuffer[2])
         {
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  if (!HIL_PM0_gateSignalBuffer[0])
                  {
                     return 7; /* 30_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     return 7; /* 30_0 */
                  }
               }
            }
            if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     return 11; /* 39_0 */
                  }
                  if (!HIL_PM0_gateSignalBuffer[4])
                  {
                     return 11; /* 39_0 */
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 61_0";
   return 14; /* 61_0 */
}
static const size_t PM0_Ad_63_rowPtr[] = {
   0,1,2,3,4
};
static const size_t PM0_Ad_63_colIdx[] = {
   0,1,2,3
};
static const double PM0_Ad_63_data[] _ALIGN = {
   0.995123042277094694,0.995123042277094694,0.995123042277094694,
   0.0252912239635718593
};
static const size_t PM0_Bd0_63_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd0_63_colIdx[] = {
   0,0,0
};
static const double PM0_Bd0_63_data[] _ALIGN = {
   0.276874085629755518,0.276874085629755518,0.276874085629755518
};
static const size_t PM0_Bd1_63_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_Bd1_63_colIdx[] = {
   0,0,0
};
static const double PM0_Bd1_63_data[] _ALIGN = {
   0.277325655609487021,0.277325655609487021,0.277325655609487021
};
static const size_t PM0_C_0_63_rowPtr[] = {
   0,1,2,3,3
};
static const size_t PM0_C_0_63_colIdx[] = {
   0,1,2
};
static const double PM0_C_0_63_data[] _ALIGN = {
   1.,1.,1.
};
static const size_t PM0_D_0_63_rowPtr[] = {
   0,0,0,0,0
};
static const size_t PM0_D_0_63_colIdx[] = {
   0
};
static const double PM0_D_0_63_data[] _ALIGN = {
   0
};
static void PM0_collision_63()
{
}
static size_t PM0_natPreComm_63_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (-x[0]-x[1]-x[2]+100.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[1])
   {
      if (x[0]+x[1]+x[2]+50.*x[3] >= 0 && !HIL_PM0_gateSignalBuffer[2])
      {
         if (HIL_PM0_gateSignalBuffer[4])
         {
            if (HIL_PM0_gateSignalBuffer[3])
            {
               if (HIL_PM0_gateSignalBuffer[5])
               {
                  if (HIL_PM0_gateSignalBuffer[0])
                  {
                     return 12; /* 57_0 */
                  }
                  else
                  {
                     return 4; /* 24_0 */
                  }
               }
               else
               {
                  return 4; /* 24_0 */
               }
            }
            else
            {
               if (HIL_PM0_gateSignalBuffer[0])
               {
                  if (HIL_PM0_gateSignalBuffer[5])
                  {
                     return 8; /* 33_0 */
                  }
                  else
                  {
                     return 0; /* 0_0 */
                  }
               }
               else
               {
                  return 0; /* 0_0 */
               }
            }
         }
         else
         {
            if (HIL_PM0_gateSignalBuffer[5])
            {
               if (HIL_PM0_gateSignalBuffer[0])
               {
                  return 8; /* 33_0 */
               }
               else
               {
                  return 0; /* 0_0 */
               }
            }
            else
            {
               return 0; /* 0_0 */
            }
         }
      }
   }
   return 15; /* 63_0 */
}
static size_t PM0_natPostComm_63_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   {
      const char cond0 = !HIL_PM0_gateSignalBuffer[0];
      if (cond0)
      {
         {
            const char cond3 = !HIL_PM0_gateSignalBuffer[4];
            if (cond3)
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                      !HIL_PM0_gateSignalBuffer[5])
                  {
                     if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        return 1; /* 2_0 */
                     }
                  }
               }
               if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            else if (!cond3)
            {
               if (HIL_PM0_gateSignalBuffer[5])
               {
                  if (!HIL_PM0_gateSignalBuffer[2])
                  {
                     if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                            !HIL_PM0_gateSignalBuffer[3])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[2])
                        {
                           return 3; /* 6_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[3])
                        {
                           return 2; /* 4_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (!HIL_PM0_gateSignalBuffer[3])
                  {
                     if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                         !HIL_PM0_gateSignalBuffer[5])
                     {
                        if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                  }
               }
            }
            if (HIL_PM0_gateSignalBuffer[5])
            {
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                     else
                     {
                        return 2; /* 4_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                         !HIL_PM0_gateSignalBuffer[4])
                     {
                        return 1; /* 2_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 5; /* 26_0 */
                     }
                  }
               }
            }
            if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
            }
         }
      }
      else if (!cond0)
      {
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               {
                  const char cond2 = !HIL_PM0_gateSignalBuffer[3];
                  if (cond2)
                  {
                     if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                         !HIL_PM0_gateSignalBuffer[5])
                     {
                        return 1; /* 2_0 */
                     }
                  }
                  else if (!cond2)
                  {
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        if (x[0]+x[1]+x[2]+100.*x[3] >= 0 &&
                            !HIL_PM0_gateSignalBuffer[5])
                        {
                           return 1; /* 2_0 */
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[4])
                        {
                           return 5; /* 26_0 */
                        }
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[5])
         {
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     return 3; /* 6_0 */
                  }
               }
            }
            if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        return 7; /* 30_0 */
                     }
                  }
               }
            }
         }
      }
      {
         const char cond2 = !HIL_PM0_gateSignalBuffer[3];
         if (cond2)
         {
            if (HIL_PM0_gateSignalBuffer[4])
            {
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (x[3] >= 0 && !HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        return 2; /* 4_0 */
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[2])
                     {
                        return 3; /* 6_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[5])
               {
                  if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        return 9; /* 35_0 */
                     }
                  }
               }
            }
            if (!HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[5])
               {
                  if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
                     {
                        return 10; /* 37_0 */
                     }
                  }
               }
            }
            if (x[0]+x[1]+x[2]-200.*x[3] > 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[0])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[5])
                     {
                        return 11; /* 39_0 */
                     }
                  }
               }
            }
         }
         else if (!cond2)
         {
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               if (!HIL_PM0_gateSignalBuffer[2])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[5])
                  {
                     if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           return 9; /* 35_0 */
                        }
                     }
                  }
               }
               if (!HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
                     {
                        if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
                        {
                           return 10; /* 37_0 */
                        }
                     }
                  }
               }
               if (x[0]+x[1]+x[2]-200.*x[3] > 0 ||
                   HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[2])
                  {
                     if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[0])
                     {
                        if (-x[0]-x[1]-x[2]-200.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[5])
                        {
                           return 11; /* 39_0 */
                        }
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2] > 0 || HIL_PM0_gateSignalBuffer[2])
            {
               {
                  const char cond7 = x[3] >= 0 &&
                                     !HIL_PM0_gateSignalBuffer[5];
                  if (cond7)
                  {
                     if (!HIL_PM0_gateSignalBuffer[4])
                     {
                        return 2; /* 4_0 */
                     }
                  }
                  else if (!cond7)
                  {
                     if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[0])
                           {
                              return 14; /* 61_0 */
                           }
                        }
                     }
                  }
                  if (!HIL_PM0_gateSignalBuffer[5])
                  {
                     if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[3])
                     {
                        if (-x[3] > 0 || HIL_PM0_gateSignalBuffer[4])
                        {
                           return 6; /* 28_0 */
                        }
                     }
                  }
               }
            }
         }
         if (!HIL_PM0_gateSignalBuffer[2])
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] > 0 || HIL_PM0_gateSignalBuffer[5])
            {
               if (x[0]+x[1]+x[2] > 0 || HIL_PM0_gateSignalBuffer[1])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                      HIL_PM0_gateSignalBuffer[3])
                  {
                     if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                         HIL_PM0_gateSignalBuffer[4])
                     {
                        if (-x[0]-x[1]-x[2]-100.*x[3] > 0 ||
                            HIL_PM0_gateSignalBuffer[0])
                        {
                           return 13; /* 59_0 */
                        }
                     }
                  }
               }
            }
         }
      }
   }
   return 15; /* 63_0 */
}
static size_t PM0_forcedComm_63_0()
{
   const double * const x = HIL_PM0_x;
   const double * const u = HIL_PM0_u;
   if (!HIL_PM0_gateSignalBuffer[0])
   {
      if (!HIL_PM0_gateSignalBuffer[2])
      {
         if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 1; /* 2_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 1; /* 2_0 */
            }
            if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  return 5; /* 26_0 */
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 2; /* 4_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 2; /* 4_0 */
            }
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
               {
                  return 6; /* 28_0 */
               }
            }
         }
      }
      if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 3; /* 6_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 3; /* 6_0 */
            }
         }
      }
      if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
      {
         if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
         {
            if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  return 7; /* 30_0 */
               }
            }
         }
      }
   }
   if (!HIL_PM0_gateSignalBuffer[5])
   {
      if (!HIL_PM0_gateSignalBuffer[2])
      {
         if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 1; /* 2_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 1; /* 2_0 */
            }
            if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[4])
               {
                  return 5; /* 26_0 */
               }
            }
         }
      }
      if (!HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 2; /* 4_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 2; /* 4_0 */
            }
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
            {
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
               {
                  return 6; /* 28_0 */
               }
            }
         }
      }
      if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[2])
         {
            if (!HIL_PM0_gateSignalBuffer[3])
            {
               return 3; /* 6_0 */
            }
            if (!HIL_PM0_gateSignalBuffer[4])
            {
               return 3; /* 6_0 */
            }
         }
      }
      if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
      {
         if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
         {
            if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
            {
               if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[2])
               {
                  return 7; /* 30_0 */
               }
            }
         }
      }
   }
   if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
   {
      if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
      {
         if (x[0]+x[1]+x[2]-200.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-66.6666666666666572*x[3] >= 0 ||
                HIL_PM0_gateSignalBuffer[2])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 11; /* 39_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 11; /* 39_0 */
               }
            }
         }
         if (x[0]+x[1]+x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[1])
         {
            if (-x[0]-x[1]-x[2]-50.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[2])
            {
               if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-200.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 15; /* 63_0 */
                  }
               }
            }
         }
      }
   }
   if (!HIL_PM0_gateSignalBuffer[2])
   {
      if (x[0]+x[1]+x[2] >= 0 || HIL_PM0_gateSignalBuffer[1])
      {
         if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
         {
            if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 9; /* 35_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 9; /* 35_0 */
               }
               if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                   HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[0]-x[1]-x[2]-100.*x[3] >= 0 ||
                      HIL_PM0_gateSignalBuffer[4])
                  {
                     return 13; /* 59_0 */
                  }
               }
            }
         }
      }
   }
   if (!HIL_PM0_gateSignalBuffer[1])
   {
      if (-x[0]-x[1]-x[2] >= 0 || HIL_PM0_gateSignalBuffer[2])
      {
         if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[0])
         {
            if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[5])
            {
               if (!HIL_PM0_gateSignalBuffer[3])
               {
                  return 10; /* 37_0 */
               }
               if (!HIL_PM0_gateSignalBuffer[4])
               {
                  return 10; /* 37_0 */
               }
               if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[3])
               {
                  if (-x[3] >= 0 || HIL_PM0_gateSignalBuffer[4])
                  {
                     return 14; /* 61_0 */
                  }
               }
            }
         }
      }
   }
   HIL_errorStatus =
      "Illegal transition conditions in forced commutation for topology 63_0";
   return 15; /* 63_0 */
}
static const size_t * const PM0_Ad_rowPtr[] = {
   PM0_Ad_0_rowPtr,PM0_Ad_2_rowPtr,PM0_Ad_4_rowPtr,PM0_Ad_6_rowPtr,
   PM0_Ad_24_rowPtr,PM0_Ad_26_rowPtr,PM0_Ad_28_rowPtr,PM0_Ad_30_rowPtr,
   PM0_Ad_33_rowPtr,PM0_Ad_35_rowPtr,PM0_Ad_37_rowPtr,PM0_Ad_39_rowPtr,
   PM0_Ad_57_rowPtr,PM0_Ad_59_rowPtr,PM0_Ad_61_rowPtr,PM0_Ad_63_rowPtr
};
static const size_t * const PM0_Ad_colIdx[] = {
   PM0_Ad_0_colIdx,PM0_Ad_2_colIdx,PM0_Ad_4_colIdx,PM0_Ad_6_colIdx,
   PM0_Ad_24_colIdx,PM0_Ad_26_colIdx,PM0_Ad_28_colIdx,PM0_Ad_30_colIdx,
   PM0_Ad_33_colIdx,PM0_Ad_35_colIdx,PM0_Ad_37_colIdx,PM0_Ad_39_colIdx,
   PM0_Ad_57_colIdx,PM0_Ad_59_colIdx,PM0_Ad_61_colIdx,PM0_Ad_63_colIdx
};
static const double * const HIL_PM0_Ad_data[] = {
   PM0_Ad_0_data,PM0_Ad_2_data,PM0_Ad_4_data,PM0_Ad_6_data,PM0_Ad_24_data,
   PM0_Ad_26_data,PM0_Ad_28_data,PM0_Ad_30_data,PM0_Ad_33_data,PM0_Ad_35_data,
   PM0_Ad_37_data,PM0_Ad_39_data,PM0_Ad_57_data,PM0_Ad_59_data,PM0_Ad_61_data,
   PM0_Ad_63_data
};
static const size_t * const PM0_Bd0_rowPtr[] = {
   PM0_Bd0_0_rowPtr,PM0_Bd0_2_rowPtr,PM0_Bd0_4_rowPtr,PM0_Bd0_6_rowPtr,
   PM0_Bd0_24_rowPtr,PM0_Bd0_26_rowPtr,PM0_Bd0_28_rowPtr,PM0_Bd0_30_rowPtr,
   PM0_Bd0_33_rowPtr,PM0_Bd0_35_rowPtr,PM0_Bd0_37_rowPtr,PM0_Bd0_39_rowPtr,
   PM0_Bd0_57_rowPtr,PM0_Bd0_59_rowPtr,PM0_Bd0_61_rowPtr,PM0_Bd0_63_rowPtr
};
static const size_t * const PM0_Bd0_colIdx[] = {
   PM0_Bd0_0_colIdx,PM0_Bd0_2_colIdx,PM0_Bd0_4_colIdx,PM0_Bd0_6_colIdx,
   PM0_Bd0_24_colIdx,PM0_Bd0_26_colIdx,PM0_Bd0_28_colIdx,PM0_Bd0_30_colIdx,
   PM0_Bd0_33_colIdx,PM0_Bd0_35_colIdx,PM0_Bd0_37_colIdx,PM0_Bd0_39_colIdx,
   PM0_Bd0_57_colIdx,PM0_Bd0_59_colIdx,PM0_Bd0_61_colIdx,PM0_Bd0_63_colIdx
};
static const double * const HIL_PM0_Bd0_data[] = {
   PM0_Bd0_0_data,PM0_Bd0_2_data,PM0_Bd0_4_data,PM0_Bd0_6_data,
   PM0_Bd0_24_data,PM0_Bd0_26_data,PM0_Bd0_28_data,PM0_Bd0_30_data,
   PM0_Bd0_33_data,PM0_Bd0_35_data,PM0_Bd0_37_data,PM0_Bd0_39_data,
   PM0_Bd0_57_data,PM0_Bd0_59_data,PM0_Bd0_61_data,PM0_Bd0_63_data
};
static const size_t * const PM0_Bd1_rowPtr[] = {
   PM0_Bd1_0_rowPtr,PM0_Bd1_2_rowPtr,PM0_Bd1_4_rowPtr,PM0_Bd1_6_rowPtr,
   PM0_Bd1_24_rowPtr,PM0_Bd1_26_rowPtr,PM0_Bd1_28_rowPtr,PM0_Bd1_30_rowPtr,
   PM0_Bd1_33_rowPtr,PM0_Bd1_35_rowPtr,PM0_Bd1_37_rowPtr,PM0_Bd1_39_rowPtr,
   PM0_Bd1_57_rowPtr,PM0_Bd1_59_rowPtr,PM0_Bd1_61_rowPtr,PM0_Bd1_63_rowPtr
};
static const size_t * const PM0_Bd1_colIdx[] = {
   PM0_Bd1_0_colIdx,PM0_Bd1_2_colIdx,PM0_Bd1_4_colIdx,PM0_Bd1_6_colIdx,
   PM0_Bd1_24_colIdx,PM0_Bd1_26_colIdx,PM0_Bd1_28_colIdx,PM0_Bd1_30_colIdx,
   PM0_Bd1_33_colIdx,PM0_Bd1_35_colIdx,PM0_Bd1_37_colIdx,PM0_Bd1_39_colIdx,
   PM0_Bd1_57_colIdx,PM0_Bd1_59_colIdx,PM0_Bd1_61_colIdx,PM0_Bd1_63_colIdx
};
static const double * const HIL_PM0_Bd1_data[] = {
   PM0_Bd1_0_data,PM0_Bd1_2_data,PM0_Bd1_4_data,PM0_Bd1_6_data,
   PM0_Bd1_24_data,PM0_Bd1_26_data,PM0_Bd1_28_data,PM0_Bd1_30_data,
   PM0_Bd1_33_data,PM0_Bd1_35_data,PM0_Bd1_37_data,PM0_Bd1_39_data,
   PM0_Bd1_57_data,PM0_Bd1_59_data,PM0_Bd1_61_data,PM0_Bd1_63_data
};
static const size_t * const PM0_C_0_rowPtr[] = {
   PM0_C_0_0_rowPtr,PM0_C_0_2_rowPtr,PM0_C_0_4_rowPtr,PM0_C_0_6_rowPtr,
   PM0_C_0_24_rowPtr,PM0_C_0_26_rowPtr,PM0_C_0_28_rowPtr,PM0_C_0_30_rowPtr,
   PM0_C_0_33_rowPtr,PM0_C_0_35_rowPtr,PM0_C_0_37_rowPtr,PM0_C_0_39_rowPtr,
   PM0_C_0_57_rowPtr,PM0_C_0_59_rowPtr,PM0_C_0_61_rowPtr,PM0_C_0_63_rowPtr
};
static const size_t * const PM0_C_0_colIdx[] = {
   PM0_C_0_0_colIdx,PM0_C_0_2_colIdx,PM0_C_0_4_colIdx,PM0_C_0_6_colIdx,
   PM0_C_0_24_colIdx,PM0_C_0_26_colIdx,PM0_C_0_28_colIdx,PM0_C_0_30_colIdx,
   PM0_C_0_33_colIdx,PM0_C_0_35_colIdx,PM0_C_0_37_colIdx,PM0_C_0_39_colIdx,
   PM0_C_0_57_colIdx,PM0_C_0_59_colIdx,PM0_C_0_61_colIdx,PM0_C_0_63_colIdx
};
static const double * const HIL_PM0_C_0_data[] = {
   PM0_C_0_0_data,PM0_C_0_2_data,PM0_C_0_4_data,PM0_C_0_6_data,
   PM0_C_0_24_data,PM0_C_0_26_data,PM0_C_0_28_data,PM0_C_0_30_data,
   PM0_C_0_33_data,PM0_C_0_35_data,PM0_C_0_37_data,PM0_C_0_39_data,
   PM0_C_0_57_data,PM0_C_0_59_data,PM0_C_0_61_data,PM0_C_0_63_data
};
static const size_t * const PM0_D_0_rowPtr[] = {
   PM0_D_0_0_rowPtr,PM0_D_0_2_rowPtr,PM0_D_0_4_rowPtr,PM0_D_0_6_rowPtr,
   PM0_D_0_24_rowPtr,PM0_D_0_26_rowPtr,PM0_D_0_28_rowPtr,PM0_D_0_30_rowPtr,
   PM0_D_0_33_rowPtr,PM0_D_0_35_rowPtr,PM0_D_0_37_rowPtr,PM0_D_0_39_rowPtr,
   PM0_D_0_57_rowPtr,PM0_D_0_59_rowPtr,PM0_D_0_61_rowPtr,PM0_D_0_63_rowPtr
};
static const size_t * const PM0_D_0_colIdx[] = {
   PM0_D_0_0_colIdx,PM0_D_0_2_colIdx,PM0_D_0_4_colIdx,PM0_D_0_6_colIdx,
   PM0_D_0_24_colIdx,PM0_D_0_26_colIdx,PM0_D_0_28_colIdx,PM0_D_0_30_colIdx,
   PM0_D_0_33_colIdx,PM0_D_0_35_colIdx,PM0_D_0_37_colIdx,PM0_D_0_39_colIdx,
   PM0_D_0_57_colIdx,PM0_D_0_59_colIdx,PM0_D_0_61_colIdx,PM0_D_0_63_colIdx
};
static const double * const HIL_PM0_D_0_data[] = {
   PM0_D_0_0_data,PM0_D_0_2_data,PM0_D_0_4_data,PM0_D_0_6_data,
   PM0_D_0_24_data,PM0_D_0_26_data,PM0_D_0_28_data,PM0_D_0_30_data,
   PM0_D_0_33_data,PM0_D_0_35_data,PM0_D_0_37_data,PM0_D_0_39_data,
   PM0_D_0_57_data,PM0_D_0_59_data,PM0_D_0_61_data,PM0_D_0_63_data
};
static void (*const PM0_collision[16]) () = {
   PM0_collision_0,PM0_collision_2,PM0_collision_4,PM0_collision_6,
   PM0_collision_24,PM0_collision_26,PM0_collision_28,PM0_collision_30,
   PM0_collision_33,PM0_collision_35,PM0_collision_37,PM0_collision_39,
   PM0_collision_57,PM0_collision_59,PM0_collision_61,PM0_collision_63
};
static size_t (*const PM0_natPreComm[16]) () = {
   PM0_natPreComm_0_0,PM0_natPreComm_2_0,PM0_natPreComm_4_0,
   PM0_natPreComm_6_0,PM0_natPreComm_24_0,PM0_natPreComm_26_0,
   PM0_natPreComm_28_0,PM0_natPreComm_30_0,PM0_natPreComm_33_0,
   PM0_natPreComm_35_0,PM0_natPreComm_37_0,PM0_natPreComm_39_0,
   PM0_natPreComm_57_0,PM0_natPreComm_59_0,PM0_natPreComm_61_0,
   PM0_natPreComm_63_0
};
static size_t (*const PM0_natPostComm[16]) () = {
   PM0_natPostComm_0_0,PM0_natPostComm_2_0,PM0_natPostComm_4_0,
   PM0_natPostComm_6_0,PM0_natPostComm_24_0,PM0_natPostComm_26_0,
   PM0_natPostComm_28_0,PM0_natPostComm_30_0,PM0_natPostComm_33_0,
   PM0_natPostComm_35_0,PM0_natPostComm_37_0,PM0_natPostComm_39_0,
   PM0_natPostComm_57_0,PM0_natPostComm_59_0,PM0_natPostComm_61_0,
   PM0_natPostComm_63_0
};
static size_t (*const PM0_forcedComm[16]) () = {
   PM0_forcedComm_0_0,PM0_forcedComm_2_0,PM0_forcedComm_4_0,
   PM0_forcedComm_6_0,PM0_forcedComm_24_0,PM0_forcedComm_26_0,
   PM0_forcedComm_28_0,PM0_forcedComm_30_0,PM0_forcedComm_33_0,
   PM0_forcedComm_35_0,PM0_forcedComm_37_0,PM0_forcedComm_39_0,
   PM0_forcedComm_57_0,PM0_forcedComm_59_0,PM0_forcedComm_61_0,
   PM0_forcedComm_63_0
};
static size_t HIL_PM0_conductionMasks[16]={
   0,2,4,6,24,26,28,30,33,35,37,39,57,59,61,63
};
static size_t HIL_PM0_directionMasks[16]={
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
static void HIL_PM0_natComm()
{
   size_t oldTopo = HIL_PM0_topoIdx;
   size_t midTopo = HIL_PM0_topoIdx;
   size_t preConductionToggleMask = 0;
   size_t postConductionToggleMask = 0;
   size_t directionToggleMask = 0;
   HIL_PM0_topoIdx = PM0_natPreComm[HIL_PM0_topoIdx]();
   midTopo = HIL_PM0_topoIdx;
   HIL_PM0_topoIdx = PM0_natPostComm[HIL_PM0_topoIdx]();
   preConductionToggleMask = HIL_PM0_conductionMasks[midTopo] ^
                             HIL_PM0_conductionMasks[oldTopo];
   if (preConductionToggleMask)
   {
      postConductionToggleMask = HIL_PM0_conductionMasks[HIL_PM0_topoIdx] ^
                                 HIL_PM0_conductionMasks[midTopo];
      directionToggleMask = HIL_PM0_directionMasks[HIL_PM0_topoIdx] ^
                            HIL_PM0_directionMasks[oldTopo];
      if (postConductionToggleMask &
          (~preConductionToggleMask | directionToggleMask))
      {
         PM0_collision[HIL_PM0_topoIdx]();
      }
      else
      {
         PM0_collision[midTopo]();
      }
   }
}
static void HIL_PM0_forcedComm()
{
   HIL_PM0_topoIdx = PM0_forcedComm[HIL_PM0_topoIdx]();
}
static void HIL_PM0_output_0()
{
   const double * _RESTRICT C_0_data =
      _ASSUME_ALIGNED(HIL_PM0_C_0_data[HIL_PM0_topoIdx]);
   const double * _RESTRICT D_0_data =
      _ASSUME_ALIGNED(HIL_PM0_D_0_data[HIL_PM0_topoIdx]);
   const size_t meterIdx[]={
      0,1,2,3
   };
   double y[4] _ALIGN;
   size_t i;
   for (i = 0; i < 4; ++i)
   {
      y[i] = 0;
      {
         const size_t *rowPtr = PM0_C_0_rowPtr[HIL_PM0_topoIdx];
         const size_t *colIdx = PM0_C_0_colIdx[HIL_PM0_topoIdx];
         size_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(y+i) += C_0_data[j]*HIL_PM0_x[colIdx[j]];
      }
      {
         const size_t *rowPtr = PM0_D_0_rowPtr[HIL_PM0_topoIdx];
         const size_t *colIdx = PM0_D_0_colIdx[HIL_PM0_topoIdx];
         size_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(y+i) += D_0_data[j]*HIL_PM0_u[colIdx[j]];
      }
   }
   for (i = 0; i < 4; ++i)
   {
      HIL_PM0_y[meterIdx[i]] = y[i];
   }
}
static void HIL_PM0_update(const double * _RESTRICT aAd_data,
                           const double * _RESTRICT aBd0_data,
                           const double * _RESTRICT aBd1_data,
                           double * _RESTRICT x)
{
   const double * _RESTRICT Ad_data = _ASSUME_ALIGNED(aAd_data);
   const double * _RESTRICT Bd0_data = _ASSUME_ALIGNED(aBd0_data);
   const double * _RESTRICT Bd1_data = _ASSUME_ALIGNED(aBd1_data);
   const double * _RESTRICT prevX = HIL_PM0_prevX;
   size_t i;
   for (i = 0; i < 4; ++i)
   {
      x[i] = 0;
      {
         const size_t *rowPtr = PM0_Ad_rowPtr[HIL_PM0_topoIdx];
         const size_t *colIdx = PM0_Ad_colIdx[HIL_PM0_topoIdx];
         size_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(x+i) += Ad_data[j]*prevX[colIdx[j]];
      }
      {
         const size_t *rowPtr = PM0_Bd0_rowPtr[HIL_PM0_topoIdx];
         const size_t *colIdx = PM0_Bd0_colIdx[HIL_PM0_topoIdx];
         size_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(x+i) += Bd0_data[j]*HIL_PM0_prevU[colIdx[j]];
      }
      {
         const size_t *rowPtr = PM0_Bd1_rowPtr[HIL_PM0_topoIdx];
         const size_t *colIdx = PM0_Bd1_colIdx[HIL_PM0_topoIdx];
         size_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(x+i) += Bd1_data[j]*HIL_PM0_u[colIdx[j]];
      }
   }
}
static char HIL_first;
static double HIL_deriv[4] _ALIGN;
static uint32_t HIL_tickLo;
static int32_t HIL_tickHi;
HIL_BlockOutputs HIL_B;
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
static double HIL_ExtModeBuffer[2];
const double * const HIL_ExtModeSignals[] = {
   &HIL_PM0_y[0],
   &HIL_PM0_y[1],
   &HIL_PM0_y[2],
   &HIL_PM0_y[3],
   &HIL_ExtModeBuffer[0],
   &HIL_ExtModeBuffer[1],
   &HIL_B.AAF2,
   &HIL_B.AAF3
};
#endif /* defined(EXTERNAL_MODE) */
HIL_ModelStates HIL_X _ALIGN;
const char * HIL_errorStatus;
const double HIL_sampleTime = 0.00100000000000000002;
const char * const HIL_checksum = "dac2b5f4e58714bc0aa8d8952c76143a7326611f";
/* Target declarations */
struct PlxDataCaptureRegistry plxDataCaptureRegistry[1];
const int plxUseEthercat = 0;
struct PlxProgrammableValueRegistry plxProgrammableValueRegistry[1];
struct PlxToFileRegistry plxToFileRegistry[1];

void HIL_initialize(double time)
{
   double remainder;
   HIL_errorStatus = NULL;
   HIL_tickHi = floor(time/(4294967296.0*HIL_sampleTime));
   remainder = time - HIL_tickHi*4294967296.0*HIL_sampleTime;
   HIL_tickLo = floor(remainder/HIL_sampleTime + .5);
   remainder -= HIL_tickLo*HIL_sampleTime;
   if (fabs(remainder) > 1e-6*fabs(time))
   {
      HIL_errorStatus =
         "Start time must be an integer multiple of the base sample time.";
   }
   memset(&HIL_X, 0, sizeof(HIL_X));

   /* Target pre-initialization */
   setAnalogInputVoltage(0);
   setupDACs(0);
   setDigitalOutVoltage(0);
   plxInitDigitalOut();
   initPWMCapture();
   plxInitDigitalOverride();
   plxSetupAnalogSampling(1, 0, 1.00000000000000002e-03);
   plxSetMaxNumConsecutiveOverruns(5);
   setupSFPSyncMaster(0, 0, 0, 0);
   setupSFPSyncSlave(0, 0, 0);


   /* Initialization for PWM Capture : 'HIL/PWM Capture3' */
   plxSetupPWMCaptureChannel(27, 1, 1);
   plxSetupPWMCaptureChannel(26, 1, 1);
   HIL_D_size_t[0] = 0;
   HIL_D_int[0] = 1;

   /* Initialization for PWM Capture : 'HIL/PWM Capture1' */
   plxSetupPWMCaptureChannel(19, 1, 1);
   plxSetupPWMCaptureChannel(18, 1, 1);
   HIL_D_size_t[1] = 0;
   HIL_D_int[1] = 1;

   /* Initialization for PWM Capture : 'HIL/PWM Capture2' */
   plxSetupPWMCaptureChannel(21, 1, 1);
   plxSetupPWMCaptureChannel(20, 1, 1);
   HIL_D_size_t[2] = 0;
   HIL_D_int[2] = 1;

   /* Initialization for Subsystem : 'HIL' */
   HIL_X.HIL_i1_PM0_s[0] = 0;
   HIL_X.HIL_i1_PM0_s[1] = 1;
   HIL_X.HIL_i1_PM0_s[2] = 0;
   HIL_X.HIL_i1_PM0_s[3] = 0;
   HIL_X.HIL_i1_PM0_s[4] = 0;
   HIL_X.HIL_i1_PM0_s[5] = 0;
   HIL_PM0_topoIdx = 1;
   HIL_X.HIL_PM0_x[0] = 0;
   HIL_X.HIL_PM0_x[1] = 0;
   HIL_X.HIL_PM0_x[2] = 0;
   HIL_X.HIL_PM0_x[3] = 0;
   HIL_PM0_x = &HIL_X.HIL_PM0_x[0];

   /* Initialization for Transfer Function : 'HIL/AAF2' */
   HIL_X.AAF2 = 0.;

   /* Initialization for Transfer Function : 'HIL/AAF3' */
   HIL_X.AAF3 = 0.;

   /* Initialization for Transfer Function : 'HIL/AAF' */
   HIL_X.AAF = 0.;

   /* Initialization for Analog Out : 'HIL/Analog Out1' */
   setupAnalogOut(11, -2.000000000e-01f, 1.500000000e+00f, -inf, inf);

   /* Initialization for Transfer Function : 'HIL/AAF1' */
   HIL_X.AAF1 = 0.;

   /* Initialization for Analog Out : 'HIL/Analog Out2' */
   setupAnalogOut(9, -2.000000000e-01f, 1.500000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'HIL/Analog Out3' */
   setupAnalogOut(7, -4.000000000e-01f, 1.500000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'HIL/Analog Out4' */
   setupAnalogOut(5, -2.000000000e-01f, 1.500000000e+00f, -inf, inf);
   HIL_first = 1;
}

void HIL_step(void)
{
   if (HIL_errorStatus)
   {
      return;
   }

   /* PWM Capture : 'HIL/PWM Capture3' */
   {
      float* result = &HIL_B.PWMCapture3[0];
      *result = plxGetDigitalInAveraged(27);
   }
   {
      float* result = &HIL_B.PWMCapture3[1];
      *result = plxGetDigitalInAveraged(26);
   }
   /* PWM Capture : 'HIL/PWM Capture1' */
   {
      float* result = &HIL_B.PWMCapture1[0];
      *result = plxGetDigitalInAveraged(19);
   }
   {
      float* result = &HIL_B.PWMCapture1[1];
      *result = plxGetDigitalInAveraged(18);
   }
   /* Data Type : 'HIL/Data Type1' */
   HIL_B.DataType1 = (bool)HIL_B.PWMCapture1[1];

   /* Data Type : 'HIL/Data Type' */
   HIL_B.DataType = (bool)HIL_B.PWMCapture1[0];

   /* PWM Capture : 'HIL/PWM Capture2' */
   {
      float* result = &HIL_B.PWMCapture2[0];
      *result = plxGetDigitalInAveraged(21);
   }
   {
      float* result = &HIL_B.PWMCapture2[1];
      *result = plxGetDigitalInAveraged(20);
   }


   /* Electrical model */


   /* Electrical model input */
   /* Voltage Source DC : 'HIL/V_dc' */
   HIL_PM0_u[0]=30.;
   /* End of electrical model input */
   if (!HIL_first)
   {
      memcpy(HIL_PM0_prevX,HIL_PM0_x,4*sizeof(double));
      HIL_PM0_update(HIL_PM0_Ad_data[HIL_PM0_topoIdx],
                     HIL_PM0_Bd0_data[HIL_PM0_topoIdx],
                     HIL_PM0_Bd1_data[HIL_PM0_topoIdx],
                     HIL_PM0_x);
   }


   /* Commutation */
   HIL_PM0_natComm();
   HIL_PM0_gateSignalBuffer[0] = (bool)HIL_B.PWMCapture3[0];
   HIL_PM0_gateSignalBuffer[1] = HIL_B.DataType1;
   HIL_PM0_gateSignalBuffer[5] = (bool)HIL_B.PWMCapture3[1];
   HIL_PM0_gateSignalBuffer[2] = HIL_B.DataType;
   HIL_PM0_gateSignalBuffer[3] = (bool)HIL_B.PWMCapture2[1];
   HIL_PM0_gateSignalBuffer[4] = (bool)HIL_B.PWMCapture2[0];
   HIL_PM0_forcedComm();

   /* Electrical model output */
   HIL_PM0_output_0();
   /* End of electrical model output */

   /* End of electrical model */
   /* Transfer Function : 'HIL/AAF2' */
   HIL_B.AAF2 = -72765375.3238059282*HIL_X.AAF2;

   /* Transfer Function : 'HIL/AAF3' */
   HIL_B.AAF3 = -72765375.3238059282*HIL_X.AAF3;
   /* Analog Out : 'HIL/Analog Out1' */
   setAnalogOut(11, -72765375.3238059282*HIL_X.AAF);

   /* Analog Out : 'HIL/Analog Out2' */
   setAnalogOut(9, -72765375.3238059282*HIL_X.AAF1);

   /* Analog Out : 'HIL/Analog Out3' */
   setAnalogOut(7, HIL_B.AAF2);

   /* Analog Out : 'HIL/Analog Out4' */
   setAnalogOut(5, HIL_B.AAF3);
   HIL_first = 0;
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
   HIL_ExtModeBuffer[0] = (double)HIL_B.DataType;
   HIL_ExtModeBuffer[1] = (double)HIL_B.DataType1;
#endif /* defined(EXTERNAL_MODE) */

   if (HIL_errorStatus)
   {
      return;
   }

   /* Update for Subsystem : 'HIL' */
   memcpy(HIL_PM0_prevU,HIL_PM0_u,1*sizeof(double));

   /* Derivatives for Transfer Function : 'HIL/AAF2'
    * incorporates
    *  Voltmeter : 'HIL/Vm1'
    */
   HIL_deriv[2] = (HIL_PM0_y[3])-11205.8677998661133*HIL_X.AAF2;

   /* Derivatives for Transfer Function : 'HIL/AAF3'
    * incorporates
    *  Meter (3 phase) : 'HIL/3ph Meter'
    */
   HIL_deriv[3] = (HIL_PM0_y[0])-11205.8677998661133*HIL_X.AAF3;

   /* Derivatives for Transfer Function : 'HIL/AAF'
    * incorporates
    *  Meter (3 phase) : 'HIL/3ph Meter'
    */
   HIL_deriv[0] = (HIL_PM0_y[1])-11205.8677998661133*HIL_X.AAF;

   /* Derivatives for Transfer Function : 'HIL/AAF1'
    * incorporates
    *  Meter (3 phase) : 'HIL/3ph Meter'
    */
   HIL_deriv[1] = (HIL_PM0_y[2])-11205.8677998661133*HIL_X.AAF1;

   /* Update continuous states */
   HIL_X.AAF2 += 0.00100000000000000002*HIL_deriv[2];
   HIL_X.AAF3 += 0.00100000000000000002*HIL_deriv[3];
   HIL_X.AAF += 0.00100000000000000002*HIL_deriv[0];
   HIL_X.AAF1 += 0.00100000000000000002*HIL_deriv[1];
}

void HIL_terminate(void)
{
}
