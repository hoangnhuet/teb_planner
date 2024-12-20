#include <Eigen/Core>
#include <Eigen/StdVector>
#include <Eigen/Geometry>

using namespace std;
int main()
{
    Eigen::Vector2d start;
    Eigen::Vector2d end;
    Eigen::Vector2d point;
    start<< 1,1;
    end << 2,2;
    point<< 1,1;
    Eigen::Vector2d a = end-start; // not normalized!  a=y-x
    Eigen::Vector2d b = point-start; // b=m-x
    double t = a.dot(b) / a.dot(a);
    cout<<t<<endl;


}