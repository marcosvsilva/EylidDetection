

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

struct eye{
	std::vector<cv::Point2f> upper,lower;
};






void median_u_rescale(cv::Mat *pic, cv::Mat *result, int fak);



void parabel_fit2(std::vector<cv::Point> posis, float *param, cv::Point st);


void parabel_fit2(std::vector<cv::Point2f> posis, float *param, cv::Point st);

std::vector<cv::Point> fit_lower_line_to_pic(cv::Mat pic, cv::Point st, double border, int step);


cv::Point round(cv::Point2f a);



float eval_lines(std::vector<cv::Point> line, cv::Mat pic);

float eval_lines(std::vector<cv::Point2f> line, cv::Mat pic);

std::vector<cv::Point> eval_lines_best_points(std::vector<cv::Point> line, cv::Mat pic, float amount);



std::vector<cv::Point> fit_upper_line_to_pic(cv::Mat pic, cv::Point st, std::vector<cv::Point> lower_line, double border, int step);





eye horzscattering2(cv::Mat pic, cv::Mat pic_real, double border);









