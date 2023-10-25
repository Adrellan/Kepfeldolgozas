//
// Kepek letrehozasa
//

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

// A képet tartalmazó mappa útvonala
string img_dir = "../images/";


int main() {

	// 1: szürkeskálás kép (8 bit, 1 csatorna),  200 sor, 50 oszlop 
	Mat img1(200, 50, CV_8UC1);

	// 2: színes kép (24 bit), 50 sor, 200 oszlop
	Mat img2(50, 200, CV_8UC3);   
	
	// 3: tiszta FEKETE kép (8 bit, 1 csatorna), 20 sor, 40 oszlop
	Mat img3 = Mat::zeros(20, 40, CV_8UC1);

	// 4: tiszta FEHÉR kép (8 bit, 1 csatorna), 20 sor, 40 oszlop
	Mat img4(20, 40, CV_8UC1);
	img4.setTo(255);

	// 5: egy színes kép (24 bit, 3 csatorna), mely tiszta PIROS, 99 sor, 121 oszlop
	Mat img5(99, 121, CV_8UC3);
	img5.setTo(Scalar(0, 0, 255));  

	// 6: Egy beolvasott képpel azonos méretű és típusú kép létrehozása. 
	Mat img6_orig = imread(img_dir + "joke.jpg");
	Mat img6(img6_orig.size(), img6_orig.type());
	
	// 7: Egy beolvasott képpel azonos típus kép létrehozáse, melynek szélessége az eredeti,
	// magassága az eredeti fele. 
	Mat img7_orig = imread(img_dir + "joke.jpg");
	Mat img7(img7_orig.rows / 2, img7_orig.cols, img7_orig.type());
	
	// Ablakok megjelenítése, majd bill. leütés után azok lezárása. 
	imshow("Ex1", img1);
	imshow("Ex2", img2);
	waitKey();
	destroyAllWindows();   
	
	imshow("Ex3", img3);
	imshow("Ex4", img4);
	imshow("Ex5", img5);
	waitKey();
	destroyAllWindows();
	
	imshow("Ex6", img6_orig);
	imshow("Ex6", img6);
	waitKey();
	destroyAllWindows();
	
	imshow("Ex7", img7_orig);
	imshow("Ex7", img7);
	waitKey();
	destroyAllWindows();

	return 0;
}