clc
clear all
% close all
load heartrate_example.mat
figure(1)
lRate = length(rate);
p = 0.1;
plotSize = floor(lRate * p);

Fs = 25;
T = 1/Fs;
t = T.*rate(:,2);
x = rate(:,1);


plot(t(1:plotSize),x(1:plotSize), '-*');

tsRate = timeseries(x,t);
p = 0.4;
simTime = t(length(t));
stepTime = mean(diff(t));

sys = 'filterAnalyse';

open_system(sys);
normalizeBufferSize = 64;
minmaxBuffer = 64;
normalizeBPMBuffer = 200;
sim(sys);

