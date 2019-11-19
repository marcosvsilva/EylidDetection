#include "pch.h"
#include <iostream>

//#include "stdafx.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

#include <iostream>            
#include <fstream>
#include <time.h>
#include <stdio.h>

#include "algo.h"

int _tmain(int argc, char* argv[])
{

	std::fstream Quelldatei;
	Quelldatei.open("...\\outlines.csv");


	std::fstream auswertung;
	auswertung.open("...\\results.txt", std::fstream::trunc | std::fstream::out);

	int frame_size = 5101;



	std::string str_number;
	char buffer[20];

	cv::Mat frame;
	for (int k = 1; k <= frame_size; k++) {

		std::cout << k << std::endl;

		str_number = sprintf_s(buffer, "%d", k);
		str_number = buffer;
		std::string path_images = "...\\eyelid_data\\" + str_number + ".png";

		frame = cv::imread(path_images, cv::IMREAD_GRAYSCALE);


		std::vector<cv::Point2f> upper, lower;

		std::string line[21];
		int line_val[21];



		do {// if starting not at 1
			Quelldatei >> line[0] >> line[1] >> line[2] >> line[3] >> line[4] >> line[5] >> line[6] >> line[7] >> line[8] >> line[9]
				>> line[10] >> line[11] >> line[12] >> line[13] >> line[14] >> line[15] >> line[16] >> line[17] >> line[18] >> line[19]
				>> line[20];





			for (int toint = 0; toint < 21; toint++) {
				line_val[toint] = atoi(line[toint].c_str());

				if (toint % 2 == 0 && toint > 0)
					line_val[toint] = 288 - line_val[toint];

			}

		} while (line_val[0] != k);




		for (int toint = 1; toint < 13; toint += 2) {
			cv::Point ak_point;

			ak_point.x = line_val[toint];
			ak_point.y = line_val[toint + 1];

			upper.push_back(ak_point);
		}
		for (int toint = 11; toint < 21; toint += 2) {
			cv::Point ak_point;

			ak_point.x = line_val[toint];
			ak_point.y = line_val[toint + 1];

			lower.push_back(ak_point);
		}
		lower.push_back(cv::Point2f(line_val[1], line_val[2]));





		std::vector<cv::Point2f> upper_eyelid = poly_fit_bezier_splines(upper, frame);
		std::vector<cv::Point2f> lower_eyelid = poly_fit_bezier_splines(lower, frame);




		eye detected;
		clock_t t;
		t = clock();
		for (int zi = 0; zi < 100; zi++)
			detected = EYELIDDETECTION::eyelid(frame, 0.1);
		t = clock() - t;
		printf("It took me %d clicks (%f seconds).\n", t, float(((float)t) / CLOCKS_PER_SEC) / 100.0);




		float labled_dist = poly_calc_max_dist(upper_eyelid, lower_eyelid, cv::Point2f(line_val[1], line_val[2]), cv::Point2f(line_val[11], line_val[12]), frame);






		float eyelid_dist = eval_opening(detected.lower, detected.upper, frame);

		float eye_area = eval_area(detected.lower, detected.upper, lower_eyelid, upper_eyelid, frame);


		std::cout << 0 << ":" << 0 << "|" << abs(labled_dist - eyelid_dist) << "|" << eye_area << std::endl;

		auswertung << 0 << ";" << 0 << ";" << abs(labled_dist - eyelid_dist) << ";" << eye_area << std::endl;


		for (int i = 0; i < upper_eyelid.size(); i++) {
			if (upper_eyelid.at(i).x > 0 && upper_eyelid.at(i).x < frame.cols && upper_eyelid.at(i).y>0 && upper_eyelid.at(i).y < frame.rows)
				frame.at<unsigned char>(upper_eyelid.at(i)) = 255;
		}

		for (int i = 0; i < lower_eyelid.size(); i++) {
			if (lower_eyelid.at(i).x > 0 && lower_eyelid.at(i).x < frame.cols && lower_eyelid.at(i).y>0 && lower_eyelid.at(i).y < frame.rows)
				frame.at<unsigned char>(lower_eyelid.at(i)) = 255;
		}


		for (int i = 0; i < detected.lower.size(); i++) {
			if (detected.lower.at(i).x > 0 && detected.lower.at(i).x < frame.cols && detected.lower.at(i).y>0 && detected.lower.at(i).y < frame.rows)
				frame.at<unsigned char>(detected.lower.at(i)) = 255;
			//frame.at<unsigned char>(detected.lower.at(i)-cv::Point2f(0,5))=255;
		}

		for (int i = 0; i < detected.upper.size(); i++) {
			if (detected.upper.at(i).x > 0 && detected.upper.at(i).x < frame.cols && detected.upper.at(i).y>0 && detected.upper.at(i).y < frame.rows)
				frame.at<unsigned char>(detected.upper.at(i)) = 255;
		}



		imshow("frame", frame);

		cv::waitKey(1000);


	}

	Quelldatei.close();
	auswertung.close();


	std::cout << "ENDE:" << std::endl;
	int tt;
	std::cin >> tt;

	return 0;
}