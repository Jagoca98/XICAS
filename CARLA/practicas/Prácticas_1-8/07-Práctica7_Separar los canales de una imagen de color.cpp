#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	// initialize object
	Mat original_image, modified_image;

	// load image from disk
	original_image = imread("lightballs.jpg", IMREAD_COLOR);

	// check if the image is available
	if (!original_image.data)
	{
		cout << "Error in loading the image!" << endl;
	}
	else
	{
		// convert the image from BGR to RGB
		cvtColor(original_image, modified_image, CV_BGR2RGB);

		// create a channel for each color with image size
		Mat red_channel(modified_image.size(), CV_8UC1);
		Mat green_channel(modified_image.size(), CV_8UC1);
		Mat blue_channel(modified_image.size(), CV_8UC1);
		// create an array of all channels
		Mat channels_array[] = {red_channel, green_channel, blue_channel};
		// split the image to separate channels
		split(modified_image, channels_array);

		// create window canvases to show images
		namedWindow("L03_E02_Original", CV_WINDOW_AUTOSIZE);
		namedWindow("L03_E02_Modified", CV_WINDOW_AUTOSIZE);
		namedWindow("L03_E02_Red_Color", CV_WINDOW_AUTOSIZE);
		namedWindow("L03_E02_Green_Color", CV_WINDOW_AUTOSIZE);
		namedWindow("L03_E02_Blue_Color", CV_WINDOW_AUTOSIZE);

		// add images to windows
		imshow("L03_E02_Original", original_image);
		imshow("L03_E02_Modified", modified_image);
		imshow("L03_E02_Red_Color", red_channel);
		imshow("L03_E02_Green_Color", green_channel);
		imshow("L03_E02_Blue_Color", blue_channel);

		// wait till a key is pressed
		waitKey(0);

		// free memory
		destroyAllWindows();
	}
}


