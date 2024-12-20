#include <opencv2/opencv.hpp>
#include <iostream>
#include <Eigen/Core>
#include <Eigen/StdVector>
#include <Eigen/Geometry>

int main() {
    int thickness = 10;
    int radius = 100;
    Eigen::Vector2d start(100,100);
    Eigen::Vector2d end(300,300);
    Eigen::Vector2d point(100,200);
    Eigen::Vector2d a = end-start; 
    Eigen::Vector2d b = point-start;
    double t = a.dot(b) / a.dot(a);
    std::cout<<t<<std::endl;
    Eigen::Vector2d res = start + t * a;
    cv::Scalar color(0,0,255);
    cv::Mat image = cv::Mat::zeros(600, 600, CV_8UC3);
    // cv::line(image, cv::Point(start(0), start(1)), cv::Point(end(0), end(1)), color, thickness);
    // cv::circle(image, cv::Point(point(0), point(1)), radius, color, thickness);
    // cv::line(image, cv::Point(res(0), res(1)), cv::Point(point(0), point(1)), color, thickness);
    std::vector<cv::Point> polygon_points;
    polygon_points.push_back(cv::Point(start(0), start(1)));
    polygon_points.push_back(cv::Point(end(0), end(1)));
    polygon_points.push_back(cv::Point(point(0), point(1)));
    cv::fillConvexPoly(image, polygon_points, color);


    cv::imshow("Image", image);
    cv::waitKey(0);
    return 0;
}