// AnnakGUI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Input.h"
#include "ManageMap.h"
using namespace cv;

int main()
{
    ManageMap game;
    /*cv::Mat img = cv::imread("D:/גיבוי קבצי משתמש לא לגעת!!/Downloads/154 תחילת הלילה.jpg");
    namedWindow("Yishay and Shany wading", WINDOW_AUTOSIZE);
    cv::imshow("Yishay and Shany wading", img);
    cv::moveWindow("Yishay and Shany wading", 0, 0);
    cv::waitKey(0);
    cv::destroyAllWindows();*/
    /*std::string image_path = samples::findFile("starry_night.jpg");
    cv::Mat a = imread(image_path,IMREAD_COLOR);
    cv::Mat b = imread(image_path, IMREAD_COLOR);
    cv::Mat dst;
    std::vector<cv::Mat> matrices = {
            a, b
    };
    hconcat(matrices, dst);
    if (a.empty()||b.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }*/
    //Mat img = imread(image_path, IMREAD_COLOR);

    //if (img.empty())
    //{
    //    std::cout << "Could not read the image: " << image_path << std::endl;
    //    return 1;
    //}

    //imshow("Display window", dst);
    //int k = waitKey(0); // Wait for a keystroke in the window

    //if (k == 's')
    //{
    //    imwrite("starry_night.png", img);
    //}
    //Input i;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
