#include"obstacle.h"
#include <iostream>
// int main()
// {
//     using namespace teb_local_planner;
//     int k = 0;

//     // Create a PolygonObstacle with some vertices
//     Point2dContainer vertices;
//     vertices.push_back(Eigen::Vector2d(100.0, 100.0));
//     vertices.push_back(Eigen::Vector2d(500.0, 100.0));
//     vertices.push_back(Eigen::Vector2d(500.0, 300.0));
//     vertices.push_back(Eigen::Vector2d(300.0, 400.0));
//     vertices.push_back(Eigen::Vector2d(100.0, 300.0));

//     PolygonObstacle polygon(vertices);

//     // finalize polygon to compute centroid
//     polygon.finalizePolygon();

//     // Get the centroid
//     const Eigen::Vector2d& centroid = polygon.getCentroid();
//     std::cout << "Centroid of polygon: (" << centroid.x() << ", " << centroid.y() << ")\n";

//     // Create an empty map (image) to visualize
//     int width = 800;
//     int height = 600;
//     cv::Mat map = cv::Mat::zeros(height, width, CV_8UC3);
//     map.setTo(cv::Scalar(255, 255, 255)); // white background

//     // Visualization parameters
//     double gain_x = 5.0; 
//     double gain_y = 5.0;
//     double map_height = 10.0; // world units in height direction

//     cv::Scalar color(0,0,255); // red color (BGR)
//     polygon.visualize(map, color, gain_x, gain_y, map_height);

//     // Optionally draw centroid
//     {
//         Point2DPixel c_pixel(centroid.x(), centroid.y(), gain_x, gain_y, map_height);
//         cv::circle(map, cv::Point(c_pixel.x, c_pixel.y), 4, cv::Scalar(0,255,0), -1); // green circle at centroid
//     }

//     cv::imshow("PolygonObstacle Test", map);
//     cv::waitKey(0);

//     return 0;
// }
int main()
{
    using namespace teb_local_planner;
    PointObstacle point(Eigen::Vector2d(1.0, 1.0));
    CircularObstacle circle(Eigen::Vector2d(2.0, 2.0), 1.5);
    // LineObstacle line(Eigen::Vector2d(300.0, 300.0), Eigen::Vector2d(400.0, 400.0));
    int w = 800;
    int h =600; 
    cv::Mat map  = cv::Mat::zeros(h,w,CV_8UC3);
    map.setTo(cv::Scalar(0,0,255));
    double gain_x = 5.0;
    double gain_y  =5.0;
    double map_height = 400.0;
    cv::Scalar color(255,255,255);
    point.visualize(map, color,gain_x, gain_y, map_height);
    // circle.visualize(map, color, gain_x, gain_y, map_height);
    // cv::line(map, cv::Point(300,300), cv::Point(400,400), color, 2);
    cv::imshow("Vis Test", map);
    cv::waitKey(0);
    return 0;
}