/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 https://github.com/pezy/Cpp-Primer

Disc_quote class
 1. define copy-control members to do the same job as the synthesized versions.
 2. Print function name to trace the running.

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#ifndef CP5_EX15_26_DISC_QUOTE_H
#define CP5_EX15_26_DISC_QUOTE_H

#include "ex15_26_Quote.h"

namespace EX26 {
class Disc_quote : public Quote {
public:
    Disc_quote() {
        cout << "Disc_quote Constructor" << endl;
    }

    Disc_quote(const string &b, double p, size_t q, double d) : Quote(b, p), quantity(q), discount(d) {
        cout << "Disc_quote Constructor taking four paramters" << endl;
    }

    Disc_quote(const Disc_quote& rhs) : Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) {
        cout << "Disc_quote Copy Constructor" << endl;
    }

    Disc_quote& operator=(const Disc_quote& rhs) {
        cout << "Disc_quote Copy assignment operator" << endl;
        Quote::operator=(rhs);
        quantity = rhs.quantity;
        discount = rhs.discount;
        return *this;
    }

    Disc_quote(Disc_quote &&rhs) noexcept : Quote(rhs), quantity(std::move(rhs.quantity)),
                                            discount(std::move(rhs.discount)) {
        cout << "Disc_quote Move constructor" << endl;
    }

    Disc_quote& operator=(Disc_quote &&rhs) noexcept {
        cout << "Disc_quote Move assignment operator" << endl;
        Quote::operator=(rhs);
        quantity = std::move(rhs.quantity);
        discount = std::move(rhs.discount);
        return *this;
    }

    virtual ~Disc_quote() {
        cout << "Disc_quote destructor" << endl;
    }
    virtual double net_price(size_t) const = 0;
protected:
    size_t quantity = 0;
    double discount = 0.0;
};
}

#endif //CP5_EX15_26_DISC_QUOTE_H
