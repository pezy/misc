//
// Created by pezy on 6/12/2015.
// compute the total `net_price` of all the elements in the vector.
//

#include <vector>
#include <numeric>
#include <memory>

#include "ex15_30_Basket.h"

int main()
{
    Basket bsk;

    for (size_t i = 0; i != 10; ++i) {
        bsk.add_item(Bulk_quote("Bible", 20.5, 5, 0.2));
        bsk.add_item(Bulk_quote("CppPrimer", 30.5, 10, 0.5));
        bsk.add_item(Quote("CLRS", 40.5));
    }

    bsk.total_receipt(std::cout);
}