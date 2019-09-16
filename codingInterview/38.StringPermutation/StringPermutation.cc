#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
   public:
    vector<string> Permutation(string str) {
        if (str.empty()) return res;

        used = vector<bool>(str.size(), false);
        std::sort(str.begin(), str.end());  //可能存在重复

        string permutation;
        generatePermutation(str, 0, permutation);
        return res;
    }

   private:
    void generatePermutation(string& str, int index, string& permutation) {
        if (index == str.size()) {
            res.push_back(permutation);
            return;
        }

        for (int i = 0; i < str.size(); ++i) {
            if (used[i]) {
                continue;
            }

            if (i > 0 && str[i] == str[i - 1] && !used[i - 1]) {
                continue;
            }

            permutation.push_back(str[i]);
            used[i] = true;

            generatePermutation(str, index + 1, permutation);

            permutation.pop_back();
            used[i] = false;
        }
        return;
    }

   private:
    vector<string> res;
    vector<bool> used;
};

template <class Container>
void display(const Container& c) {
    typename Container::const_iterator cit = c.begin();
    while (cit != c.end()) {
        cout << *cit << " ";
        ++cit;
    }
    cout << endl;
}

int main() {
    Solution solution;
    string str("abc");
    string str1("aaa");
    vector<string> res = solution.Permutation(str1);
    display(res);
    return 0;
}