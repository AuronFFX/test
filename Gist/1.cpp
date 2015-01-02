#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

void main()
{
	Mat gabor = getGaborKernel(Size(64, 64), 20, 1, 20, 1, 0);
	Mat gray,img = imread("1.jpg");
	resize(img, img, Size(64, 64));
	cvtColor(img, gray, CV_RGB2GRAY);
	//filter2D()
	imshow("1", img);
	waitKey();
}