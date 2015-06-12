//
// Created by pezy on 6/12/2015.
// compute the total `net_price` of all the elements in the vector.
//

#include <vector>
#include <numeric>
#include <memory>

#include "ex15_27_Bulk_quote.h"

int main()
{
    std::vector<std::shared_ptr<Quote>> vecQuote;

    std::shared_ptr<Bulk_quote> spBulk0 = std::make_shared<Bulk_quote>("0-201-82470-1", 50, 5, 0.2);
    std::shared_ptr<Bulk_quote> spBulk1 = std::make_shared<Bulk_quote>("0-201-82470-1", 50, 3, 0.5);

    // total price should be:
    std::cout << "bulk_quote's total: " << spBulk0->net_price(5) + spBulk1->net_price(5) << std::endl;

    vecQuote.push_back(spBulk0);
    vecQuote.push_back(spBulk1);

    double total = std::accumulate(vecQuote.cbegin(), vecQuote.cend(),0.0, [](double ret, std::shared_ptr<Quote> sp){
        return ret += sp->net_price(5);
    });

    // total price in the vector.
    std::cout << "total in the vector: " << total << std::endl;
}