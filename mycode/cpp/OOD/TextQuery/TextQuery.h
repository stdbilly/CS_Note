#pragma once
#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "QueryResult.h"

using std::map;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;
using std::ifstream;

class QueryResult;
class TextQuery {
   public:
   using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;

   private:
   shared_ptr<vector<string>> _file;
   map<string, shared_ptr<set<line_no>>> _wordMap;
};
