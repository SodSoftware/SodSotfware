#include "widget.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>

#include "u2net.h"

using namespace cv;
int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //Widget w;
    //w.show();

    //return a.exec();

	cv::Mat src = cv::imread("e:/000000000785.jpg");
	cv::Mat dst;
	U2net u2net;

	auto start = std::chrono::high_resolution_clock::now();
	u2net.saliency_detection(src, dst);
	auto end = std::chrono::high_resolution_clock::now();
	float duration = std::chrono::duration<float, std::milli>(end - start).count();
	std::cout << duration << std::endl;
}
