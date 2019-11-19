
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>


#include "beziersplines.h"
#include "image_statistics.h"



float eval_area(std::vector<cv::Point2f> a1, std::vector<cv::Point2f> a2, std::vector<cv::Point2f> b1, std::vector<cv::Point2f> b2, cv::Mat frame);


float eval_opening(std::vector<cv::Point2f> a1, std::vector<cv::Point2f> a2, cv::Mat frame);

//not used for evaluation
float eval_meandist(std::vector<cv::Point2f> a1, std::vector<cv::Point2f> a2);


namespace EYELIDDETECTION{


eye eyelid(cv::Mat pic, double border);





}



