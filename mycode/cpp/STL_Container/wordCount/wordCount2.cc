#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <map>
#include <unordered_map>
using std::cout;
using std::endl;
using std::map;
using std::unordered_map;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;

void test1() {
    auto start = std::chrono::system_clock::now();
    ifstream ifs("The_Holy_Bible.txt");
    if(!ifs){
        cout<<"ifstream open file error"<<endl;
    }
    string line;
    string word;
    //map<string, int> wordInfo;
    unordered_map<string, int> wordInfo;
    while(getline(ifs,line)){
        istringstream iss(line);
        while(!iss.eof()){
            iss>>word;
            if(!isNum(word)){
                ++wordInfo[word];
            }
        }
    }

    ofstream ofs("dict.txt");
    if(!ofs){
        cout<<"ofstream open file error"<<endl;
    }
    for(auto & info:wordInfo){
        ofs<<info.first<<" "<<info.second<<"\n";
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "use time: " << elapsed_seconds.count() << "s\n";
}

int main() {
    test1();
    return 0;
}

