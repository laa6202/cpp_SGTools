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


int main() {
	cout << "---SGTools2---" << endl; // prints !!!Hello World!!!

	String fn0 = "t10/Sat Jun 03 15-32-54.bmp";
	String fn1 = "t11/Sat Jun 03 15-32-54.png";

	Mat A = imread(fn0,1);
	if(A.empty()){
		cout << "load file error!" << endl;
		exit(-1);
	}


	//imshow("SGTools2", A);
	//waitKey(1000);
	imwrite(fn1,A);

	cout << "---end SGTools2---" <<endl;
	return 0;
}
