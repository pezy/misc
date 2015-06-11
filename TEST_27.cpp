//
// Created by pezy on 6/11/2015.
//

#include "ex15_27_Bulk_quote.h"

int main()
{
    EX27::Bulk_quote bulk_quote_15("0-201-82470-1", 50, 5, .19);
    EX03::print_total(std::cout, bulk_quote_15, 6);
    return 0;
}
