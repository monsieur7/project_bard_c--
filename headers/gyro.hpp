
class gyro{

private:
    int x;
    int y;
    int z;
    bool status;
public:

    double  getx();
    double  gety();
    double getz();
    void gyro_launch();
    void gyro_stop();
};