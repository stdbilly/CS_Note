#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    double Power(double base, int exponent) {
        if (equal(base, 0.0) && exponent < 0) return 0.0;

        unsigned int absExponent = (unsigned int)exponent;
        if (exponent < 0) {
            absExponent = (unsigned int)(-exponent);
        }
        double result = powWithUnsignedExponent(base, absExponent);
        if (exponent < 0) {
            result = 1.0 / result;
        }
        return result;
    }

   private:
    double powWithUnsignedExponent(double base, unsigned int exponent) {
        if (exponent == 0) {
            return 1;
        }
        if (exponent == 1) {
            return base;
        }

        double result = powWithUnsignedExponent(base, exponent >> 1);
        result *= result;
        if (exponent & 1) {
            result *= base;
        }
        return result;
    }

    bool equal(int num1, int num2) {
        if (num1 - num2 > -0.0000001 && num1 - num2 < 0.0000001) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    cout << solution.Power(-2, 3) << endl;
    return 0;
}