%% Choose Core material
% Input  
%       L = Inductance value
%       Mat = Material chosen
%       Core = Core shape chosen
%       iLrms, iLp, iLv = Inductance currents
%       fs = switching frequency
%       didt = maximum current slope
%       fw = winding factor
%       duty = duty cycle
%       Vg = Input voltage
%       Vo = Output voltage
%       
% Output
%       Pcore = Overall Core losses
%       Pcu = Overall copper losses
%       Peddy = Eddy current losses
%       Pfringe = Fringe field losses
%       Rdc = DC resistance
%       Rac = AC resistance (proximity effect)
%       Nopt = Number of turns
%       g = air gap
%       Nwire = Number of wires needed
%       dwire = Wire diameter
%       lwire = Wire length

function [Pcore, Pcu, Peddy, Pfringe, Rdc, Rac, Nopt, g, Nwire, dwire, lwire] = InductorLosses(L, Mat, Core, iLrms, iLp, iLv, fs, didt,fw, duty, Vg, Vo)
% L = 11.8519e-6;
% fs = 100e3;
% iLp = 7.1812;
% iLv = 0;
% iLrms = 7.1429;
% Mat = 11;
% Core = 29;
% didt = 160/L;
% fw = 0.3;
% Vg = 140;
% Vo = 400;
% duty = 0.65;

% Callback to ChooseCoreMat and ChooseCore
mhu = 0;
Bsat = 0;
k = 0;
alpha = 0;
Beta = 0;
Ve = 0;
le = 0;
Ae = 0;
Aw = 0;
lm = 0;
Mww = 0;
a = 0;
b = 0;
w = 0;

[mhu, Bsat, k, alpha, Beta, MatName] = ChooseCoreMat(Mat);
[Ve, le, Ae, Aw, lm, Mww, a, b, w, CoreName] = ChooseCore(Core);

% Wires (diameter)
d = [0.01 0.02 0.05 0.06 0.08 0.1 0.2 0.3 0.4 0.5 0.6 0.8 1.1 1.2 1.4]*1e-3;

% Constants

%Ta = 25;            % Ambient temperature
rho = 1/(5.7e7);    % Copper resistivity
mhu0 = 4*pi*1e-7;   % Vacuum permitivity
sigma = 1/rho;      % Copper conductivity

% Determination of number of turns
DiL = iLp-iLv;
N = 1:1:200;

Nmin = round((L*iLp)/(Bsat*0.95*Ae));

    % Copper loss if the window were completly fulfilled
    PcuN = (N.^2)*(rho*lm*iLrms^2)/(fw*Aw);
    
    % Core loss (hysterisis only)
    BmaxN = ((L*DiL/2)./(N*Ae))*1e3;                  % iLp instead of DiL/2 for other criteria
    PcoreN1 = (Ve*1e3)*k*fs^alpha*BmaxN.^Beta;
    dTheta = 0.001*pi;
    Theta = 0:dTheta:2*pi;
    
    intCos = 2^(Beta-alpha)*sum((abs(cos(Theta)).^alpha)*dTheta);
    ki = k/((2*pi)^(alpha-1)*intCos);
    
    dBdt = ((didt*L)./N*Ae)*1e3;
    dB = ((iLp-iLv)*L./(2*N*Ae))*1e3;
    
    PcoreN = fs*(Ve*1e9)*ki.*((abs(dBdt)).^alpha).*((dB).^(Beta-alpha));
    
    PN1 = PcuN+PcoreN1;
    PN = PcuN+PcoreN;
        
    [MinPN1 nopt1]  = min(PN1);
    [MinPN nopt] = min(PN);
    
    Nopt = [nopt nopt1];
    
    Bopt = (L*iLp)./(Nopt*Ae);
    Pcore = [PcoreN(nopt) PcoreN1(nopt1)];
    
