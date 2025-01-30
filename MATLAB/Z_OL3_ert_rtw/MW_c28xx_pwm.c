#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "DSP2833x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "Z_OL3.h"
#include "Z_OL3_private.h"

void config_ePWM_GPIO (void)
{
  EALLOW;

  /*-- Configure pin assignments for ePWM1 --*/

  /*-- Configure pin assignments for ePWM3 --*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1U; /* Configure GPIOGPIO4 as EPWM3A*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1U; /* Configure GPIOGPIO5 as EPWM3B*/

  /*-- Configure pin assignments for ePWM4 --*/

  /*-- Configure pin assignments for ePWM5 --*/
  EDIS;
}

void config_ePWM_TBSync (void)
{
  /* Enable TBCLK within the EPWM*/
  EALLOW;
  SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
  EDIS;
}

void config_ePWMSyncSource (void)
{
}
