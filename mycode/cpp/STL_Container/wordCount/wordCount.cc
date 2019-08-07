#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;

struct Info{
    Info(const string& s,int i=1)
        :word(s)
         ,count(i){ }
    string word;
    int count;
};

bool isNum(string s){
    istringstream iss(s);
    int i;
    if(iss>>i){
        return true;
    }
    return false;
}

void test1() {
    auto start = std::chrono::system_clock::now();
    ifstream ifs("The_Holy_Bible.txt");
    if(!ifs){
        cout<<"ifstream open file error"<<endl;
    }
    string line;
    string word;
    bool hasSame=false;
    vector<Info> wordInfo;
    while(getline(ifs,line)){
        istringstream iss(line);
        while(!iss.eof()){
            hasSame=false;
            iss>>word;
            for(auto & info:wordInfo){
                if(info.word==word){
                    info.count++;
                    hasSame=true;
                    break;
                }
            }

            if(!hasSame && !isNum(word)){
                wordInfo.push_back(Info(word));
            }
        }
    }

    ofstream ofs("dict.txt");
    if(!ofs){
        cout<<"ofstream open file error"<<endl;
    }
    for(auto & info:wordInfo){
        //cout<<info.word<<" "<<info.count<<endl;
        ofs<<info.word<<" "<<info.count<<"\n";
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "use time: " << elapsed_seconds.count() << "s\n";
}

int main() {
    test1();
    return 0;
}

