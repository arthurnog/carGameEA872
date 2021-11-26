#pragma once
using namespace std;
class Car {
    private:
        float x_current=0;
        float y_current=0;
        float angle=0;
        float speed=0;
        float maxSpeed=12;
        float acc=0.2;
        float dec=0.3;
        float turnSpeed=0.08;
    public:
        Car();
        ~Car();
        float get_x();
        void set_x(float new_x);
        float get_y();
        void set_y(float new_y);
        float get_angle();
        void set_angle(float new_angle);
        float get_speed();
        void set_speed(float new_speed);
        float get_maxSpeed();
        float get_turnSpeed();
        float get_acc();
        float get_dec();
};