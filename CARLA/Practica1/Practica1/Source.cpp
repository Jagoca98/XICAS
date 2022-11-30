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
		cout << "error loading image" << endl;
		return 1;
	}
	// create window canvas to show image
	namedWindow("original", CV_WINDOW_AUTOSIZE);

	// add the image to the window
	imshow("original", img);

	// wait till a key is pressed
	waitKey(0);

	// free memory
	destroyWindow("original");
	
	return 0;
}