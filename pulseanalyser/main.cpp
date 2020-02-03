#include <iostream>  
#include "PulseAnalyser.hpp"  

int main(void)   
{  
	//Test values
	int values[5] = {1000, 2, 3, 17, 50};
	
	PulseAnalyser pulseAnalyser = PulseAnalyser(2, 0.1); //creating an object of PulseAnalayser   
    
    pulseAnalyser.analyse(values);
    std::cout << "Hallo Welt" << std::endl;
    return 0;  
}  

