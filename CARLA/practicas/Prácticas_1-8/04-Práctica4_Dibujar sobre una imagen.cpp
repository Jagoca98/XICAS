#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	// initialize object
	Mat original_image, modified_image;

	// load image from disk
	original_image = imread("lena.jpg");
	
	// check if the image is available
	if (!original_image.data)
	{
		cout << "Error in loading the image!" << endl;
	}
	else
	{
		// copy the image matrix to the modified image
		// method 1 clone()
		// modified_image = original_image.clone();
		
		// method 2 copyTo()
		original_image.copyTo(modified_image);
		
		// define points
		Point p1(modified_image.rows / 2, modified_image.cols / 2);
		Point p2((modified_image.rows / 2) + 25, (modified_image.cols / 2) + 25);
		
		// draw a line
		line(modified_image, p1, p2, Scalar(255, 0, 0));
		
		// draw a rectangle
		rectangle(modified_image, p1, p2, Scalar(0, 255, 0));
		
		// draw a circle
		circle(modified_image, p1, 25, Scalar(0, 0, 255));

		// create window canvas to show image
		namedWindow("L02_E01_Original", CV_WINDOW_AUTOSIZE);
		namedWindow("L02_E01_Modified", CV_WINDOW_AUTOSIZE);

		// add the image to the window
		imshow("L02_E01_Original", original_image);
		imshow("L02_E01_Modified", modified_image);

		// wait till a key is pressed
		waitKey(0);

		// free memory
		destroyWindow("L02_E01_Original");
		destroyWindow("L02_E01_Modified");
	}
}