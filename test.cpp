//#include <iostream>
//
//int global = 42;
//
//int main()
//{
//    static int s = 13;
//
//    auto lamba0 = [global](){ return global; };
//    auto lamba1 = [s](){ return s; };
//
//    std::cout << lamba0() << std::endl;
//    std::cout << lamba1() << std::endl;
//}

#include "ex13_49_StrVec.h"
#include <iostream>

int main()
{
    StrVec vec;
    std::string str0{"hello"}, str1{"world"};
    vec.push_back(str0);
    vec.push_back(str1);
    for (const auto &s : vec)
        std::cout << s << std::endl;
}