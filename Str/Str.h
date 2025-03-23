#include <memory>
#ifndef AAA
#define AAA
using namespace std;
using PrimitiveCharArrayType = std::unique_ptr<char[]>;
namespace MyCollection
{
    class Str
    {
    private:
        //char *data = nullptr;  // old C++ 03 style with pointers
        PrimitiveCharArrayType data;
        int len = 0;
    public:
        Str();
        Str(const Str &);  // Copy constructor
        Str(char *inData);  
        ~Str();
        char& operator [](int index);
        int count_x(char x);
        int length() {return len; };
        //void get();
        // set();  
    };

}
#endif