% Air-gap needed:
    g = (((mhu0*Nopt.^2*Ae)/L)-(le/mhu))/2;
    % If I had the core dimmension (cross section) I could calculate the
    % new inductance value due to this airgap using the following eq.
    L1 = L*(1+((a+b)*g/(a*b)));
    
% Once the number of turns is set, then we have to recalculate the copper
% losses, eddy current losses and fringe field effect losses

    % Skin effect

    S = fw*Aw./Nopt;
    
    depSkin = sqrt(1/(pi*fs*mhu*mhu0*sigma));
    dskin = 2*sqrt(rho/(pi*fs*mhu0));
    
    Iwire = find(d>=dskin,1);   
    dwire = d(Iwire-1);
    
    Nwire = round(4*S/(pi*dwire^2));
    Swire = Nwire*pi*dwire^2/4;
    
    Rdc = rho*lm*Nopt./Swire
    
    PcuDc = Rdc*iLrms^2;
    
    RacSkin = Rdc.*((dwire/(2*depSkin^4))/(48+0.8*dwire/(2*depSkin^4)))
    
    % Proximity effect
    Delta = 0.83*dwire;
    dlayer = 2*sqrt(Swire/pi);
    NperLayer = floor(w./dlayer);
    Layers = round(Nopt./NperLayer);                      % Number of layers
    RacProx = Rdc.*Delta.*((sinh(2*Delta)+sin(2*Delta)./(cosh(2*Delta)-cos(2*Delta)))+2*(Layers.^2-1)*(sinh(Delta)-sin(Delta))./(3*(cosh(Delta)+cos(Delta))));
    
    Rac = RacSkin+RacProx;
    
    PcuAc = Rac*iLrms^2;
    
    % PcuProx = (Layers/3).*(2*Layers.^2+1).*(dlayer.*Rdc./dskin).*iLrms.^2;
    % Erickson's method shown in the equation above. It is considerable
    % larger than Roshen's method.
    
    Pcu = PcuDc+PcuAc;
    
    % Eddy current losses
     
    % Classical Eddy Current
    PeddyClas = (duty*(Vg)^2+(1-duty)*(Vg-Vo)^2)./(8*pi*rho*Ae*1e6*Nopt.^2)*Ve;
    % Excess Eddy Current
    alpha2 = (Ae*1e6*(4*fs.*Bopt).^2)/(8*pi*rho);
    alpha2 = 1;
    PeddyExc = sqrt(Ae*1e6*alpha2/rho)*(duty*(Vg)^(3/2)+(1-duty)*(Vo-Vg)^(3/2))./((Nopt.*Ae*1e6).^(3/2))*Ve;
    
    Peddy = PeddyClas+PeddyExc;
    
    % Fringe field losses
    Hg = 0.9*Nopt(1)*iLp/g(1);
    
    y = [0.2 0.5 1 2]*1e-3;
    x = 0: 15e-3/100:15e-3;
    
    Ji = dwire/depSkin;
    Fji = 3*(sinh(Ji)-sin(Ji))/(Ji*(cosh(Ji)-cos(Ji)));
    
    for (i3 =1:1:length(g)) 
        for(i1=1:1:length(y))
            for(i2=1:1:length(x))
                if (x(i2)^2+y(i1)^2>g(i3)^2)
                    m(i2) = 0;
                else
                    m(i2) = 1;
                end
                Hy(i1+length(y)*(i3-1),i2) = -(Hg/(2*pi))*(atan(2*x(i2)*g(i3)./(x(i2).^2+y(i1).^2-g(i3)^2))+m(i2)*pi);
                Py(i1+length(y)*(i3-1),i2) = (((pi*mhu0*Hy(i1+length(y)*(i3-1),i2)*fs).^2)*(dwire^3)*dwire/(6*rho)+Fji)*y(i1);
            end
        end
        Pfringe(i3) = max(max(Py));
    end
       
    
    
% Conductor length
    lwire = Nopt*lm;

