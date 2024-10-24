%% Battery Parameters
%{
batteryResponseTime = 10;  % (s) Settling time (95%) for 1C current steps
VBN = 360; % (V) nominal voltage
CBN = 24000; % (kWh) Battery rated capacity 
ratedC = CBN/VBN; % (Ah) Rated capacity in Ah (Ah@C1)  66.6Ah
VBNmax = 419.0354;  % (V) From simulink model (Full battery)
VBNmin = 350; %(V) From design
socInit = 80; % (%) State of charge
%}

%% Power Converter
fsw = 10e3; %Hz
Tsw = 1/fsw;
deadtimesw = 2.8e-6; %s (swiching deadtime)
VFdiodeIGBT = 2.27; %V
VthIGBT = 0.5; %V (IGBT treshold voltage normalized)

VinNom = 30; %V
VoutNom = 50; %V

%% Boost Converter design
%from datasheet
%
ILnom = 5; %Arms half of maximum
dIL = 0.2*ILnom;

% boost inductor
D = 1 - VinNom/VoutNom; % openloop duty cycle for 1leg
D3 = D/3; % openloop duty cycle for 3leg
L = 1.1*max(VinNom*D*Tsw / dIL, VinNom*(1-D)*Tsw / dIL); %find max inductor for boost & buck operation


RserL = L * (0.14/5e-3); %Ohm (unknown) must estimate
C = 1000e-6; %H % from guasch datasheet
ResrC = 1.8e-3; %Ohm (unknown) but not used in control tuning
%}

PCN = ILnom*VinNom; % converter nominal power (dont know yet)
IoutNom = PCN/VoutNom; %A
Rload = VoutNom/IoutNom; %Ohm
ILmax = 10; %Arms from guash

% OL duty cycle correction
%
Iin = IoutNom/(1-D);
VdropL = Iin*RserL;
D = 1 - (VinNom-VdropL) / VoutNom;
%}

% interleaved OL correction
Iin = IoutNom/(1-D3);
VdropL = Iin*RserL/3;
D3 = 1 - (VinNom-VdropL)/VoutNom;