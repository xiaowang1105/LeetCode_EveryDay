/*************************************************************************
	> File Name: problem32_Longest_Valid_Parentheses_Brute_Force.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Mon 16 Jul 2018 10:37:39 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> PaStack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                PaStack.push('(');
            }
            else if (s[i] == ')'){
                if (!PaStack.empty() && PaStack.top() == '(') {
                    PaStack.pop();
                }
            else return false;
            }
        }
        return PaStack.empty();
    }

    int longestValidParentheses(string s) {
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 2; i + j < s.size(); j += 2 ) {
                if (isValid(s.substr(i, j))) {
                    maxlen = max(maxlen, j);
                }
            }
        }
        return maxlen;
    }
};


int main() {
    string s = "(()))";
    Solution solu;
    int maxlen = solu.longestValidParentheses(s);
    cout << maxlen << endl;
}
