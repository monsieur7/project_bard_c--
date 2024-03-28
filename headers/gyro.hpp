#pragma once

enum class Orientation {
    Up,
    Down,
    Left,
    Right,
    Unknown
};
class Gyro
{
private:
    double x;
    double y;
    double z;

public:
    Gyro();
    ~Gyro();
    void updateValues();
    double getx();
    double gety();
    double getz();
    Orientation getOrientation();
};