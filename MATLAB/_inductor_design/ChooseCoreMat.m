%% Choose Core material
% Input MOSFET 
%       Index = Material index
%       
% Output
%       mhu = magnetic permetivity
%       Bsat = B saturation
%       k = Stenmetz's parameter
%       alpha = Stenmtez's parameter
%       Beta = Stenmetz's parameter

function [mhu, Bsat, k, alpha, Beta, name] = ChooseCoreMat(Index)

% Core Material database -> see spreadsheet below
[numMat, textMat]=xlsread('CoreMat.xls');

% 1 - 3C81
% 2 - 3C90
% 3 - 3C91
% 4 - 3C92a
% 5 - 3C92b
% 6 - 3C93a
% 7 - 3C93b
% 8 - 3C94
% 9 - 3C96a
% 10 - 3C96b
% 11 - 3F3a
% 12 - 3F3b

mhu = numMat(Index,1);
Bsat = numMat(Index,2)*1e-3;
k = numMat(Index,3);
alpha = numMat(Index,4);
Beta = numMat(Index,5);
name = textMat(Index+1,1);
