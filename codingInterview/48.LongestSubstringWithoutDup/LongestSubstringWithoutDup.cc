#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = -1;
        int freq[256] = {0};
        int res = 0;
        while (left < s.size())
        {
            if(right + 1 < s.size() && freq[s[right+1]] == 0) {
                ++right;
                ++freq[s[right]];
            } else {
                //右边界存在相同的字符,缩小左边界;
                --freq[s[left]];
                ++left;
            }

            res = std::max(res, right - left + 1);
        }
        return res;
    }
};

int main(){
   Solution solution;
   string s("abcabcbb");
   cout << solution.lengthOfLongestSubstring(s) << endl;
   return 0;
}