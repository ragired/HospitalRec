/* 
HospThread.cpp
Sample program to demonstrate C++ 17 threads and mutex for 
managing a critical section ( a number )
*/
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
 
int g_num = 0; // protected by g_num_mutex
std::mutex g_numMutex;
 
void slow_increment(int id) 
{
    for (auto i = 0; i < 6; ++i)
    {
        g_numMutex.lock(); 
        ++g_num;
        // note, that the mutex also syncronizes the output
        std::cout << "id: " << id << ", g_num: " << g_num << '\n';
        g_numMutex.unlock();
 
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}
 
int main()
{
    std::thread t1{slow_increment, 0};
    std::thread t2{slow_increment, 1};
    t1.join();
    t2.join();
}