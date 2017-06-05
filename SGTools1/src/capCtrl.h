/*
 * capCtrl.h
 *
 *  Created on: 2017Äê4ÔÂ14ÈÕ
 *      Author: Administrator
 */

#ifndef CAPCTRL_H_
#define CAPCTRL_H_

#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


void get_inf(VideoCapture cap);
void get_bcs(VideoCapture cap,double &br,double &con,double & sat );
void set_cap_br(VideoCapture cap);
void set_cap_con(VideoCapture cap);
void set_cap_sat(VideoCapture cap);
void set_cap_exp(VideoCapture cap);
void set_cap_hue(VideoCapture cap);
void set_cap_gain(VideoCapture cap);
void set_cap_exp(VideoCapture cap);


#endif /* CAPCTRL_H_ */
