% configure PWM
CPUCLK = 150e6 %Hz
SYSCLKOUT = 1/CPUCLK; %s system clock period
HSPCLKDIV = 1;
CLKDIV = 1;
TBCLK = SYSCLKOUT/(HSPCLKDIV*CLKDIV) %s

fsw = 10e3 %Hz
Tsw = 1/fsw %s timer/PWM/carrier period
TBPRD = Tsw / (2*TBCLK)
TBPHS = (Tsw/3) / (2*TBCLK)

FED = 2.8e-6 %s dead time between switching
DBFED = FED/TBCLK

ADC_mapping = 4095

%{
ADC input [0, 4095] -> linearize (cast to single) -> already include gain 1/4095
duty cycle:
CMPA in TBCLK = duty*TBPRD -> gain = TBPRD
TBCLK need to be integer -> convert
CMPA in percentage = 100*duty -> gain = 100
%}
