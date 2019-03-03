//
// Created by Thomas Kling on 1/24/19.
//

#ifndef DUSTTEST_DUST_H
#define DUSTTEST_DUST_H


class dust {


public:
    double M_;
    double x_;
    double y_;
    double z_;
    double vx_;
    double vy_;
    double vz_;
    double Fx_;
    double Fy_;
    double dx_, dy_, dz_, dvx_, dvy_, dvz_;

    dust();
    ~dust();

};


#endif //DUSTTEST_DUST_H
