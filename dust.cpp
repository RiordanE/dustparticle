//
// Created by Thomas Kling on 1/24/19.
//

#include "dust.h"

dust::~dust() {  }

dust::dust() {

    M_ = 1; // 1e+20; // all same mass, 10^26 kg
    //x_ = 0.4;
    //y_ = 0.1;
    //z_ = 0;
    //vx_ = 0;
    //vy_ = 0;
    //vz_ = 0;
    Fx_ = 0;
    Fy_ = 0;
     dx_ = dy_ = dz_ = dvx_ = dvy_ = dvz_ = .1;

}
