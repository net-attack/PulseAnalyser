#include <iostream>  
#include <fftw.h>

using namespace std;  

class PulseAnalyser {  
    private:
		int* window;
		int size;
		fftw_plan p;
		
	public:  
		
		PulseAnalyser(int length, float frequency)
		{   
			//Create window for windowing in fft
		
			int temp_window[length];
			size = length;
			for(int i = 0; i <  length; i++){
				temp_window[i] = 1;
			}
			window = temp_window;
			
			
			 p = fftw_create_plan(length, FFTW_FORWARD, FFTW_ESTIMATE);
			
		}
		
		~PulseAnalyser()
		{
			fftw_destroy_plan(p);
		}
		
		void analyse(int* values)
		{
			fftw_complex in[size], out[size];
			
			fftw_one(p, in, out);
			for(int i = 0; i <  size; i++){
				std::cout << values[i] << std::endl;
			}
		}
};  
