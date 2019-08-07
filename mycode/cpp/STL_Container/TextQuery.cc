#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <set>
using std::set;
using std::map;
using std::unordered_map;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::istringstream;
using std::make_pair;

class TextQuery {
public:
    void readFile(const char* filename) {
        ifstream ifs(filename);
        if(!ifs){
            cout<<"ifstream open file error"<<endl;
            return ;
        }   
        string line;
        string word;
        int i = 1;
        while(getline(ifs, line)) {
            _lines[i] = line;
            istringstream iss(line);
            while(!iss.eof()) {
                iss >> word;
                _word2Line[word].insert(i);
                ++_dict[word];
            }
            ++i;
        }
    }

    void query(const string & word) {
        auto it = _dict.find(word);
        if(it != _dict.end()) {
            cout << word << " occurs " << _dict[word] << " times" << endl;
            print(_word2Line[word]);
        } else {
            cout << word << " not found" << endl;
        }
    }
private:
    template <class Container>
        void print(const Container& c) {
            typename Container::const_iterator cit = c.begin();
            while(cit != c.end()) {
                cout << "(line " << *cit << ")" << _lines[*cit] << endl;
                cit++;
            }
        }
    unordered_map<int,string> _lines;
    map<string, set<int> > _word2Line;
    map<string, int> _dict;
};

int main(int argc, char *argv[]) {
    string queryWord;
    cout << "please input query word:";
    cin >> queryWord;
    TextQuery tq;
    tq.readFile("china_daily.txt");
    tq.query(queryWord);            
    return 0;
}
