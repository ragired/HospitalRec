/* Safe List
   A reader / writer class for a list of strings

*/
#ifndef _SAFE_L
#define _SAFE_L
#include <mutex>
#include <shared_mutex>
#include <syncstream>
#include <thread>
#include <list>
#include <vector>
#include <string>
#include <iostream>

class ThreadSafeList
{
public:
    ThreadSafeList() = default;
 
    // Multiple threads/readers can read the counter's value at the same time.
    std::list<std::string> get() const
    {
        std::shared_lock lock(mutex_);
        // invoke a move constructor explicitly, since mL is 
        // not a function local variable, but a member variable 
        return std::list<std::string>(std::move(mL));
        // Due to move constructor, return by value is more efficient
    }

    void display(int id) const
    {
        
      
        int nIteration = 0;
         
        while(nIteration<5)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::shared_lock lock(mutex_);
            std::cout<<"\n list contents display from ID "<<id << "iteration"<< nIteration <<"\n";
           for(auto it=mL.begin(); it!=mL.end();it++) 
           {
           
              std::cout<<" "<<*it;
           }
           lock.unlock();
           nIteration++;
        }
    }
 
    // Only one thread/writer can append to the list
    void emplace(std::string newString)
    {
        // Note: std::lock_guard or atomic<int> can be used instead
        // I prefer unique_lock or shared_lock or scoped_lock 
        // the latter allows multiple mutexes, but cant be passed as param
        // to conditions
        // a condition can be a check, a lock will be acquired
        // only if the condition occurs, for example SPI data recvd
        std::unique_lock lock(mutex_);
        mL.emplace_back(newString); // emplace is better htan push, since it creates objj in place
        // in unique_lock, we can explicitly also call unlock
        // but unlock is RAII anyway
    }
    void writer(const std::vector<std::string> &myData)
    {
        for(const std::string &gotStr:myData)
        {
            // simulate a SPI receive or so event using a sleep
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            emplace(gotStr);
        }

    }
 
    // Only one thread/writer can clear the list.
    void reset()
    {
        std::unique_lock lock(mutex_);
        mL.clear();
    }
 
private:
// member variable can also be modified inside const functions
    mutable std::shared_mutex mutex_; 
    std::list<std::string> mL;
    
    
};

#endif