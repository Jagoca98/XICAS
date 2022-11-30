#include "opencv\cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	// initialize object
	Mat original_image;

	// load image from disk
	original_image = imread("lena.jpg", IMREAD_GRAYSCALE);
	
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
		Mat image_histogram(histogram_height, histogram_width, CV_8UC1, Scalar(255, 0, 0)); //Scalar(0)
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
