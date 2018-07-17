/*************************************************************************
	> File Name: problem32_Longest_Valid_Parentheses_Dynamic_Programming.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Tue 17 Jul 2018 09:27:24 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string> 
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        int len = s.length();
        if (len == 0) return 0;
        vector <int> dp(len);
        for (int i = 1; i < len; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                    else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + (i -dp[i - 1] - 2 >=0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                    }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    string s = "(()))";
    Solution solu;
    int maxlen = solu.longestValidParentheses(s);
    cout << maxlen << endl;
}
