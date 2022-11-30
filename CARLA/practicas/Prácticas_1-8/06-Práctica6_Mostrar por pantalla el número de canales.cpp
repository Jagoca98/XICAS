#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	// initialize object
	Mat original_image, grayscale_image;

	// load image from disk
	original_image = imread("lena.jpg", IMREAD_COLOR);

	// load image from disk as gray scale
	grayscale_image = imread("Images/lena.jpg", IMREAD_GRAYSCALE);

	// check if the image is available
	if (!original_image.data || !grayscale_image.data)
	{
		cout << "Error in loading the image!" << endl;
	}
	else
	{
		// print out number of channels colors in the command window
		cout << "Original Image has: " << original_image.channels() << " channels" << endl;
		cout << "Grayscale Image has: " << grayscale_image.channels() << " channels" << endl;
		
		// create window canvas to show image
		namedWindow("L03_E01_Original", CV_WINDOW_AUTOSIZE);
		namedWindow("L03_E01_Grayscale", CV_WINDOW_AUTOSIZE);

		// add the image to the window
		imshow("L03_E01_Original", original_image);
		imshow("L03_E01_Grayscale", grayscale_image);

		// wait till a key is pressed
		waitKey(0);

		// free memory
		destroyAllWindows();
	}
}


