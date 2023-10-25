//
// Példa képpontok elérésére
//
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int main() {

	Mat img(2, 3, CV_8UC3);

	// teljes pixel modositasa (a dian levo feladat)
	img.at<Vec3b>(0, 0) = Vec3b(0, 0, 255);
	img.at<Vec3b>(0, 1) = Vec3b(0, 255, 0);
	img.at<Vec3b>(0, 2) = Vec3b(255, 0, 0);

	img.at<Vec3b>(1, 0) = Vec3b(0, 0, 0);
	img.at<Vec3b>(1, 1) = Vec3b(39, 127, 255);
	img.at<Vec3b>(1, 2) = Vec3b(0, 255, 255);

	namedWindow("kiskep", WINDOW_NORMAL);
	resizeWindow("kiskep", Size(120, 80));
	imshow("kiskep", img);
	waitKey();

	// a jobb also sarokban levo pixel R komponensenek modositasa
	// Vec3b(0, 255, 255) ertekbol Vec3b(0, 255, 0) lesz
	img.at<Vec3b>(1, 2)[2] = 0;
	imshow("kiskep", img);

	waitKey();
	return 0;
}
