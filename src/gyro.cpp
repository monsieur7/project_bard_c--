#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include <console_io.h>
#include <sensehat.h>
#include "../headers/gyro.hpp"

using namespace std;
using namespace std::this_thread;  // sleep_for, sleep_until
using namespace std::chrono;	   // nanoseconds, system_clock, seconds



gyro::gyro(){
	this -> x = 0;
	this -> y = 0;
	this -> z = 0;
	this -> status = 0;
}


void gyro:: gyro_launch(){
	status = 1;
	double xx , yy,zz;
	while (status){
		for (int time = 0; time < 10; time++) {
			sleep_for(milliseconds(1));
			cout << "Gyrometer in radians/s." << endl;
			if (senseGetGyroRadians(xx,yy,zz)) {
				x = xx;
				y = yy;
				z = zz;
			} else
				cout << "Error. No measures." << endl;
		}
	}
	cout <<"end measure";
}

double gyro::getx(){
	return(x);
}
double gyro::gety(){
	return(y);
}

double gyro::getz(){
	return(z);
}
void gyro::gyro_stop(){

	status = 0
}


