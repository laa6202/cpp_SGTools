//============================================================================
// Name        : SGTools2.cpp
// Author      : alu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


String fn0 = "t10/test2.bmp";


int main() {
	cout << "---SGTools2---" << endl; // prints !!!Hello World!!!






	string::size_type pos = fn0.find("bmp");
	if(pos == string::npos){
		cout << "no bmp in fn0 =" << fn0 <<"\t exit(-1)"<<endl;
		exit(-1);
	}
	String fn1 = fn0;
	fn1.replace(pos,3,"png");

	pos = fn0.find("t10");
	if(pos == string::npos){
		cout << "no t10 in fn0 =" << fn0 <<"\t exit(-1)"<<endl;
		exit(-1);
	}
	fn1.replace(pos,3,"t11");
	cout << "fn0 = "<<fn0 << endl;
	cout << "fn1 = "<<fn1 << endl;


	Mat R = imread("ref.png",1);
	Mat A = imread(fn0,1);
	if(A.empty()){
		cout << "load file error! \t exit(-2)" << endl;
		exit(-2);
	}

	Mat B;
	resize(A, B, Size(640,480));

	Mat C = R.clone();
	for(int i=0;i<C.rows;i++){
		for(int j=0;j<C.cols;j++){
			C.at<Vec3b>(i,C.cols - j)[0]= B.at<Vec3b>(j,i)[0];
			C.at<Vec3b>(i,C.cols - j)[1]= B.at<Vec3b>(j,i)[1];
			C.at<Vec3b>(i,C.cols - j)[2]= B.at<Vec3b>(j,i)[2];
		}

	}



	while(1){
		imshow("SGTools2", C);
		uchar key =waitKey(25);
		if(key == 'q')
			break;
	}
	imwrite(fn1,C);

	cout << "---end SGTools2---" <<endl;
	return 0;
}
