%% Power Converter
fsw = 10e3; %Hz 	    switching frequency
Tsw = 1/fsw; %s	        switching period
deadtimesw = 2.8e-6; %s switching deadtime
VFdiodeIGBT = 2.27; %V	diode's forward voltage
VthIGBT = 0.5; %V       IGBT treshold voltage normalized

VinNom = 30; %V	    nominal operating input voltage
VfbMax = 750; %V	max measured voltage
IfbMax = 10; %A	    max measured current
VoutNom = 50; %V	nominal operating output voltage
VoutMax = 70; %V

phy2sensV = 7.5/VfbMax; % voltage scaling from physical value to sensor output
phy2sensI = 7.5/IfbMax; % current scaling from physical value to sensor output

PCN = 75; %W converter nominal power (dont know yet)
IoutNom = PCN/VoutNom %A
Rload = VoutNom/IoutNom %Ohm

%% Boost Converter design
%from datasheet
%
ILmax = 10; %Arms from guash
ILnom = (1/3)*PCN/VinNom %A
dIL = 0.4*ILnom
ILpeak = ILnom+dIL
ILvalley = ILnom-dIL

% boost inductor, continuous mode
D = 1 - VinNom/VoutNom % openloop duty cycle for 1leg
D_3 = D; % openloop duty cycle for 3leg
L = VinNom*D*Tsw/dIL %H inductor for boost operation
RserL = 8.78e-3 %Ohm from Open Magnetics

C = 1000e-6 %H % from guasch datasheet
% assume RserC = (1e-5)/C, but not used in control tuning
RserC = (1e-5)/C %Ohm
%}

% OL duty cycle correction
%
Iin = IoutNom/(1-D);
VdropL = Iin*RserL;
D = (1 - (VinNom-VdropL)/VoutNom) + deadtimesw/Tsw
%}

% interleaved OL correction
Iin = IoutNom/(1-D_3);
VdropL = Iin*RserL/3;
D_3 = (1 - (VinNom-VdropL)/VoutNom) + deadtimesw/Tsw