#!/bin/sh
sudo apt install fftw-dev
g++ main.cpp -I. -o PulseAnalyser -lfftw
chmod +x PulseAnalyser
./PulseAnalyser
