class BPMAnalyser {

  private:
    float bpm = 60;

    float positiveWindowSpan = 0.5;
    float negativeWindowSpan = 0.5;

    int lengthWindow;

    int* values;
    int positiveStep;
    int negativeStep;

    double lastRiseTime;
    double lastFallTime;

    float* riseTimes;
    float* fallTimes;


  public:

    BPMAnalyser(int s) {
      lengthWindow = s;

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
 

      double mean = 0;
      int minV = 4097;
      int maxV = 0;

      if(value == 0) return bpm;

      for(int i = 0; i < lengthWindow - 1; i++){
        values[i] = values[i+1];
        if(values[i] > maxV) maxV = values[i];
        if(values[i] < minV) minV = values[i];
        mean+=values[i];
      }
      values[lengthWindow - 1] = value;

      if(value > maxV) maxV = value;
      if(value < minV) minV = value;
      mean+=value;
      mean/=lengthWindow;

      int normalizedValue = value - mean;
      int positiveThreshold = positiveWindowSpan*(maxV - mean);
      int negativeThreshold = negativeWindowSpan*(minV - mean);

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
      //Serial.print(normalizedValue);      
      //Serial.print(",");      
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
      for(int i = 0; i < lengthWindow - 1; i++){
        riseTimes[i] = riseTimes[i+1];
      }
      riseTimes[lengthWindow-1] = riseBpm;
    }

    void handleFall(double fallTime){
      float fallBpm = 60000/((fallTime - lastFallTime)/1000);
      lastFallTime = fallTime;
      for(int i = 0; i < lengthWindow - 1; i++){
        fallTimes[i] = fallTimes[i+1];
      }
      fallTimes[lengthWindow-1] = fallBpm;
    }

    void normalizeBPM(){
      float tempbpm = bpm;
      int count = 1;

      int maxBPM = 220;
      int minBPM = 35;

      int meanSize = 2;//length - 0;

      for(int i = 1; i < meanSize + 1; i++){
        float f = fallTimes[lengthWindow-i];
        float r = riseTimes[lengthWindow-i];
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


    
};
