#include <iostream>
using std::cout;
using std::endl;

class Solution {
   public:
    bool duplicate(int numbers[], int length, int* duplication) {
        if (numbers == nullptr || length <= 0) {
            return false;
        }

        for (size_t i = 0; i < length; ++i) {
            while (numbers[i] != i) {
                if (numbers[i] == numbers[numbers[i]]) {
                    *duplication = numbers[i];
                    return true;
                }

                std::swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplication;
    if(solution.duplicate(numbers, sizeof(numbers)/sizeof(int), &duplication) == true) {
        cout << duplication << endl;
    }
    return 0;
}