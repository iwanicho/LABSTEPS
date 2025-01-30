#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "DSP2833x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "Z_CL3.h"
#include "Z_CL3_private.h"

void config_ePWM_GPIO (void)
{
  EALLOW;

  /*-- Configure pin assignments for ePWM1 --*/

  /*-- Configure pin assignments for ePWM2 --*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1U; /* Configure GPIOGPIO2 as EPWM2A*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1U; /* Configure GPIOGPIO3 as EPWM2B*/

  /*-- Configure pin assignments for ePWM3 --*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1U; /* Configure GPIOGPIO4 as EPWM3A*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1U; /* Configure GPIOGPIO5 as EPWM3B*/

  /*-- Configure pin assignments for ePWM6 --*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1U;/* Configure GPIOGPIO10 as EPWM6A*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1U;/* Configure GPIOGPIO11 as EPWM6B*/

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
