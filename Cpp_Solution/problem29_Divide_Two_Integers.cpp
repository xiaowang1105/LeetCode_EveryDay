/*************************************************************************
	> File Name: problem29_Divide_Two_Integers.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Sat 05 May 2018 08:20:01 PM CST
 ************************************************************************/

#include<iostream>
#include<limits>
#include<cstdint>
using namespace std;

class Solution {
    public:
    int divide(int dividend, int divisor){
        const bool negative = (((dividend ^ divisor) >> 31) & 0x1) == 1;
        unsigned int quotient = 0;

    for (unsigned int a = dividend < 0 ? -dividend : dividend, b = divisor < 0 ? -divisor : divisor, k; a >= b; a -= b << k)
        {
            for (k = 0; a >= b << k && b << k <= (0x80000000 >> 1); ++k);
            quotient |= 1 << (a < b << k ? --k : k);
        }
        return negative ? -quotient : quotient > INT_MAX ? INT_MAX : quotient;
    }

};

int main() {
    int dividend = 100;
    int divisor = 10;
    Solution solu;
    int out = solu.divide(100, 10);
    cout << out << endl;
}