% TOTAL LOSSES BREAKDOWN
    LossMatrix = [Pcore(1) PcuDc(1) PcuAc(1) PeddyClas(1) PeddyExc(1) Pfringe(1);
                  Pcore(2) PcuDc(2) PcuAc(2) PeddyClas(2) PeddyExc(2) Pfringe(2)];
    
   
    
    figure
    plot(N,PcuN, 'LineWidth',1.5);
    hold on
    plot(N,PcoreN1, '--k', 'LineWidth',1.5);
    plot(N,PcoreN, 'k', 'LineWidth',1.5);
    plot(N, PN1, '--r', 'LineWidth',1.5);
    plot(N, PN, 'r', 'LineWidth',1.5);
    %plot(PSq, EffSq, '--r', 'LineWidth',1.5);
    hold off
    title ('Losses versus N')
    xlabel('# of turns (N)')
    ylabel('Power loss [W]');
    legend('Copper', 'Core(SE)', 'Core(iGSE)', 'Total(SE)', 'Total(iGSE)')%, 'Location', 'SouthEast')
    ylim([0 40])
    yL = get(gca,'YLim');
    line([nopt nopt],yL,'LineWidth',1,'Color','blue');
    line([nopt1 nopt1],yL,'LineWidth',1,'Color','black');
    line([Nmin Nmin],yL,'LineWidth',1,'Color','red');
    
    figure
    plot(x*1e3,Py(1,:),'b', 'LineWidth', 1.5)
    hold on
    plot(x*1e3,Py(2,:),'r', 'LineWidth', 1.5)
    plot(x*1e3,Py(3,:),'g', 'LineWidth', 1.5)
    plot(x*1e3,Py(4,:),'k', 'LineWidth', 1.5)
    title('Fringe field loss (iGSE)')
    xlabel('Distance to center leg x [mm]')
    ylabel('Pfringe [W]')
    legend('y=0.2','y=0.5','y=1','y=2')
    
    figure
    plot(x*1e3,Py(5,:),'b', 'LineWidth', 1.5)
    hold on
    plot(x*1e3,Py(6,:),'r', 'LineWidth', 1.5)
    plot(x*1e3,Py(7,:),'g', 'LineWidth', 1.5)
    plot(x*1e3,Py(8,:),'k', 'LineWidth', 1.5)
    title('Fringe field loss (SE)')
    xlabel('Distance to center leg x [mm]')
    ylabel('Pfringe [W]')
    legend('y=0.2','y=0.5','y=1','y=2')
    
    
    figure
    bar(LossMatrix,'Stacked', 'LineWidth', 1.5)
    title('Total Losses')
    %xlabel('# of phases')
    ylabel('Power losses [W]')
    set(gca,'XTickLabel',{'iGSE', 'SE'})
    legend('Hysteresis', 'Copper (DC)', 'Copper (AC)', 'Eddy Classical', 'Eddy Excess', 'Fringe')
    
    salida=strvcat([' '],[],['L= ' num2str(L*1e6) ' uH'],['Material: ' char(MatName)], ['Core: ' char(CoreName)],...
    [' '],['iGSE DESIGN'],[' N = ' num2str(Nopt(1)) ' turns'],[' Air-gap = ' num2str(g(1)*1e3) ' mm'],[' # of layers = ' num2str(Layers(1))],[' Wire diameter = ' num2str(dwire*1e3) ' mm'],[' # of wires = ' num2str(Nwire(1))],[' Wire length = ' num2str(Nopt(1)*lm) ' m'],...
    [' '],['SE DESIGN'],[' N = ' num2str(Nopt(2)) ' turns'],[' Air-gap = ' num2str(g(2)*1e3) ' mm'],[' # of layers = ' num2str(Layers(2))],[' Wire diameter = ' num2str(dwire*1e3) ' mm'],[' # of wires = ' num2str(Nwire(2))],[' Wire length = ' num2str(Nopt(2)*lm) ' m']);

    msgbox(salida);
    
    parametros = 0;

