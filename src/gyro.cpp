#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include <console_io.h>
#include <sensehat.h>
#include "../headers/gyro.hpp"

Gyro::Gyro() // Corrected constructor name
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->status = 0;
	std::thread(&Gyro::gyro_launch, this); // Corrected thread creation
}

Gyro::~Gyro() // Corrected destructor name
{
	this->status = 0;
}

void Gyro::gyro_launch()
{
	status = 1;
	double xx, yy, zz;
	while (status)
	{
		for (int time = 0; time < 10; time++)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			std::cout << "Gyrometer in radians/s." << std::endl;
			if (senseGetGyroRadians(xx, yy, zz))
			{
				x = xx;
				y = yy;
				z = zz;
			}
			else
				std::cout << "Error. No measures." << std::endl;
		}
	}
	std::cout << "end measure";
}

double Gyro::getx()
{
	return x;
}

double Gyro::gety()
{
	return y;
}

double Gyro::getz()
{
	return z;
}