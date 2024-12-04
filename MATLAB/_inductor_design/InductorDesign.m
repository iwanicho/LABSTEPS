close all
clc
clear all

L = 1.82*1e-3;
fs = 10e3;
iLp = 6;
iLv = 4;
iLrms = 5;
Mat = 12;
Core = 24;
Vg = 30;
Vo = 50;
didt = (Vo-Vg)/L;
fw = 0.3;
duty = 0.43;



[Pcore, Pcu, Peddy, Pfringe, Rdc, Rac, Nopt, g, Nwire, dwire, lwire] = InductorLosses(L, Mat, Core, iLrms, iLp, iLv, fs, didt,fw, duty, Vg, Vo);