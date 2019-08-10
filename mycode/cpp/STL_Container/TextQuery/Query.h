#pragma once
#include <fstream>
#include <iostream>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include "TextQuery.h"

using std::ostream;
using std::shared_ptr;
using std::string;

class Query_base {
    friend class Query;

   protected:
    using line_no = vector<string>::size_type;
    virtual ~Query_base() = default;

   private:
    // eval返回与当前Query匹配的QueryResult
    virtual QueryResult eval(const TextQuery&) const = 0;
    // rep表示查询的一个string
    virtual string rep() const = 0;
};

class Query {
    friend Query operator~(const Query&);
    friend Query operator&(const Query& lhs, const Query& rhs);
    friend Query operator|(const Query& lhs, const Query& rhs);

   public:
    Query(const string&);  //构建一个新的WordQuery对象
    //接口函数，调用对应的Query_base操作
    QueryResult eval(const TextQuery& t) const { return _pQuerybase->eval(t); }

    string rep() const { return _pQuerybase->rep(); }

   private:
    Query(shared_ptr<Query_base> query) : _pQuerybase(query) {}
    shared_ptr<Query_base> _pQuerybase;
};

ostream& operator<<(ostream& os, const Query& query) {
    // quert通过它的query_base
    return os << query.rep();
}

class WordQuery : public Query_base {
    friend class Query;

   private:
    WordQuery(const string& s) : _query_word(s) {}
    QueryResult eval(const TextQuery& t) const { return t.query(_query_word); }

    string rep() const { return _query_word; }

   private:
    string _query_word;
};

inline Query::Query(const string& s) : _pQuerybase(new WordQuery(s)) {}

class NotQuery : public Query_base {
    friend Query operator~(const Query&);

   private:
    NotQuery(const Query& q) : _query(q) {}
    string rep() const { return "~(" + _query.rep() + ")"; }

    QueryResult eval(const TextQuery&) const;

   private:
    Query _query;
};

inline Query operator~(const Query& operand) {
    shared_ptr<Query_base> tmp(new NotQuery(operand));
    return Query(tmp);
}

class BinaryQuery : public Query_base {
   protected:
    BinaryQuery(const Query& l, const Query& r, string s)
        : _lhs(l), _rhs(r), _opSym(s) {}

    string rep() const {
        return "(" + _lhs.rep() + " " + _opSym + " " + _rhs.rep() + ")";
    }

   protected:
    Query _lhs, _rhs;
    string _opSym;
};

class AndQuery : public BinaryQuery {
private:
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& lhs, const Query& rhs) : BinaryQuery(lhs, rhs, "&"){};
    QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query& lhs, const Query& rhs) {
    shared_ptr<Query_base> tmp(new AndQuery(lhs, rhs));
    return Query(tmp);
}

class OrQuery : public BinaryQuery {
private:
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& lhs, const Query& rhs) : BinaryQuery(lhs, rhs, "|"){};
    QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query& lhs, const Query& rhs) {
    shared_ptr<Query_base> tmp(new OrQuery(lhs, rhs));
    return Query(tmp);
}