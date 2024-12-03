%% INDUCTOR VOLUME ESTIMATOR
% Input MOSFET 
%       Loss = Inductor losses
%       
% Output
%       VolInd = Inductor estimated volume
%       WeigthInd = Inductor weigth

function [VolInd] = IndVolume(Loss)

% FET database -> see spreadsheet below
[num, text]=xlsread('Core.xls');

DT = 60;
Awmin = 26*Loss*100/DT;

Aw = num(:,5)';
Vol = num(:,1)'*1e-9;

[AwMax]=max(Aw);

if (Awmin-AwMax < 0)
    k=1;
else
    k = round(Awmin-AwMax);
end

[Index] = find(k*Aw>=Awmin,1);

VolInd = k*Vol(Index);

