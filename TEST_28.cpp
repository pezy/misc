//
// Created by pezy on 6/12/2015.
// compute the total `net_price` of all the elements in the vector.
//

#include <vector>
#include <numeric>

#include "ex15_27_Bulk_quote.h"

int main()
{
    std::vector<Quote> vecQuote;

    Bulk_quote bulk0("0-201-82470-1", 50, 5, 0.2);
    Bulk_quote bulk1("0-201-82470-1", 50, 3, 0.5);

    // total price should be:
    std::cout << "bulk_quote's total: " << bulk0.net_price(5) + bulk1.net_price(5) << std::endl;

    vecQuote.push_back(bulk0);
    vecQuote.push_back(bulk1);

    double total = std::accumulate(vecQuote.cbegin(), vecQuote.cend(),0.0, [](double ret, const Quote &obj){
        return ret += obj.net_price(5);
    });

    // total price in the vector.
    std::cout << "total in the vector: " << total << std::endl;
}