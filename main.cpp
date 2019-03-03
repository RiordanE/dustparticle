#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "dust.h"
#include <random>
#include <time.h>

using namespace std;



int main() {

    ofstream myfile;
    myfile.open("simulation3.csv"); //define the file


    vector<dust> d;
    for(int i=0; i<2; i++){
        d.push_back(dust());
        //cout<< i <<"  " <<d[i].M_ << endl;
    }

    default_random_engine re(time(0));
    //normal_distribution<double> galaxySizeDistribution(50, 5);  //mean followed by std dev.

    uniform_real_distribution<double> yDistribution(-10, 10);

    default_random_engine rev(time(0));
    //normal_distribution<double> Distribution(50, 5);  //mean followed by std dev.

    uniform_real_distribution<double> vDistribution(-10, 10);


    for(int i = 0; i< 2; i++){
        d[i].x_ = 1 + i; //yDistribution(re); //*1e+5;
        d[i].y_= 1 +i; //yDistribution(re);//*1e+5;
        d[i].vx_= 0;//vDistribution(rev)*1e+2;
        d[i].vy_ = 0; //vDistribution(rev)*1e+2;

        //cout << d[i].x_ << "  "<< d[i].y_ << endl;
    }

    double G = 1; // 6.67e-11;
    double h = .1;
    double scale = 1; //1e+06;


    for(int n = 0; n<1000; n++){ // Euler loop

        // compute the new force on each particle
        for(int i=0; i<2; i++){
            for(int j = i+1; j<2; j++){
                double rval = sqrt(pow(d[i].x_ - d[j].x_, 2.0) + pow(d[i].y_ - d[j].y_, 2.0));
                d[i].Fx_ += - G*d[i].M_ * d[j].M_/rval/rval/rval *(d[i].x_ - d[j].x_);
                d[j].Fx_ += - d[i].Fx_; //+ G*d[i].M_ * d[j].M_/rval/rval/rval*(d[i].x_ - d[j].x_);
                d[i].Fy_ += - G*d[i].M_ * d[j].M_ /rval/rval/rval*(d[i].y_ - d[j].y_);
                d[j].Fy_ += - d[i].Fy_; //+ G*d[i].M_ * d[j].M_ /rval/rval/rval*(d[i].y_ - d[j].y_);

                //cout << d[i].Fx_ <<"  "<< d[j].Fx_ <<  "  "<< rval << endl;


            }
            //char test;
            //cin >> test;


        }


        // figure out how much each one moves

        for(int i=0; i<2; i++){
            d[i].dx_  = h * d[i].vx_;
            d[i].dvx_ = h * d[i].Fx_ / d[i].M_;
            d[i].dy_  = h * d[i].vy_;
            d[i].dvy_ = h * d[i].Fy_ / d[i].M_;
        }

        // move each one together and reset all teh forces to zero

        for(int i =0; i<2; i++){
            d[i].x_  += d[i].dx_;
            d[i].vx_ += d[i].dvx_;
            d[i].y_  += d[i].dy_;
            d[i].vy_ += d[i].dvy_;

            cout << d[1].Fx_ << "," << d[1].Fy_ << endl;

            // add line for y

            d[i].Fx_ = 0;
            d[i].Fy_ = 0;
        }
        //cout << d[0].Fx_/scale << "," << d[1].Fx_/scale<< endl; // output stuff here on each Euler step

        //myfile << d[0].x_/scale << "," << d[0].y_/scale << ","<< d[1].x_/scale << "," << d[1].y_/scale << "," << d[2].x_/scale << "," << d[2].y_/scale << "," << d[3].x_/scale << "," << d[3].y_/scale << "," << d[4].x_/scale << "," << d[4].y_ /scale<< endl;

    } // end of Euler loop



    return 0;
}