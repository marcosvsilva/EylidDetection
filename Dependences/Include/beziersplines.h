


#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>




void poly_fit_bezier_splines_geo_point_calc(std::vector<cv::Point2f> points, cv::Point2f *p1, cv::Point2f *p2, int n);



std::vector<cv::Point2f> poly_fit_bezier_splines(std::vector<cv::Point2f> points, cv::Mat img);



cv::Point2f point_on_line(std::vector<cv::Point2f> list, cv::Point2f akp, cv::Point2f ortho);




float poly_calc_max_dist(std::vector<cv::Point2f> upper, std::vector<cv::Point2f> lower, cv::Point2f lst, cv::Point2f rst, cv::Mat img);




