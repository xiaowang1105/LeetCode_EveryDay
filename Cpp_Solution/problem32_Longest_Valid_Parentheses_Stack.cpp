/*************************************************************************
	> File Name: problem32_Longest_Valid_Parentheses_Stack.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Mon 16 Jul 2018 11:02:33 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        stack <int> PaStack;
        PaStack.push(-1);

        for (int i = 0; i <  s.length(); i++) {
            if (s[i] == '(') {
                PaStack.push(i);
            }
            else {
                PaStack.pop();
                if (PaStack.empty()) {
                    PaStack.push(i);
                }
                else {
                    maxlen = max(maxlen, i - PaStack.top());
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
