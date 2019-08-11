## 词频统计的作业再用map/unordered_map容器去实现一次，体验一下使用vector/map/unordered_map时程序执行的速度 

```C++
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
```

## 文本查询作业

该程序将读取用户指定的任意文本文件【当前目录下的china_daily.txt】，
然后允许用户从该文件中查找单词。查询的结果是该单词出现的次数，并列
出每次出现所在的行。如果某单词在同一行中多次出现，程序将只显示该行
一次。行号按升序显示。

要求：
a. 它必须允许用户指明要处理的文件名字。

b. 程序将存储该文件的内容，以便输出每个单词所在的原始行。
     vector<string> lines;//O(1)  完美hash
  或 map<int, string> lines;//O(logN)
  或 unorderedmap<int,string> lines;//O(1) 
     
c. 它必须将每一行分解为各个单词，并记录每个单词所在的所有行。 
	 在输出行号时，应保证以升序输出，并且不重复。 

```
   map<string, set<int> > word2Line;
   map<string, int> dict;
```

d. 对特定单词的查询将返回出现该单词的所有行的行号。

e. 输出某单词所在的行文本时，程序必须能根据给定的行号从输入
	 文件中获取相应的行。
	 
示例：
		使用提供的文件内容，然后查找单词 "element"。输出的前几行为：

---------------------------------------------
​	 	element occurs 125 times.
​			(line 62) element with a given key.
​			(line 64) second element with the same key.
​			(line 153) element |==| operator.
​			(line 250) the element type.
​			(line 398) corresponding element.

---------------------------------------------

​	  程序接口[可选]:
​		class TextQuery
​		{
​		public:
​		    void readFile(const string filename);
​		    void query(const string & word);
​		private:
​					//......
​		};
​		
​		//程序测试用例
​		int main(int argc, char *argv[])
​		{
​		   string  queryWord("hello");
​		   
​		   TextQuery tq;
​		   tq.readFile("test.dat");
​		   tq.query(queryWord);			   
​		   return 0;
​		}     			   			    			

```C++
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
```

![1565093429476](C:%5CUsers%5Cwhb22%5CAppData%5CRoaming%5CTypora%5Ctypora-user-images%5C1565093429476.png)

## Leetcode 146 LRUCache

```C++
#include <iostream>
#include <list>
#include <utility>
#include <unordered_map>
using std::unordered_map;
using std::list;
using std::pair;
using std::cout;
using std::endl;

class LRUCache {
public:
    LRUCache(int capacity) :_capacity(capacity){}

    int get(int key) {
        if(_cache.find(key) == _cache.end()) {
            return -1;
        } else {
            _used.splice(_used.begin(), _used, _cache[key]);
            _cache[key] = _used.begin();
            return _used.begin()->second;
        }
    }

    void put(int key, int value) {
        if(_cache.find(key) != _cache.end()) {
            _used.splice(_used.begin(), _used, _cache[key]);
            _used.begin()->second = value;
            _cache[key] = _used.begin();
        } else {
            if(_cache.size() == _capacity) {
                int deleteKey = _used.back().first;
                _cache.erase(deleteKey);
                _used.pop_back();
            }
            _used.push_front({key, value});
            _cache[key] = _used.begin();
        }

    }
private:
    typedef list<pair<int,int> > pairList;
    pairList _used;
    int _capacity;
    unordered_map<int, pairList::iterator> _cache;
};

void test1() {
    LRUCache* cache = new LRUCache( 2 /* capacity */  );

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;       // returns 1
    cache->put(3, 3);    // evicts key 2
    cout << cache->get(2) << endl;       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    cout << cache->get(1) << endl;       // returns -1 (not found)
    cout << cache->get(3) << endl;       // returns -1 (not found)
    cout << cache->get(4) << endl;       // returns -1 (not found)
}

int main() {
    test1();
    return 0;
}
```

## 实现一个堆排序算法

可选择使用模板或非模板的实现：

使用模板的框架如下：
 template <typename T, typename Compare = std::less<T> >
 class HeapSort
 {
 public:
     void heapAdjust();
     void sort();
 private:
     //...
 };

```C++
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::swap;

template <typename T, typename Compare = std::less<T> >
class HeapSort {
public:
    void heapAdjust(vector<T>& arr, int pos, int arrLen) {
        while(true) {
            int maxPos = pos;
            if(pos * 2 + 1 < arrLen && compare(arr[pos], arr[pos * 2 + 1]))
                maxPos = pos * 2 + 1;
            if(pos * 2 + 2 < arrLen && compare(arr[maxPos], arr[pos * 2 + 2]))
                maxPos = pos * 2 + 2;

            if(maxPos == pos) 
                break;
            swap(arr[pos], arr[maxPos]);
            pos = maxPos;
        }
    }

    bool compare(const T& lhs, const T& rhs, Compare com = Compare()) {
        return com(lhs,rhs);
    }

    void sort(vector<T>& arr) {
        for(int i = arr.size()/2 - 1; i >= 0; --i) {
            heapAdjust(arr, i, arr.size());
        }

        int k = arr.size();
        while(k > 0) {
            swap(arr[0], arr[k-1]);
            --k;
            heapAdjust(arr, 0, k);
        }
    }
};

void test1() {
    vector<int> nums({3,6,2,5,12,4,8,15,11});
    //HeapSort<int> heap;
    HeapSort<int,std::greater<int> > heap;
    heap.sort(nums);
    for(int& i:nums) {
        cout << i << " " ;
    }
    cout << endl;
}

int main() {
    test1();
    return 0;
}
```
