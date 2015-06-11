#include "ex15_26_Quote.h"
#include "ex15_26_Bulk_quote.h"

using std::cout; using std::endl;

int main() {
    EX26::Quote quote_26;
    EX26::Quote quote_26_p("0-201-78345-X", 23.8);
    EX26::Quote quote_26_cp(quote_26_p);
    EX26::Quote quote_26_mv(std::move(quote_26_p));

    cout << "======ISBN: price======" << endl;
    cout << quote_26.isbn() << ": " << quote_26.net_price(3) << endl;
    cout << quote_26_cp.isbn() << ": " << quote_26_cp.net_price(3) << endl;
    cout << quote_26_mv.isbn() << ": " << quote_26_mv.net_price(3) << endl;
    cout << "=======================" << endl;

    EX26::Bulk_quote bulk_26;
    EX26::Bulk_quote bulk_26_p("0-201-78345-X", 23.8, 3, 0.5);
    EX26::Bulk_quote bulk_26_cp(bulk_26_p);
    EX26::Bulk_quote bulk_26_mv(std::move(bulk_26_p));

    cout << "======ISBN: price======" << endl;
    cout << bulk_26.isbn() << ": " << bulk_26.net_price(3) << endl;
    cout << bulk_26_cp.isbn() << ": " << bulk_26_cp.net_price(3) << endl;
    cout << bulk_26_mv.isbn() << ": " << bulk_26_mv.net_price(3) << endl;
    cout << "=======================" << endl;

    return 0;
}