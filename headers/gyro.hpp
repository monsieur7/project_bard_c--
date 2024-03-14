
class Gyro
{

private:
    int x;
    int y;
    int z;
    bool status;
    void gyro_launch();

public:
    Gyro();
    ~Gyro();
    double getx();
    double gety();
    double getz();
};