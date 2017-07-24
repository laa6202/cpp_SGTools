


#include "capCtrl.h"



void get_inf(VideoCapture cap){

	double height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	double width  = cap.get(CV_CAP_PROP_FRAME_WIDTH);
//	double mode = cap.get(CV_CAP_PROP_MODE);
	double br = cap.get(CV_CAP_PROP_BRIGHTNESS);
	double con = cap.get(CV_CAP_PROP_CONTRAST);
	double sat = cap.get(CV_CAP_PROP_SATURATION);
	double hue = cap.get(CV_CAP_PROP_HUE);
	double gain = cap.get(CV_CAP_PROP_GAIN);
	double exp = cap.get(CV_CAP_PROP_EXPOSURE);
	cout << "cap height = " << height << "\t";
	cout << "cap width  = " << width  << endl;
//	cout << "cap mode  = " << mode  << endl;
	cout << "(B)cap br = " << br <<"\t";
	cout << "(C)cap con = " << con <<"\t";
	cout << "(S)cap sat = " << sat <<endl;
	cout << "(H)cap hue = " << hue <<"\t";
	cout << "(G)cap gain = " << gain <<"\t";
	cout << "(E)cap exp = " << exp <<endl;
	cout << "show information press (I), default press (D),save photo press (R),quit press (Q)."
			<< endl << endl;;
}


void get_bcs(VideoCapture cap,double &br,double &con,double & sat ){
	br = cap.get(CV_CAP_PROP_BRIGHTNESS);
	con = cap.get(CV_CAP_PROP_CONTRAST);
	sat = cap.get(CV_CAP_PROP_SATURATION);

}

void set_cap_br(VideoCapture cap){
	double br = cap.get(CV_CAP_PROP_BRIGHTNESS);
	br += 10;
	br = (br >=255) ? (br-255 ) : br;
	cap.set(CV_CAP_PROP_BRIGHTNESS,br);
}

void set_cap_con(VideoCapture cap){
	double con = cap.get(CV_CAP_PROP_CONTRAST);
	con += 10;
	con = (con >=255) ? (con-255 ) : con;
	cap.set(CV_CAP_PROP_CONTRAST,con);
}

void set_cap_sat(VideoCapture cap){
	double sat = cap.get(CV_CAP_PROP_SATURATION);
	sat += 10;
	sat = (sat >=255) ? (sat-255 ) : sat;
	cap.set(CV_CAP_PROP_SATURATION,sat);
}

void set_cap_hue(VideoCapture cap){
	double hue = cap.get(CV_CAP_PROP_HUE);
	hue += 10;
	hue = (hue >=120) ? (hue-120 ) : hue;
	cap.set(CV_CAP_PROP_HUE,hue);
}

void set_cap_gain(VideoCapture cap){
	double gain = cap.get(CV_CAP_PROP_GAIN);
	gain += 10;
	gain = (gain >=100) ? (gain-100 ) : gain;
	cap.set(CV_CAP_PROP_GAIN,gain);
}


void set_cap_exp(VideoCapture cap){
	double exp = cap.get(CV_CAP_PROP_EXPOSURE);
	exp += 10;
	exp = (exp >=100) ? (exp-100 ) : exp;
	cap.set(CV_CAP_PROP_EXPOSURE,exp);
}


void set_default(VideoCapture cap){

	cap.set(CV_CAP_PROP_BRIGHTNESS,20);
	cap.set(CV_CAP_PROP_CONTRAST,20);
	cap.set(CV_CAP_PROP_SATURATION,50);
	cap.set(CV_CAP_PROP_HUE,18);
	cap.set(CV_CAP_PROP_GAIN,18);
	cap.set(CV_CAP_PROP_EXPOSURE,15);
}
