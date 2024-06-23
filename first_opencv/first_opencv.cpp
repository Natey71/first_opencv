// first_opencv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
	string image_path = "C:/Users/mende/OneDrive/Pictures/Camera Roll/wooga.jpg";
	string im2 = "C:/Users/mende/OneDrive/Pictures/Camera Roll/wooga.jpg";

	Mat image = imread(image_path, IMREAD_COLOR);
	Mat image2 = imread(im2, cv::IMREAD_COLOR);

	if (image_path.empty() || im2.empty()) 
	{
		cout << "Could not read image: " << endl;
		return 1;
	}


	resize(image, image, { 500,500 }, 0, 0, cv::INTER_NEAREST);
	resize(image2, image2, { 500,500 }, 0, 0, cv::INTER_NEAREST);
	rotate(image2, image2, ROTATE_90_CLOCKWISE);


	for (int i = 0; i < image2.rows; i++)
	{
		for (int j = 0; j < image2.cols; j++)
		{
			Vec3b bgpixel = image2.at<Vec3b>(i, j);

			unsigned char grayScale = (bgpixel[2] + bgpixel[1] + bgpixel[0]) / 3;
			
			image2.at<Vec3b>(i, j) = { grayScale, grayScale, grayScale };
		}
	}

	


	imshow("Image", image);
	imshow("Image 2", image2);

	int k = waitKey(0);
	if (k == 's')
	{
		imwrite("wooga.png", image2);
	}


	return 0;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
