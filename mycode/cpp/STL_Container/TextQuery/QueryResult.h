#pragma once
#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <vector>

using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

class QueryResult {
    friend ostream& print(ostream&, const QueryResult&);

   public:
    using line_no = vector<string>::size_type;
    using line_it = set<line_no>::const_iterator;
    QueryResult(string s, shared_ptr<set<line_no>> p,
                shared_ptr<vector<string>> f)
        : _queryWord(s), _lines(p), _file(f){};

    set<line_no>::size_type size() const { return _lines->size(); }

    line_it begin() const { return _lines->cbegin(); }

    line_it end() const { return _lines->cend(); }

    shared_ptr<vector<string>> getFile() { return _file; }

   private:
    string _queryWord;
    shared_ptr<set<line_no>> _lines;
    shared_ptr<vector<string>> _file;
};

ostream& print(ostream&, const QueryResult&);

inline string make_plural(size_t ctr, const string& word,
                          const string& ending) {
    return (ctr > 1) ? word + ending : word;
}