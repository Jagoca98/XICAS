// Practica 2

/*
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
*/
//Practica 4

/*
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
		Point p3((modified_image.rows) , (modified_image.cols));
		Point p4((modified_image.rows / 4) + 50, (modified_image.cols / 4) + 50);

		// draw a line
		line(modified_image, p2, p3, Scalar(0, 0, 255),3);

		// draw a rectangle
		rectangle(modified_image, p1, p4, Scalar(255, 255, 0));

		// draw a circle
		circle(modified_image, p2, 30, Scalar(0, 255, 255), -1);

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

*/

//Practica 5
/*
#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	// initialize object
	Mat original_image;

	// load image from disk
	original_image = imread("mandril.jpg", IMREAD_GRAYSCALE);

	// check if the image is available
	if (!original_image.data)
	{
		cout << "Error in loading the image!" << endl;
	}
	else
	{
		// initialize histogram calculating parameters
		int histogram_size = 256;
		float histogram_range[] = { 0, 256 };
		const float* histogram_ranges[] = { histogram_range };
		Mat histogram;

		// calculate image histogram
		calcHist(&original_image, 1, 0, Mat(), histogram, 1, &histogram_size, histogram_ranges);

		// print calculated histogram in the command window
		for (int i = 0; i < histogram_size; i++)
		{
			float bin_value = histogram.at<float>(i);
			cout << " " << bin_value;
		}

		// initialize histogram plotting parameters
		int bin_width = 2;
		int histogram_width = 512;
		int histogram_height = 400;
		Mat normalized_histogram;

		// empty image for the histogram plot
		Mat image_histogram(histogram_height, histogram_width, CV_8UC1, Scalar(255, 0, 0));
		// normalize histogram to fit the window
		normalize(histogram, normalized_histogram, 0, histogram_height, NORM_MINMAX, -1, Mat());

		for (int i = 1; i < histogram_size; i++)
		{
			Point p1(bin_width*(i - 1), histogram_height - cvRound(normalized_histogram.at<float>(i - 1)));
			Point p2(bin_width*(i), histogram_height - cvRound(normalized_histogram.at<float>(i)));
			line(image_histogram, p1, p2, Scalar(0, 0, 0), 2);
		}

		// create window canvas to show image
		namedWindow("L02_E02_Original", CV_WINDOW_AUTOSIZE);
		namedWindow("L02_E02_Histogram", CV_WINDOW_AUTOSIZE);

		// add the image to the window
		imshow("L02_E02_Original", original_image);
		imshow("L02_E02_Histogram", image_histogram);

		// wait till a key is pressed
		waitKey(0);

		// free memory
		destroyAllWindows();
	}
}
*/

//Practica 6
/*
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
	grayscale_image = imread("lena.jpg", IMREAD_GRAYSCALE);

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
*/

//Practica 7
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
		Mat channels_array[] = { red_channel, green_channel, blue_channel };
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
