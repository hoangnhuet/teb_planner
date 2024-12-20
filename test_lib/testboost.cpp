#include<chrono>
#include <boost/thread.hpp>
#include <iostream>
void threadFunc1()
{
    while(1)
    {
    std::cout<<"Thread1"<<std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(500));
    }
}
void threadFunc2()
{
    while(1)
    {
    std::cout<<"Thread2"<<std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(500));
    }
}
int main()
{
    boost::thread Thread1(threadFunc1);
    boost::thread Thread2(threadFunc2);
    Thread1.join();
    Thread2.join();

}