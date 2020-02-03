#include <iostream>
#include <sys/time.h>
using namespace std;

class BPMAnalyser {

  private:
    float bpm = 60;

    float positiveWindowSpan = 0.5;
    float negativeWindowSpan = 0.5;

    int length;

    int* values;
    int positiveStep;
    int negativeStep;

    double lastRiseTime;
    double lastFallTime;

    float* riseTimes;
    float* fallTimes;


  public:

    BPMAnalyser(int s) {
      length = s;

      positiveStep = 0;
      negativeStep = 0;

      values = new int[s];

      riseTimes = new float[s];
      fallTimes = new float[s];
      lastRiseTime = micros();
      lastFallTime = micros();

      for(int i = 0; i < s; i++){
        values[i] = 0;
      }
    }

    float analyse(int value){

      int mean = 0;
      int min = 4097;
      int max = 0;

      if(value == 0) return bpm;

      for(int i = 0; i < length - 1; i++){
        values[i] = values[i+1];
        if(values[i] > max) max = values[i];
        if(values[i] < min) min = values[i];
        mean+=values[i];
      }
      values[length - 1] = value;

      if(value > max) max = value;
      if(value < min) min = value;
      mean+=value;
      mean/=length;

      int normalizedValue = value - mean;
      int positiveThreshold = positiveWindowSpan*(max - mean);
      int negativeThreshold = negativeWindowSpan*(min - mean);

      bool rise = false;
      bool fall = false;
      double riseTime;
      double fallTime;

      if(normalizedValue > positiveThreshold ){
        if(positiveStep==0){
          rise = true;
          riseTime = micros();
        }
        positiveStep = 1;
      } else {
        positiveStep = 0;
      }

      if(normalizedValue < negativeThreshold ){
        if(negativeStep==0){
          fall = true;
          fallTime = micros();
        }
        negativeStep = 1;
      } else {
        negativeStep = 0;
      }

      if(rise){
        handleRise(riseTime);
      }

      if(fall){
        handleFall(fallTime);
      }

      normalizeBPM();
      return bpm;
    }

    void handleRise(double riseTime){
      float riseBpm = 60000.0/((riseTime - lastRiseTime)/1000);
      lastRiseTime = riseTime;
      for(int i = 0; i < length - 1; i++){
        riseTimes[i] = riseTimes[i+1];
      }
      riseTimes[length-1] = riseBpm;
    }

    void handleFall(double fallTime){
      float fallBpm = 60000/((fallTime - lastFallTime)/1000);
      lastFallTime = fallTime;
      for(int i = 0; i < length - 1; i++){
        fallTimes[i] = fallTimes[i+1];
      }
      fallTimes[length-1] = fallBpm;
    }

    void normalizeBPM(){
      float tempbpm = bpm;
      int count = 1;

      int maxBPM = 220;
      int minBPM = 35;

      int meanSize = 2;//length - 0;

      for(int i = 1; i < meanSize + 1; i++){
        float f = fallTimes[length-i];
        float r = riseTimes[length-i];
        if((r  < maxBPM) && (r  > minBPM)){
          tempbpm += r ;
          count++;
        }
        if((f < maxBPM) && (f > minBPM)){
          tempbpm += f;
          count++;
        }
      }

      if(count>0) {
        tempbpm  =  tempbpm/count;
        bpm = tempbpm;
      }

    }


    double micros(){
      struct timeval  tv1;
      gettimeofday(&tv1, NULL);
      return (double)(tv1.tv_sec*1000000 + tv1.tv_usec);
    }
};
