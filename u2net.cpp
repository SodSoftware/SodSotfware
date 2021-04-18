#include "u2net.h"
#define WIDTH 320
#define HEIGHT 320




U2net::U2net(bool gpu_available)
{
	ncnn::create_gpu_instance();
	net = new ncnn::Net;
	net->set_vulkan_device(0);
	net->opt.use_vulkan_compute = true;
	net->load_param("u2netp_sim-opt.param");
	net->load_model("u2netp_sim-opt.bin");
}


U2net::~U2net()
{
	delete net;
	net = nullptr;
	ncnn::destroy_gpu_instance();
}

void U2net::saliency_detection(cv::Mat & src, cv::Mat & dst)
{
	cv::Size size = src.size();
    cv::Mat rgb;
    cv::cvtColor(src, rgb, cv::COLOR_BGR2RGB);

    cv::Mat resized;
    cv::resize(rgb, resized, cv::Size(WIDTH, HEIGHT), cv::INTER_NEAREST);

    ncnn::Mat in = ncnn::Mat::from_pixels(resized.data, ncnn::Mat::PIXEL_RGB, WIDTH, HEIGHT);
    in.substract_mean_normalize(mean, norm);

    ncnn::Mat out;

    ncnn::Extractor ex = net->create_extractor();
    ex.set_num_threads(4);
    ex.input("input", in);

    ex.extract("output", out);

    cv::Mat a(in.h, in.w, CV_32FC1);
    memcpy((uchar*)a.data, out.data, out.w * out.h * sizeof(float));

    cv::Mat predict(a.size(), CV_8UC1);
    a.convertTo(predict, CV_8UC1, 255);

    cv::resize(predict, predict, size, cv::INTER_NEAREST);

    // 二值化
    cv::Mat mask;
    cv::Mat result;
    cv::threshold(predict, mask, 128, 255, cv::THRESH_BINARY);
    src.copyTo(result, mask);

    add_alpha(result, mask, dst);
}

void U2net::add_alpha(cv::Mat & src, cv::Mat & alpha, cv::Mat & dst)
{
	dst = cv::Mat(src.rows, src.cols, CV_8UC4);

	std::vector<cv::Mat> srcChannels;
	std::vector<cv::Mat> dstChannels;
	//分离通道
	cv::split(src, srcChannels);

	dstChannels.push_back(srcChannels[0]);
	dstChannels.push_back(srcChannels[1]);
	dstChannels.push_back(srcChannels[2]);
	//添加透明度通道
	dstChannels.push_back(alpha);
	//合并通道
	cv::merge(dstChannels, dst);
}
