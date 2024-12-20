#include <Eigen/Core>
#include <Eigen/StdVector>
#include <Eigen/Geometry>
#include<iostream>

int main()
{
    Eigen::Vector2d start(1,1);
    Eigen::Vector2d end(3,3);
    Eigen::Vector2d point(1,2);
    Eigen::Vector2d a = end-start; // not normalized!  a=y-x
    Eigen::Vector2d b = point-start; // b=m-x
    double t = a.dot(b) / a.dot(a);
    std::cout<<t<<std::endl;
    Eigen::Vector2d res = start + t * a;
    std::cout<<res<<std::endl;
    std::cout<<res.norm()<<std::endl;


}