#include "QueryResult.h"
#include "TextQuery.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    ifstream infile("china_daily.txt");
    TextQuery tq(infile);
    string word;
    cout << "please input query word: ";
    cin >> word;
    print(cout, tq.query(word)) << endl;
    return 0;
}