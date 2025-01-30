clear all; clc; close;
% 6.6 times under 10kHz
%% INITIAL VALUES (FILTER)
% cutoff = 1kHz
xaaf = 1.5; %ratio of resistor to change the cutoff frequency

Rf1 = 10.5e3/xaaf; %Ohm
Rf2 = 10.5e3/xaaf; %Ohm
Rf3 = 5.9e3/xaaf; %Ohm
Cf1 = 10e-9; %F
Cf2 = 40.2e-9; %F

K = -Rf2/Rf1;
a = Rf2*Rf3*Cf1*Cf2;
b = Rf3*Cf1 + Rf2*Cf1 + Rf2*Rf3*Cf1/Rf1;
c = 1;
num = K;
denum = [a b c];
G1 = tf(num, denum);
%}

%% DESIGN VALUES (FILTER)
Rf1 = 6.8e3; %Ohm
Rf2 = 6.8e3; %Ohm
Rf3 = 4.3e3; %Ohm
Cf1 = 10e-9; %F
Cf2 = 47e-9; %F
%

K = -Rf2/Rf1;
a = Rf2*Rf3*Cf1*Cf2;
b = Rf3*Cf1 + Rf2*Cf1 + Rf2*Rf3*Cf1/Rf1;
c = 1;
num_aaf = K;
den_aaf = [a b c];
Gaaf = tf(num_aaf, den_aaf)

% "ltiview" to change units rad/s to Hz
BW1 = bandwidth(G1)/(2*pi)
BWaaf = bandwidth(Gaaf)/(2*pi)
bode(G1,Gaaf), grid, legend
%}

%% Signal Conditioning
%clc;
% Rsum/Rin_i = 1.5/7.5 = 0.2
% Rsum/Roffset_i = 1.5/15 = 0.1
% Rin_v = Rin_i/2
% Roffset_i=50e3
% Rin_i=25e3
% Rsum=5e3
Rsum = 6.8e3 % 4x
Roffset_i = Rsum/0.1 %3x
Rin_i = Rsum/0.2 %3x


% Rsum/Rin_v = 3/7.5 = 0.4
Rin_v = Rin_i/2 % 1x