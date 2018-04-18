/*************************************************************************
	> File Name: problem20_Valid_Parentheses.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Wed 18 Apr 2018 08:38:43 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char &c : s) {
            switch(c) {
                case '(':
                case '{':
                case '[': paren.push(c); break;
                case ')': if (paren.empty()) return false; else paren.pop(); break;
                case '}': if (paren.empty()) return false; else paren.pop(); break;
                case ']': if (paren.empty()) return false; else paren.pop(); break;
            }
        }
        return paren.empty();
    }
};

int main() {
    string s = "{}[]";
    Solution solu;
    bool ans = solu.isValid(s);
    cout << "output: " << ans << endl;
}
