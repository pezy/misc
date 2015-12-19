#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

#include "ex16_02_compare.h"
#include "ex16_04_find.h"
#include "ex16_05_print_array.h"
#include "ex16_06_begin_end.h"
#include "ex16_07_sizeof_array.h"

#include "Blob.h"

int main()
{
    // 16.02
    std::cout << compare(3, 5) << std::endl;
    std::cout << compare(std::vector<int>{ 1, 4, 7 }, { 2, 3, 4 }) << std::endl;
    std::cout << compare("cpp", "pezy") << std::endl;

    // 16.03
    //Sales_data cpp("cpp", 5, 23.5);
    //Sales_data boost("boost", 3, 11.8);
    //cout << compare(cpp, boost) << std::endl;

    // 16.04
    std::vector<int> ivec{ 1,3,5,7,9 };
    std::list<std::string> slist{ "one", "three", "five", "seven", "nine" };
    auto found_ivec = Find(ivec.cbegin(), ivec.cend(), 5);
    if (found_ivec != ivec.end())
    {
        std::cout << "found " << *found_ivec << std::endl;
    }

    auto found_slist = Find(slist.cbegin(), slist.cend(), "five");
    if (found_slist != slist.end())
    {
        std::cout << "found " << *found_slist << std::endl;
    }

    // 16.05
    int test_array[] = { 2, 8, 4, 6 };
    print_array(test_array);
    print_array("hello, cppprimer");

    // 16.06
    std::sort(Begin(test_array), End(test_array));
    print_array(test_array);

    // 16.07
    std::cout << SizeOfArray(test_array) << std::endl;
    std::cout << SizeOfArray("cppprimer") << std::endl;

    Blob<std::string> articles = { "a", "an", "the" };
    std::cout << articles.back() << std::endl;

    for (auto iter = articles.begin(); iter != articles.end(); ++iter)
    {
        std::cout << *iter << std::endl;
    }
}