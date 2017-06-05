//============================================================================
// Name        : SGTools1.cpp
// Author      : alu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"
#include "capCtrl.h"


using namespace std;
using namespace cv;



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

/*
	Mat H = imread("F46.jpg",1);
	if(H.empty()){
		cout << "empty" << endl;
		exit(-2);
	}
	imshow("TC1",H);
	waitKey(10000);
*/




	VideoCapture cap(0);
	if(!cap.isOpened()){
		cout << "Can not open capture!" << endl;
		exit(-1);
	}

//	cap.set(CV_CAP_PROP_FRAME_WIDTH,1280);
//	cap.set(CV_CAP_PROP_FRAME_HEIGHT,720);

	get_inf(cap);

	Mat frame;
	int i=0;
	while(1){
		cap >> frame;
		if(frame.empty())
		{
			cout << "failed to open capture" << endl;
			exit(-2);
		}
		imshow("TC1",frame);
		char key;
		key = waitKey(25);
		if(key == 'q'){
			cout << "Camera exit!" << endl;
			break;
		}
		if(key == 'r'){
			i++;
			char fn_out[120];
			char para[100];
			double br,con,sat;
			get_bcs(cap,br,con,sat);
			sprintf(para,"br%.0f_con%.0f_st%.0f",br,con,sat);
			sprintf(fn_out,"%d_",i);
			strcat(fn_out,para);
			strcat(fn_out,".jpg");
			cout << fn_out << endl;
			imwrite(fn_out,frame);
		}
		if(key == 'i'){
			get_inf(cap);
		}
		if(key == 'b'){
			set_cap_br(cap);
		}
		if(key == 'c'){
			set_cap_con(cap);
		}
		if(key == 's'){
			set_cap_sat(cap);
		}
		if(key == 'h'){
			set_cap_hue(cap);
		}
		if(key == 'g'){
			set_cap_gain(cap);
		}
		if(key == 'e'){
			set_cap_exp(cap);
		}
	}

	cap.release();


	return 0;

}






