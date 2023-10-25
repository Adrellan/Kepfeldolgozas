//
// A kép másolása egy másik kép adott részére 
//    (kiskep.copyTo(nagykep_reszlete))
//

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
	// A nagy kép, amire másolunk
	Mat img = imread("background.jpg", IMREAD_COLOR);

	// A másolandó kép
	Mat kurama = imread("kurama.jpg", IMREAD_COLOR);

      // Elég nagy, ezért lekicsinyítjük
	resize(kurama, kurama, Size(200, 200));

	// Kijelöljük a részt, ahová másolni fogunk
	Mat middle_200 = img(Rect(img.cols/2 - 100, img.rows/2 - 100, 200, 200));
	// A kis képet a nagyobb közepére másoljuk
	kurama.copyTo(middle_200);

	// Eg picit ronda, de a miénk...
	imshow("img", img);
	waitKey();

	return 0;
}