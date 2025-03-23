#include <iostream>
#include "Str.h"

using namespace std;
using namespace MyCollection;

int main()
{
    char c[] = {'h','i','y','a',' ','b','u','d','d','d','y','\0'};
Str s(c);
cout << "The length is\n" <<s.length();
cout <<"The number of instances of d is \n" << s.count_x('d');
cout << "The character at index 3 is \n"<<s[3]; 
s[3]='z';
cout << "The character at index 3 is \n"<<s[3]; 
//cout <<"new string \n"<<s;
}