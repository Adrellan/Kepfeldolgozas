//
// A kep egy reszenek hasznalata
//

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
	// Egy kep elkesztese
	Mat img(400, 600, CV_8UC3);

	// Pirosra szinezzuk
	img.setTo(Scalar(0, 0, 255));

	// Egy egyszeru teglalap, a koordinatai a kep felso reszet irjak le
	Rect upper_half(0, 0, img.cols, img.rows / 2);

	// A teglalap segitsegevel kijelöljuk a kepreszt majd atszinezzuk
	img(upper_half).setTo(Scalar(0, 255, 255));

	// Az eredmeny
	imshow("eredmeny", img);
	waitKey();

	return 0;
}