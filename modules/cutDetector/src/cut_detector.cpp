#include "cut_detector.h"

CutDetector::CutDetector(float& w, float& h, float& minRadius, float& maxRadius) :
	_width(w), _height(h), _minRadius(minRadius), _maxRadius(maxRadius) {

}
void CutDetector::detectCuts(cv::Mat& frame, std::vector<float>& diameters, std::string& status) {
	_grayFrame = frame.clone();
	
	cv::cvtColor(frame, _grayFrame, cv::COLOR_BGR2GRAY);
	cv::resize(_grayFrame, _grayFrame, cv::Size(frame.cols / 6, frame.rows / 6));
	cv::GaussianBlur(_grayFrame, _grayFrame, cv::Size(7, 7), 1.5, 1.5);
	cv::imshow("Frame",_grayFrame);
	cv::waitKey(0);
	std::vector<cv::Vec3f> circles;

	cv::HoughCircles(_grayFrame, circles, CV_HOUGH_GRADIENT, 1, _grayFrame.rows / 10, 200, 50, 0, 0);

	for (int i = 0; i < circles.size(); i++)
	{
		diameters.push_back(circles[i][2]/frame.rows*_width);
		cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		// circle center
		circle(_grayFrame, center, 3, cv::Scalar(0, 255, 0), -1, 8, 0);
		// circle outline
		circle(_grayFrame, center, radius, cv::Scalar(0, 0, 255), 3, 8, 0);
	}
	cv::imshow("Results", _grayFrame);
	cv::waitKey(0);
	checkCutsDimensions(circles,status);
}
void CutDetector::checkCutsDimensions(std::vector<cv::Vec3f>& circles, std::string& status) {
	if (circles.size() != 2) {
		status = "ERROR_WRONG_NUMBER";
	}
	else {
		if (circles[0][2] < _maxRadius && circles[0][2] >_minRadius && circles[1][2] <_maxRadius && circles[1][2]> _minRadius) {
			status = "ERROR_WRONG_DIMENSIONS";
		}
		else {
			status = "CORRECT_CUT";
		}
	}
}