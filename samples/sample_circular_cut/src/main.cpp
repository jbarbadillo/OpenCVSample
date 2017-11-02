#include "config.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <fstream>
#include "cut_detector.h"

int main(int argc, char *argv[]) {

	//Data submitted from configuration or other service
	float plateWidth = 0.2f;
	float plateHeight = 0.14f;
	float minRadius = 0.02f;
	float maxRadius = 0.08;
	cv::VideoCapture videoSource(0);

	//TODO remove, testing purposes only
	//std::string data_path =TEST_DATA"/metal-plate_01.png";
	//videoSource.open(data_path);

	if (!videoSource.isOpened()) {
		std::cout << "Error opening default camera" << std::endl;
		return -1;
	}
	//TODO pass dimensions for resizing image before processing
	double cameraWidth = 640;
	double cameraHeight = 480;

	CutDetector *cutDetector = new CutDetector(plateHeight,plateWidth, minRadius, maxRadius);
	std::vector<float> diameters;
	std::string status;

	cv::Mat frame;
	for (;;) {
		videoSource >> frame;
		cutDetector->detectCuts(frame, diameters, status);

		std::cout<<"Cuts detected: " << diameters.size() <<std::endl;

		for (int i = 0; i < diameters.size(); i++) {
			std::cout << "Cut "<< i+1 << " diameter: "<< diameters[i] << std::endl;
		}
		std::cout << "Status: " << status << std::endl;

		//Optional write to file
		/*std::ofstream results;
		results.open(TEST_DATA"/results.csv");
		results << "Cuts: " << diameters.size() << " Status: " << status;
		results.close;*/
	}

}