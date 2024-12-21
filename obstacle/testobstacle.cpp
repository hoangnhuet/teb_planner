#include"obstacle.h"
#include <iostream>
int main()
{
    using namespace teb_local_planner;
    int k = 0;

    // Create a PolygonObstacle with some vertices
    Point2dContainer vertices;
    vertices.push_back(Eigen::Vector2d(1.0, 1.0));
    vertices.push_back(Eigen::Vector2d(5.0, 1.0));
    vertices.push_back(Eigen::Vector2d(5.0, 3.0));
    vertices.push_back(Eigen::Vector2d(3.0, 4.0));
    vertices.push_back(Eigen::Vector2d(1.0, 3.0));

    PolygonObstacle polygon(vertices);

    // finalize polygon to compute centroid
    polygon.finalizePolygon();

    // Get the centroid
    const Eigen::Vector2d& centroid = polygon.getCentroid();
    std::cout << "Centroid of polygon: (" << centroid.x() << ", " << centroid.y() << ")\n";

    // Create an empty map (image) to visualize
    int width = 800;
    int height = 600;
    cv::Mat map = cv::Mat::zeros(height, width, CV_8UC3);
    map.setTo(cv::Scalar(255, 255, 255)); // white background

    // Visualization parameters
    double gain_x = 50.0; 
    double gain_y = 50.0;
    double map_height = 10.0; // world units in height direction

    cv::Scalar color(0,0,255); // red color (BGR)
    polygon.visualize(map, color, gain_x, gain_y, map_height);

    // Optionally draw centroid
    {
        Point2DPixel c_pixel(centroid.x(), centroid.y(), gain_x, gain_y, map_height);
        cv::circle(map, cv::Point(c_pixel.x, c_pixel.y), 4, cv::Scalar(0,255,0), -1); // green circle at centroid
    }

    // show the map in a window
    cv::imshow("PolygonObstacle Test", map);
    cv::waitKey(0);

    return 0;
}