#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace std;
using namespace cv;


/// author: Denny Vamilion
/// Funktion: Pixel manipulation
/// Date: 01.06.2022

void salt(Mat image, int n) {
	int i, j;

	for (int k = 0; k < n; k++) {
		i = rand() % image.cols; 
		j = rand() % image.rows;

		if (image.type() == CV_8UC1)
		{
			image.at<uchar>(j, i) = 255;
		}
		else if (image.type() == CV_8UC3) {
			image.at<Vec3b>(j, i)[0] = 255;
			image.at<Vec3b>(j, i)[1] = 255;
			image.at<Vec3b>(j, i)[2] = 255;
		}
	}
}

int main() {
	//Mat image = imread("C:\\daniel.jpg"); // load image
	//salt(image, 3000);
	//imshow("Image", image);
	//waitKey(0);

	VideoCapture cap(0);
	while (true) {
		Mat frame;
		Mat i;
		cap >> frame;
		salt(frame, 3000);
		flip(frame,i, 1);
		imshow("image", i);
		waitKey(1);
	}
}
