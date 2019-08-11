## 迭代器的种类有哪些？他们各自的功能是什么？为什么要定义这么多种类？

|      | 随机访问迭代器（RandomAccessIterator） | 双向迭代器（BidirectionalIterator） | 前向迭代器（ForwardIterator） | 输出迭代器（OutputIterator） | 输入迭代器（InputIterator） |
| ---- | -------------------------------------- | ----------------------------------- | ----------------------------- | ---------------------------- | --------------------------- |
| 读   | =*p                                    | =*p                                 | =*p                           |                              | =*p                         |
| 访问 | ->   []                                | ->                                  | ->                            |                              | ->                          |
| 写   | *p=                                    | *p=                                 | *p=                           | *p=                          |                             |
| 迭代 | ++   --   +  -    +=   -=              | ++   --                             | ++                            | ++                           | ++                          |
| 比较 | ==  !=  >  <   >=   <=                 | ==  !=                              | ==    !=                      |                              | ==    !=                    |

不同的算法要求的迭代器类型不同，之所以定义了5种迭代器，是为了使用“最合适”的工具，编写算法时在满足要求的基础上尽可能地使用功能少的迭代器，减少迭代器引入的副作用，假设要编写一个查找函数find()，只要能读取容器中的元素即可，最理想的方案是使用输入迭代器，这样，有效防止了在find()函数内对元素的修改，真正“物尽其用”。

## 什么是适配器模式？STL中有哪些适配器？

适配器模式(Adapter Pattern) ：将一个接口转换成客户希望的另一个接口，适配器模式使接口不兼容的那些类可以一起工作，其别名为包装器(Wrapper)。适配器模式既可以作为类结构型模式，也可以作为对象结构型模式。

stack：底层实现采用deque

queue：底层实现采用deque

priority_queue：底层实现采用vector

## Leetcode 20 Valid Parentheses 

```C++
#include <iostream>
#include <stack>
#include <string>
using std::cout;
using std::endl;
using std::stack;
using std::string;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> stk;
        for (const char c : s) {
            switch (c) {
                case '(':
                    stk.push(')');
                    break;
                case '{':
                    stk.push('}');
                    break;
                case '[':
                    stk.push(']');
                    break;
                default:
                    if (stk.size() == 0 || c != stk.top()) {
                        return false;
                    } else {
                        stk.pop();
                    }
            }
        }
        return stk.empty();
    }
};

int main() {
    Solution solution;
    string s("()[]{}");
    cout << solution.isValid(s) << endl;
    return 0;
}
```

#### 2. Leetcode 127 Word Ladder

```C++
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::swap;
using std::unordered_set;
using std::vector;

// 双向广度优先搜索(Bidirectional BFS)
// 分别从begWord和endWord进行搜索，如果结果在对方的集合里出现，则找到解
class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        int len = beginWord.length();
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        int step = 0;
        while (!q1.empty() && !q2.empty()) {
            ++step;
            //总是扩展最小的集合
            if (q1.size() > q2.size()) {
                swap(q1, q2);
            }

            unordered_set<string> q;

            for (string w : q1) {
                for (int i = 0; i < len; i++) {
                    char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        if (q2.count(w)) return step + 1;
                        if (!dict.count(w)) continue;
                        dict.erase(w); //如果在字典中将其删除
                        q.insert(w);
                    }
                    w[i] = ch; //将取出的单词还原
                }
            }
            swap(q, q1);//更新q1
        }
        return 0;
    }
};

int main() {
    Solution solution;
    string beginWord("hit");
    string endWord("cog");
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    int ret = solution.ladderLength(beginWord, endWord, wordList);
    cout << ret << endl;
    return 0;
}
```
