/* 
HospThread.cpp
Sample program to demonstrate C++ 17 threads and mutex for 
managing a critical section ( a number )
*/
#include <vector>
#include <iostream>
#include "SafeList.h"
 
std::vector<std::string> g_Vector;
 
void seedData() 
{
    g_Vector.emplace_back("SysPressure 120");
    g_Vector.emplace_back("Diast Pressure 80");
    g_Vector.emplace_back("SysPressure 130");
    g_Vector.emplace_back("Diast Pressure 90");
    g_Vector.emplace_back("SysPressure 122");
    g_Vector.emplace_back("Diast Pressure 80");
    g_Vector.emplace_back("SysPressure 124");
    g_Vector.emplace_back("Diast Pressure 85");
    g_Vector.emplace_back("SysPressure 120");
    g_Vector.emplace_back("Diast Pressure 80");
    g_Vector.emplace_back("SysPressure 126");
    g_Vector.emplace_back("Diast Pressure 86");
    g_Vector.emplace_back("SysPressure 128");
    g_Vector.emplace_back("Diast Pressure 88");
    g_Vector.emplace_back("SysPressure 129");
    g_Vector.emplace_back("Diast Pressure 89");
    g_Vector.emplace_back("SysPressure 120");
    g_Vector.emplace_back("Diast Pressure 80");
    
}
 
int main()
{
    seedData();
    ThreadSafeList testL;
    std::thread t0{&ThreadSafeList::writer, &testL, g_Vector};
    std::thread t1{&ThreadSafeList::display, &testL, 0};
    std::thread t2{&ThreadSafeList::display, &testL, 1};
    t0.join();
    t1.join();
    t2.join();
}