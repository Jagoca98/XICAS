#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	// initialize object
	Mat original_image, modified_image;

	// load image from disk
	original_image = imread("mandril.jpg", IMREAD_COLOR);

	// check if the image is available
	if (!original_image.data)
	{
		cout << "Error in loading the image!" << endl;
	}
	else
	{
		// convert the image from BGR to RGB
		cvtColor(original_image, modified_image, CV_BGR2HSV);

		// create a channel for each color with image size
		Mat hue_channel(modified_image.size(), CV_8UC1);
		Mat saturation_channel(modified_image.size(), CV_8UC1);
		Mat value_channel(modified_image.size(), CV_8UC1);
		// create an array of all channels
		Mat channels_array[] = { hue_channel, saturation_channel, value_channel };
		// split the image to separate channels
		split(modified_image, channels_array);

		// initialize histogram calculating parameters
		int histogram_size = 256;
		float histogram_range[] = { 0, 256 };
		const float* histogram_ranges[] = { histogram_range };
		Mat hue_histogram, saturation_histogram, value_histogram;

		// calculate image histograms
		calcHist(&hue_channel, 1, 0, Mat(), hue_histogram, 1, &histogram_size, histogram_ranges);
		calcHist(&saturation_channel, 1, 0, Mat(), saturation_histogram, 1, &histogram_size, histogram_ranges);
		calcHist(&value_channel, 1, 0, Mat(), value_histogram, 1, &histogram_size, histogram_ranges);

		// initialize histogram plotting parameters
		int bin_width = 2;
		int histogram_width = 512;
		int histogram_height = 400;
		Mat normalized_hue_histogram, normalized_saturation_histogram, normalized_value_histogram;

		// empty image for the histogram plot
		Mat image_histogram(histogram_height, histogram_width, CV_8UC3, Scalar(255, 255, 255));
		// normalize histograms to fit the window
		normalize(hue_histogram, normalized_hue_histogram, 0, histogram_height, NORM_MINMAX, -1, Mat());
		normalize(saturation_histogram, normalized_saturation_histogram, 0, histogram_height, NORM_MINMAX, -1, Mat());
		normalize(value_histogram, normalized_value_histogram, 0, histogram_height, NORM_MINMAX, -1, Mat());

		for (int i = 1; i < histogram_size; i++)
		{
			Point p1(bin_width*(i - 1), histogram_height - cvRound(normalized_hue_histogram.at<float>(i - 1)));
			Point p2(bin_width*(i), histogram_height - cvRound(normalized_hue_histogram.at<float>(i)));
			line(image_histogram, p1, p2, Scalar(255, 0, 0), 2); 

			Point p3(bin_width*(i - 1), histogram_height - cvRound(normalized_saturation_histogram.at<float>(i - 1)));
			Point p4(bin_width*(i), histogram_height - cvRound(normalized_saturation_histogram.at<float>(i)));
			line(image_histogram, p3, p4, Scalar(0, 255, 0), 2);

			Point p5(bin_width*(i - 1), histogram_height - cvRound(normalized_value_histogram.at<float>(i - 1)));
			Point p6(bin_width*(i), histogram_height - cvRound(normalized_value_histogram.at<float>(i)));
			line(image_histogram, p5, p6, Scalar(0, 0, 255), 2);
		}
		
		// create window canvases to show images
		namedWindow("L03_E03_Original", CV_WINDOW_AUTOSIZE);
		namedWindow("L03_E03_Modified", CV_WINDOW_AUTOSIZE);
		namedWindow("L03_E03_Hue_Color", CV_WINDOW_AUTOSIZE);
		namedWindow("L03_E03_Saturation_Color", CV_WINDOW_AUTOSIZE);
		namedWindow("L03_E03_Value_Color", CV_WINDOW_AUTOSIZE);
		namedWindow("L03_E03_HSV_Histogram", CV_WINDOW_AUTOSIZE);

		// add images to windows
		imshow("L03_E03_Original", original_image);
		imshow("L03_E03_Modified", modified_image);
		imshow("L03_E03_Hue_Color", hue_channel);
		imshow("L03_E03_Saturation_Color", saturation_channel);
		imshow("L03_E03_Value_Color", value_channel);
		imshow("L03_E03_HSV_Histogram", image_histogram);

		// wait till a key is pressed
		waitKey(0);

		// free memory
		destroyAllWindows();
	}
}


