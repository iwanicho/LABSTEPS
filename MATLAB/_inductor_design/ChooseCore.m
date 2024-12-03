%% Choose Core
% Input MOSFET 
%       Index = Core index
%       
% Output
%       Ve = Equivalent volume
%       le = Equivalent length
%       Ae = Effective area
%       Aw = Window area
%       lm = Average turn length
%       Mww = Average number of turns per layer
%       a = cross section dimension
%       b = cross section dimension

function [Ve, le, Ae, Aw, lm, Mww, a, b, w, name] = ChooseCore(Index)

% Core Material database -> see spreadsheet below
[num, text]=xlsread('Core.xls');

% 1 - RM4
% 2 - E13
% 3 - RM5
% 4 - RM6
% 5 - E16
% 6 - E20/5
% 7 - E20/6
% 8 - RM8
% 9 - RM10
% 10 - E25
% 11 - ETD29
% 12 - E30
% 13 - ETD34
% 14 - RM12
% 15 - E34
% 16 - ETD39
% 17 - RM14
% 18 - ETD44
% 19 - E42/20
% 20 - ETD49
% 21 - E42/15
% 22 - E47
% 23 - ETD54
% 24 - ETD59
% 25 - E55
% 26 - E56
% 27 - E65
% 28 - E71
% 29 - E80


Ve = num(Index,1)*1e-9;
le = num(Index,2)*1e-3;
Ae = num(Index,3)*1e-6;
Aw = num(Index,5)*1e-6;
lm = num(Index,6)*1e-3;
Mww = num(Index,7)*1e-3;
a = num(Index,8)*1e-3;
b = num(Index,9)*1e-3;
w = num(Index,10)*1e-3;
name = text(Index+1,1);
