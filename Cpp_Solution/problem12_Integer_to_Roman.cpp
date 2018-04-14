/*************************************************************************
	> File Name: problem12_Integer_to_Roman.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Apr 2018 02:15:10 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};

int main() {
    int num = 199;
    Solution solu;
    string ans = solu.intToRoman(num);
    cout << "output is: " << ans << endl;
}
