#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

void main()
{
	double res=0;
	Mat gabor = getGaborKernel(Size(64, 64), 20, 1, 20, 1, 0);
	imshow("Filter", gabor);
	Mat gray,img = imread("1.jpg");
	resize(img, img, Size(64, 64));
	cvtColor(img, gray, COLOR_BGR2GRAY); 
	imshow("1", gray);
	unsigned char* img_data;
	double* gabor_data;
	gabor_data = (double*)gabor.data;
	img_data = gray.data;
	int start_time = getTickCount();
	for (int k = 0; k < 1024; k++)
	for (int i = 0; i < 65 * 65; i++)
	{
		res += gabor_data[i] * (float)img_data[i];
		//cout << (float)img_data[i] << endl;
	}
	int end_time= getTickCount();
	double elapsed_time = (end_time - start_time) / getTickFrequency();
	cout << res << endl;
	cout << elapsed_time << endl;
	//imshow("2", res);
	waitKey();
}