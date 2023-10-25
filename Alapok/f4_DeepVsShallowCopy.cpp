//
// shallow copy vs deep copy
//

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main() {
      // egy kep beolvasasa
	Mat img = imread("kurama.jpg");
	if (img.empty()) {
		cout << "Upsz. Ez nem nyithato." << endl;
		exit(-1);
	}

	imshow("eredeti", img);


	// shallow copy ("alias")
	Mat copy1 = img;

	// a masolat pixeleinek megvaltoztatasa
	copy1.setTo(0);
	imshow("eredeti kep a masolat modositas utan", img);

	// ujra beolvassuk a kepet
	img = imread("kurama.jpg");
	if (img.empty()) {
		cout << "Upsz. Ez nem nyithato." << endl;
		exit(-1);
	}

	// deep copy
	Mat copy2 = img.clone();

	// a masolat pixeleinek megvaltoztatasa 
	copy2.setTo(0);

	imshow("eredeti kep a masolat modositasa utan", img);
	waitKey();

}