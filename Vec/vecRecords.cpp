/*  
   vecRecords.cpp

   Description 
   Main File
   Program to demonstrate STL Vector and basic algorithms
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// a function, which can be passed as a function pointer to STL Algorithms
/*bool myPred ( const string &s)
{
    if(s[0]=='C' || s[0]=='D')
    return true;
    else
    return false;
}*/


// A functor, which is a class with overloaded ()
// Advantage : can also store a state, unlike a function
class CheckFirstChar
{
  private :
     char ch;
  public:
  CheckFirstChar(char c) : ch{c} {};
  bool operator()(const string &s)
  {
    if(s[0]==ch)
    return true;
    else
    return false;
  }
};

/*
Function to print 
*/
template <typename FUN>
void printFrom(const vector <string> &vec,  FUN lambdaFun )
{
   // auto stIt = std::find_if(vec.begin(), vec.end(), myPred);
  
   // auto stIt = std::find_if(vec.begin(), vec.end(), CheckFirstChar(searchC));
   
   auto stIt = std::find_if(vec.begin(), vec.end(), lambdaFun);
    if(stIt != vec.end())
    {
        while(stIt!=vec.end())
        {
            cout << "The found after C "<<  " is " << *stIt << "\n";
            stIt++;
        }
    }
}

int main()
{

    vector <string> myVec;
    myVec.push_back("Peter");
    myVec.push_back("Mary");
    myVec.push_back("Chris");
    myVec.push_back("Ragu");
    myVec.push_back("Tom");
    myVec.push_back("Claudia");
    myVec.push_back("Simon");
    myVec.push_back("Praveen");
    myVec.push_back("Bella");
    myVec.push_back("Claus");
    for (auto it=myVec.begin(); it!=myVec.end();it++)
    {
        cout << "The original list " << *it << "\n";
    }
    char cSearch = 'C'; 
    auto lambFun = [cSearch](const string &s){return s[0]==cSearch;};
    printFrom(myVec, lambFun); 
}