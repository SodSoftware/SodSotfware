#pragma once
#include <opencv2/opencv.hpp>
#include <gpu.h>
#include <vulkan/vulkan.h>
#include "net.h"
#include <iostream>
using namespace std;

class U2net
{
public:
	U2net(bool gpu_available=true);
	~U2net();

    void saliency_detection(cv::Mat& src, cv::Mat& dst);
    ncnn::Net *net;
	void add_alpha(cv::Mat& src, cv::Mat& alpha, cv::Mat& dst);
	const float mean[3] = { 0.485 * 255.0, 0.456 * 255.0, 0.406 * 255.0 };
	const float norm[3] = { 1.0 / (0.229 * 255.0), 1.0 / (0.224 * 255.0), 1.0 / (0.225 * 255.0) };
};

