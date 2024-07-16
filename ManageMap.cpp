#include "ManageMap.h"
#include "Input.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

ManageMap::ManageMap():input(1),imgMap({{}})
{
	
	//Input input(1);
	/*if(input)
		cout << input.start[0]->name << endl;*/
	//input.print_start_commands();
	map = convertToIntVector(input.getWorld()->data);
	printMap();
}

vector<vector<int>> ManageMap::convertToIntVector(vector<vector<string>>& data) {
	vector<vector<int>> result;
	for (const auto& row : data) {
		vector<int> intRow;
		for (const auto& elem : row) {
			intRow.push_back(stoi(elem));
		}
		result.push_back(intRow);
	}
	return result;
}

//void ManageMap::printMap()
//{
//	int mapSize = map.size();
//	vector<Mat> big;
//	for (int i = 0; i < mapSize; i++) {
//		int rowSize = map[i].size();
//		vector<Mat> m;
//		if (i < imgMap.size())
//			imgMap.push_back(m);
//		for (int j = 0; j < rowSize; j++) {
//			string path = "D:/BootCamp/CrackingTheCode/AnnakPictures/TILES/"+ to_string(map[i][j])+".png";
//			cv::Mat img = imread(path, IMREAD_COLOR);
//			if (j >= imgMap[i].size())
//				imgMap[i].push_back(img);
//			imgMap[i][j] = img;
//		}
//		hconcat(imgMap[i], m);
//		big.push_back();
//	}
//	//hconcat(imgMap, world);
//	if (world.empty())
//	{
//		std::cout << "Could not read the image: " << endl;
//		return;
//	}
//	imshow("Display window", world);
//	int k = waitKey(0); // Wait for a keystroke in the window
//}


void ManageMap::printMap() {
    int mapSize = map.size();
    imgMap.resize(mapSize);

    // Iterate through the map to read images
    for (int i = 0; i < mapSize; i++) {
        int rowSize = map[i].size();
        imgMap[i].resize(rowSize);

        for (int j = 0; j < rowSize; j++) {
            string path = "D:/BootCamp/CrackingTheCode/AnnakPictures/TILES/" + to_string(map[i][j]) + ".png";
            Mat img = imread(path, IMREAD_COLOR);
    
            if (img.empty()) {
                cerr << "Could not read the image: " << path << endl;
                return;
            }

            cv::resize(img, img, Size(150, 150));
            imgMap[i][j] = img;
        }
    }

    // Concatenate images row-wise and then concatenate the rows
    vector<Mat> concatenatedRows;
    for (const auto& row : imgMap) {
        Mat concatenatedRow;
        hconcat(row, concatenatedRow);
        concatenatedRows.push_back(concatenatedRow);
    }

    // Concatenate all the rows vertically to form the final map
    vconcat(concatenatedRows, world);

    if (world.empty()) {
        cerr << "The world image is empty!" << endl;
        return;
    }

    imshow("Annak", world);
    int k = waitKey(0); // Wait for a keystroke in the window

    printGrid();
}

//void ManageMap::printGrid()
//{
//    for (int i = 0; i < imgMap.size() * 50; i += 10) {
//        cv::line(imgMap, cv::Point(i, 0), cv::Point(i, imgMap[i].size() * 50), cv::Scalar(255, 0, 0), 5);
//        for (int j = 0; j < imgMap[i].size() * 50; j += 10) {
//            cv::line(imgMap, cv::Point(i, j), cv::Point(i+50, j), cv::Scalar(255, 0, 0), 5);
//        }
//    }
//
//}

//#include "ManageMap.h"
//#include "Input.h"
//#include <opencv2/core.hpp>
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//ManageMap::ManageMap() : input(1), imgMap({ {} })
//{
//    map = convertToIntVector(input.getWorld()->data);
//    printMap();
//}
//
//vector<vector<int>> ManageMap::convertToIntVector(vector<vector<string>>& data) {
//    vector<vector<int>> result;
//    for (const auto& row : data) {
//        vector<int> intRow;
//        for (const auto& elem : row) {
//            intRow.push_back(stoi(elem));
//        }
//        result.push_back(intRow);
//    }
//    return result;
//}
//
//void ManageMap::printMap() {
//    int mapSize = map.size();
//    imgMap.resize(mapSize);
//
//    for (int i = 0; i < mapSize; i++) {
//        int rowSize = map[i].size();
//        imgMap[i].resize(rowSize);
//
//        for (int j = 0; j < rowSize; j++) {
//            string path = "D:/BootCamp/CrackingTheCode/AnnakPictures/TILES/" + to_string(map[i][j]) + ".png";
//            Mat img = imread(path, IMREAD_COLOR);
//
//            if (img.empty()) {
//                cerr << "Could not read the image: " << path << endl;
//                return;
//            }
//
//            imgMap[i][j] = img;
//        }
//    }
//
//    vector<Mat> concatenatedRows;
//    for (const auto& row : imgMap) {
//        Mat concatenatedRow;
//        hconcat(row, concatenatedRow);
//        concatenatedRows.push_back(concatenatedRow);
//    }
//
//    vconcat(concatenatedRows, world);
//
//    if (world.empty()) {
//        cerr << "The world image is empty!" << endl;
//        return;
//    }
//
//    imshow("Annak", world);
//    waitKey(0); // Wait for a keystroke in the window
//
//    printGrid();
//}
//

void ManageMap::printGrid()
{
    for (int i = 0; i < world.rows + 300; i += 30) {
        line(world, Point(i, 0), Point(i, world.rows), Scalar(255, 0, 0), 1);
    }

    for (int j = 0; j < world.cols; j += 30) {
        line(world, Point(0, j), Point(world.cols, j), Scalar(255, 0, 0), 1);
    }

    imshow("Grid", world);
    waitKey(0);
}

