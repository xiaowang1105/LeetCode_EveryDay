/*************************************************************************
	> File Name: problem9_Palindrome_Number.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Apr 2018 07:45:10 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x <  0 || (x != 0 && x % 10 == 0)) 
            return false;
        
        int reverse_num = 0;
        while(x > reverse_num) {
            reverse_num = reverse_num * 10 + x % 10;
            x /= 10;
        }

        return (x == reverse_num) || (x == reverse_num / 10);
    }
};

int main() {
    int x = 12321;
    Solution solu;
    bool ans = solu.isPalindrome(x);
    string res = ans ? "yes" : "no";
    cout << res << endl;
}
