#include <iostream>
#include <unistd.h>
#include <fstream>

#include "BPMAnalyser.hpp"

using namespace std;

int getTestDataLength(){
  ifstream in("measurement");
  int i = 0;
  if(!in) {
    cout << "Cannot open input file.\n";
    return i;
  }else{
    std::string str;
    while (std::getline(in, str)) {
      if(str.at(0) != '#') i++;
    }
    in.close();
    return i;
  }
}

void getTestData(int* values){
  ifstream in("measurement");
  int i = 0;
  if(!in) {
    cout << "Cannot open input file.\n";
  }else{
    std::string str;
    while (std::getline(in, str)) {
        if(str.at(0) != '#'){
          int num = stoi(str);
          values[i] = num;
          i++;
        }
    }
    in.close();
  }
}


int main(void)
{
    cout << "Read TestData" << endl;

    int size = getTestDataLength();
    cout << "TestDataLength: " << size << endl;

    int values[size];
    getTestData(values);
    BPMAnalyser bpmAnalyser(50);

    cout << "Start of TEST" << endl;
    double time = 0;

    cout << "T;BPM" << endl;
    for(int i = 0; i < size; i++){

     float bpm = bpmAnalyser.analyse(values[i]);
     cout << time << ";" <<  bpm << endl;

     time += 0.03;
     usleep(30000);
    }

    cout << "End of File" << endl;
    exit(EXIT_SUCCESS);
}
