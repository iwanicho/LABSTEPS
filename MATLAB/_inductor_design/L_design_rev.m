clc; clear all; 
g = 2*100e-6; %200um
%Core	Ve[mm3]	le[mm]	Ae[mm2]	Weigth [g]	Aw[mm2]	lm[mm]	Mww[mm]	a [mm]	b [mm]	w [mm]
%ETD34	7640	78,6	97,1	20	        123	       60	20,9	4,7	    11,1	23,6
%ETD44	17800	103	    173	    47	        214	       77	29,5	6,25	15,2	32,2

Ae = 173e-6;
le = 103e-3;
%Bsat(3F3) = 440mT      Bsat(3C85) = 425mT
%mu_r(3F3) = 2000       mu_r(3C85) = 2000
Bsat = 440e-3;
L = 3.6e-3; 
mu_0 = 4 * pi * 10^(-7);
mu_r = 2000;
Ipeak = 1;
%Nmin = (L * Ipeak) / (Bsat * 0.95 * Ae)
%g = (mu_0 * N^2 * Ae / L) - (le/mu_r)
N = sqrt((g+(le/mu_r))*L/(mu_0*Ae))
Nmin = (L * Ipeak) / (Bsat * 0.95 * Ae) 
%%total lenght of the wire
d = 1.76e-2;
w = 3.09e-2;
MTL = 2*pi* (d+w)/4; % mean length of one turn of wire
l_w = N*MTL %wire lenght
