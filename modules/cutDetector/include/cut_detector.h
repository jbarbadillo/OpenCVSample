#ifndef CUT_DETECTOR_H
#define CUT_DETECTOR_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class CutDetector {
public:
	CutDetector(float& w, float& h, float& minRadius, float& maxRadius);
	void detectCuts(cv::Mat& frame, std::vector<float>& diameters, std::string& status);
private:
	float _width, _height, _minRadius, _maxRadius;
	cv::Mat _grayFrame;

	void checkCutsDimensions(std::vector<cv::Vec3f>& circles, std::string& status);

};

#endif