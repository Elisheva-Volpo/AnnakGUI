#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Input.h"
using namespace cv;
class ManageMap
{
	Input input;
	vector<vector<int>> map;
	vector<vector<Mat>> imgMap;
	Mat world;

public:

	ManageMap();
	vector<vector<int>> convertToIntVector(vector<vector<string>>& data);
	void printMap();
	void printGrid();
};

