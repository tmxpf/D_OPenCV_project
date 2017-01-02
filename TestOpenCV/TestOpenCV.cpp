#include <iostream>												// for cout
#include "./OpenCV2.4.11/include/opencv2/highgui/highgui.hpp"	// for opencv
#include "C:\Users\dgist\Desktop\OpenCV 2.4.11\opencv\build\include\opencv2\highgui\highgui.hpp"
using namespace cv;												// for opencv
using namespace std;											// for cout

#pragma comment(lib, "C:/Users/dgist/Desktop/OpenCV 2.4.11/opencv/build/x86/vc11/lib/opencv_highgui2411d.lib")	// for opencv Lib
#pragma comment(lib, "C:/Users/dgist/Desktop/OpenCV 2.4.11/opencv/build/x86/vc11/lib/opencv_core2411d.lib")	// for opencv Lib

void salt(Mat &image, int n)
	  {
		for(int k=0; k<n; k++)
		{
			int i = rand()%image.cols;
			int j = rand()%image.rows;

			if(image.channels() == 1)
			{
				image.at<uchar>(j, i) = 255;
			}
			else if(image.channels() == 3)
			{
				image.at<Vec3b>(j, i)[0] = 255;
				image.at<Vec3b>(j, i)[1] = 255;
				image.at<Vec3b>(j, i)[2] = 255;
			}
		}
	 }

void colorReduce(Mat &image, int div = 64)
{
	int n1 = image.rows;
	int nc = image.cols * image.channels();

	for(int j=0; j<n1; j++)
	{
		uchar* data = image.ptr<uchar>(j);

		for(int i=0; i<nc; i++)
		{
			data[i] = data[i]/div*div + div/2;
		}
	}
}



int main(void)
{
	system("copy \".\\OpenCV2.4.11\\x86\\vc11\\bin\\*.dll\" ..\\debug");	// for opencv dll

	//read the image data in the file "MyPic.JPG" and store it in 'img'

	 Mat img = imread("lena.jpg", CV_LOAD_IMAGE_UNCHANGED);
	 Mat img_2 = imread("lena.jpg", CV_LOAD_IMAGE_UNCHANGED);
	 Mat result;
	 Mat img_3 = imread("lena.jpg", CV_LOAD_IMAGE_UNCHANGED);

     if (img.empty()) //check whether the image is loaded or not
     {
          cout << "Error : Image cannot be loaded..!!" << endl;
          return -1;
     }
	 

	 flip(img, result, 1);		//ÁÂ¿ì¹ÝÀü
	 salt(img_2, 3000);
	 colorReduce(img_3);

     namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);//create a window with the name "MyWindow"
	 namedWindow("Output Image", CV_WINDOW_AUTOSIZE);
	 namedWindow("Salt Image", CV_WINDOW_AUTOSIZE);
	 namedWindow("ColorReduce", CV_WINDOW_AUTOSIZE);

	 //display the image which is stored in the 'img' in the "MyWindow" window
     imshow("MyWindow", img);
	 imshow("Output Image", result);
	 imshow("Salt Image", img_2);
	 imshow("ColorReduce", img_3);

     waitKey(0);								//wait infinite time for a keypress
     destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"
	return 0;
}