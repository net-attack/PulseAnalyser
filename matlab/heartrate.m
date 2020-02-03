clc
clear all
% close all
load heartrate_example.mat
lRate = length(rate);
samples = 128;

f_sample = 30;
T = 1/f_sample;
t = T.*double(rate(:,2));
x = rate(:,1);

%%
offset = 1500;
n_x = double(x)-offset;

%%





%%
tsRate = timeseries(x,t);
simTime = t(length(t));
stepTime = mean(diff(t));


%%
for i=1:floor(lRate/samples)-1
    figure(1)
    fs = samples;
    zeropaddingsize = 11000;
    yt = t(i*samples:(i+1)*samples);
    y = n_x(i*samples:(i+1)*samples);
    plot(yt,y, '-*');
    y = filterBPM(y,f_sample);
    hold on
    plot(yt,y, '-*');
    hold off
    title("PulseSignal");
    xlabel("seconds [s]");
    ylabel("value [1]");

    y = double(y).*hanning(length(y));
    y = [y; zeros(zeropaddingsize,1)];
    Y = fft(y);
    p1 = abs(Y/(samples/4));
    p1 = p1(1:floor(length(y)/2)-1);
    f = ((0:length(y)/2-1)./(length(y)/2-1)*f_sample/2)';
    f = f(1:length(p1));
    figure(2)
    plot(f(2:end), p1(2:end));
    title("Spektrum");
    xlabel("frequency [hz]");
    ylabel("value [1]");
    [maxP, index] = max(p1(2:end));
    fmax = f(index+1);
    figure(1)
    sin_x = -4*maxP*sin(2*pi*1/fmax*2*yt+angle(maxP));
    hold on
    plot(yt,sin_x);
    hold off
    disp(['The bpm is ' num2str(120/fmax)]);
end


