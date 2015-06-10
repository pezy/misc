#include "ex15_26_Quote.h"
#include "ex15_26_Disc_quote.h
#include "ex15_26_Disc_quote.h"

using std::cout; using std::endl;

int main() {
    EX26::Quote quote_26;
    EX26::Quote quote_26_p("0-201-78345-X", 23.8);
    EX26::Quote quote_26_cp(quote_26_p);
    EX26::Quote quote_26_mv(std::move(quote_26_p));

    cout << "======ISBN======" << endl;
    cout << quote_26.isbn() << endl;
    cout << quote_26_cp.isbn() << endl;
    cout << quote_26_mv.isbn() << endl;
    cout << "================" << endl;

    EX26::Disc_quote disc_26;

    return 0;
}