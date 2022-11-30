#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std; 

#define ESCAPE 27

int main(int argc, char* argv[])
{
	// initialize object
	Mat frame;
	
	// initialize video capturing object
	VideoCapture capture;

	// keyboard pressed
	char pressedKey = 0;

	// check the success for image reading
	bool success;

	// load video from disk
	capture.open("honda-asimo.avi");

	// check if the video is available
	if (!capture.isOpened())
	{
		cout << "Error in loading the video!" << endl;
	}
	else
	{
		// create window canvas to show video
		namedWindow("L01_E02", CV_WINDOW_AUTOSIZE);

		while (pressedKey != ESCAPE)
		{
			// read frame by frame in a loop
			success = capture.read(frame);

			// check if it was successful read
			if (success == false)
			{
				cout << "Can't read the frame from file!" << endl;
				return 1;
			}

			// add the frame to the window
			imshow("L01_E02", frame);

			// update the pressed key
			pressedKey = waitKey(0);
		}

		// free memory
		destroyWindow("L01_E02");
		capture.release();
	}
}