#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。

class Solution {
   public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;

        int root = sequence.back();
        //二叉搜索树中左子树的节点小于根节点
        auto it = sequence.begin();
        for (; it != sequence.end() - 1; ++it) {
            if (*it > root) break;
        }
        //二叉搜索树中左子树的节点小于根节点
        auto it2 = it;
        for (; it2 != sequence.end() - 1; ++it2) {
            if (*it2 < root) return false;
        }

        bool left = true;
        if (it > sequence.begin()) {
            left = VerifySquenceOfBST(vector<int>(sequence.begin(), it));
        }

        bool right = true;
        if (it2 != it) {
            right = VerifySquenceOfBST(vector<int>(it, it2));
        }

        return left && right;
    }
};

// ====================测试代码====================
void Test(const char* testName, vector<int>& sequence, bool expected) {
    Solution solution;
    if (testName != nullptr) printf("%s begins: ", testName);

    if (solution.VerifySquenceOfBST(sequence) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1() {
    vector<int> data{4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2() {
    vector<int> data{4, 6, 7, 5};
    Test("Test2", data, true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3() {
    vector<int> data{1, 2, 3, 4, 5};
    Test("Test3", data, true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4() {
    vector<int> data{5, 4, 3, 2, 1};
    Test("Test4", data, true);
}

// 树中只有1个结点
void Test5() {
    vector<int> data{5};
    Test("Test5", data, true);
}

void Test6() {
    vector<int> data{7, 4, 6, 5};
    Test("Test6", data, false);
}

void Test7() {
    vector<int> data{4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, false);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}