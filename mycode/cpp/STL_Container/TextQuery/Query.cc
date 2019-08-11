#pragma once
#include "Query.h"
#include <algorithm>
#include <iterator>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "TextQuery.h"

using namespace std;

QueryResult OrQuery::eval(const TextQuery& text) const {
    //通过query的_lhs和_rhs进行的虚调用
    auto right = _rhs.eval(text), left = _lhs.eval(text);
    //将左侧运算对象的行号拷贝到结果set中
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    //插入右侧运算对象所得的行号
    ret_lines->insert(right.begin(), right.end());
    //返回一个新的QueryResult，表示_lhs和_rhs的并集
    return QueryResult(rep(), ret_lines, left.getFile());
}

QueryResult AndQuery::eval(const TextQuery& text) const {
    auto right = _rhs.eval(text), left = _lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    //将两个范围的交集写入ret_lines指向的set中
    set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                     inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.getFile());
}

QueryResult NotQuery::eval(const TextQuery& text) const {
    auto result = _query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();

    auto sz = result.getFile()->size();
    //遍历文件的所有行，将不在result中的行添加到ret_lines
    for (size_t i = 0; i < sz; ++i) {
        if (beg == end || *beg == i) {
            ret_lines->insert(i);
        } else if (beg != end) {
            ++beg;
        }
    }
    return QueryResult(rep(), ret_lines, result.getFile());
}