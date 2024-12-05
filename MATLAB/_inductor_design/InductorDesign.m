close all
clc
clear all

L = 3.6*1e-3;
fs = 10e3;
iLp = 1;
iLv = 0.6667;
iLrms = 0.8333;
Mat = 12;   % 3F3
Core = 16;  % ETD39
Vg = 30;
Vo = 50;
didt = (Vo-Vg)/L;
fw = 0.3;
duty = 0.43;



[Pcore, Pcu, Peddy, Pfringe, Rdc, Rac, Nopt, g, Nwire, dwire, lwire] = InductorLosses(L, Mat, Core, iLrms, iLp, iLv, fs, didt,fw, duty, Vg, Vo);