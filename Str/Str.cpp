#include <iostream>
#include "Str.h"
#include <string.h>



namespace MyCollection
{
    Str::Str() : data{nullptr}, len{0}
    {

    }

    Str::Str(char *str) 
    {
        if(nullptr != str)
        {
            char *temp = str;
            for(;*temp!=0;temp++)
            {
                len++;
            }
            //data = new char[len];
            data = make_unique<char[]>(len + 1);
            memcpy(data.get(),str,len);
        }
    }

    Str::~Str()
    {
        // destructor needs to delete the data if using C++03 stle ptr
        /*if(data != nullptr)
        {
            delete [] data;
            data = nullptr;
        }*/
       // since we are using data as a smart pointer
       // , no explicit garbage collection needed
    }

    // TODO : constructor that accepts std::string
    
    Str::Str(const Str &copy) : len{copy.len}
    {
        if(copy.len != 0)
        {
           // data = new char[copy.len]; // C++03 style using native ptrs
           data = make_unique<char[]>(copy.len + 1);
            //strcpy(data, copy.data);
            memcpy(data.get(),copy.data.get(),len);
            
            
        }
    }

    int Str::count_x(char x)
    { 
        auto retVal = 0;
        // char *temp = data; // C++ 03
        char *temp = data.get(); // C++ 17
        while(*temp)
        {
            if(*temp == x)
            {
                retVal++;
            }
            temp++;
        }  
        return retVal;

    }

    char &Str::operator[](int index)
    {
        if(index>=len)
        {
            index = len-1;
        }
        // return *(data+index);
        return *(data.get()+index);
    }
    
   // Str::operator <<()
    
}