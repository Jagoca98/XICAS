#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	// initialize object
	Mat img;

	// load image from disk
	img = imread("mandril.jpg");

	// check if the image is available
	if (!img.data)
	{
		cout << "Error in loading the image!" << endl;
	}
	else
	{
		// create window canvas to show image
		namedWindow("original", CV_WINDOW_AUTOSIZE);

		// add the image to the window
		imshow("original", img);

		// wait till a key is pressed
		waitKey(0);

		// free memory
		destroyWindow("original");
	}
}