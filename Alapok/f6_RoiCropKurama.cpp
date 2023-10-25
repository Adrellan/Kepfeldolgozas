//
// A kep egy reszenek hasznalata (cropping)
//

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
	// Egy kep betoltese
	Mat img = imread("kurama.jpg", IMREAD_COLOR);
	
	// Egy teglalap a kivant kerettel
	int cut_size = 20;
      //assert( img.width > cut_size * 2 && img.height > cut_size * 2);
	Rect r(cut_size, cut_size, img.cols - 2*cut_size, img.rows - 2*cut_size);

	// Masolat keszitese a teglalap altal kijelolt kepreszrol 
	Mat part = img(r).clone();

	// Az eredmenyt a .cpp mellett talalod.
	imwrite("cropped.png", part);

	return 0;
}