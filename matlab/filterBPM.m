function x = filterBPM(x,fs)
    newx = zeros(length(x),1);
    x(abs(x)<500)=0;
    newx(1) = 0;
    for i = 2:length(x)
        newx(i) = newx(i-1) + x(i) - newx(i-1)*0.1;
    end
    x = bandpass(x,[0.75 3],fs);
%     x = newx;
end