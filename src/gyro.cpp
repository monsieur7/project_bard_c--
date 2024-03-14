#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include <console_io.h>
#include <sensehat.h>
#include "../headers/gyro.hpp"


gyro::gyro()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->status = 0;
	std::thread(&gyro::gyro_launch(), this);
}
gyro::~gyro()
{
	this->status = 0;
}

void gyro::gyro_launch()
{
	status = 1;
	double xx, yy, zz;
	while (status)
	{
		for (int time = 0; time < 10; time++)
		{
			std::chrono::sleep_for(milliseconds(1));
			std::cout << "Gyrometer in radians/s." << std::endl;
			if (senseGetGyroRadians(xx, yy, zz))
			{
				x = xx;
				y = yy;
				z = zz;
			}
			else
				cout << "Error. No measures." << endl;
		}
	}
	std::cout << "end measure";
}

double gyro::getx()
{
	return x;
}
double gyro::gety()
{
	return y;
}

double gyro::getz()
{
	return z;
}
