/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 https://github.com/pezy/Cpp-Primer



If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

//
// Created by pezy on 6/15/2015.
//

#ifndef CP5_QUERY_H
#define CP5_QUERY_H

#include "ex12_27_30.h"

class Query;

// abstract base class
// Because we don't intend users, or the derived classes, to use Query_base directly,
// Query_base has no public members.
class Query_base {
    friend class Query;

protected:
    using line_no = TextQuery::LineNo;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const string&);
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    string rep() const { return q->rep(); }

private:
    Query(shared_ptr<Query_base> query) : q(query) {}
    shared_ptr<Query_base> q;
};


#endif //CP5_QUERY_H
