#include "../headers/gyro.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include <console_io.h>
#include <sensehat.h>

Gyro::Gyro()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	updateValues();
}

Gyro::~Gyro()
{
}

void Gyro::updateValues()
{
	double xx, yy, zz;
	if (senseGetAccelMPSS(xx, yy, zz))
	{
		x = xx;
		y = yy;
		z = zz;
	}
	else
	{
		// std::cout << "Error. No measures." << std::endl;
		;
	}
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
Orientation Gyro::getOrientation()
{
	updateValues();

	// Define a threshold to consider the board as leaned
	const double threshold = 2;
	std::cout << x << " " << y << std::endl;

	// Check if leaned up or down
	if (y > threshold && abs(y) > abs(x))
		return Orientation::Right; // Inverted: Down is actually up
	else if (y < -threshold && abs(y) > abs(x))
		return Orientation::Left; // Inverted: Up is actually down

	// Check if leaned left or right
	if (x > threshold && abs(y) < abs(x))
		return Orientation::Up;
	else if (x < -threshold && abs(y) < abs(x))
		return Orientation::Down;

	// If none of the above conditions are met, return Unknown orientation

	return Orientation::Unknown;

}
