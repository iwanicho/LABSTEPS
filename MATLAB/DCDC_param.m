%% Power Converter
fsw = 10e3; %Hz
Tsw = 1/fsw;
deadtimesw = 2.8e-6; %s (swiching deadtime)
VFdiodeIGBT = 2.27; %V
VthIGBT = 0.5; %V (IGBT treshold voltage normalized)

VinNom = 30; %V
VfbMax = 750; %v
IfbMax = 10; %A
VoutNom = 50; %V
VoutMax = 70; %V

%% Boost Converter design
%from datasheet
%
ILnom = 5 %A
dIL = 0.2*ILnom;
IL_peak = ILnom+dIL
IL_valley = ILnom-dIL

% boost inductor
D = 1 - VinNom/VoutNom; % openloop duty cycle for 1leg
D_3 = D/3; % openloop duty cycle for 3leg
L = max(VinNom*D*Tsw / dIL, VinNom*(1-D)*Tsw / dIL) %find max inductor for boost & buck operation



RserL = 8.78e-3 %Ohm from Open Magnetics
C = 1000e-6; %H % from guasch datasheet
ResrC = 1.8e-3; %Ohm (unknown) but not used in control tuning
%}

PCN = 3*ILnom*VinNom % converter nominal power (dont know yet)
IoutNom = PCN/VoutNom; %A
Rload = VoutNom/IoutNom; %Ohm
ILmax = 10; %Arms from guash

% OL duty cycle correction
%
Iin = IoutNom/(1-D);
VdropL = Iin*RserL;
D = (1 - (VinNom-VdropL) / VoutNom) + deadtimesw/Tsw
%}

% interleaved OL correction
Iin = IoutNom/(1-D_3);
VdropL = Iin*RserL/3;
D_3 = (1 - (VinNom-VdropL)/VoutNom) + deadtimesw/Tsw