% written by Giulia
%probably e core or ETD 
%% design of non-optimum inductor 
L = 1.82*1e-3 %He
% L = mu_o * mu_r * N^2 * A_e/l_e
mu_o = 4 * pi * 10^(-7);
% choosing Ferrite E-core (sat = 0.3-0.5T), these values are assumed based
% on typical ferrite core dimesions in inductor design
A_e = 1 * 10^(-4); %effective area cross-sectional area, 
l_e = 0.1; % effective magnetic path lenght 
g = 0.5 * 10^(-3); %air gap
 
%% number of turns
N = sqrt(L*(l_e+g)/(mu_o*A_e)); %number of turns

%% wire parameters
I = 5;%A value that needs to be changed
J = 5; %A/mm^2 typical value for copper
A_w = I/J; %cross-sectional area
d = 2 * sqrt(A_w/pi); %wire diameter

%% avoiding saturation
%B = (L*I)/(N*A_e);
B_sat = 0.2; %T
N_min = ceil((L*I)/(B_sat*A_e)) %nearest integer that is greater than or equal to the current value,

%%total lenght of the wire
% considering a E-core h = 1-4 cm and w = 0.8-3cm
h = 2*10^(-2)
w = 1.5*10^(-2)
MTL = 2* (h+w) % mean length of one turn of wire
l_w = N*MTL %wire lenght

