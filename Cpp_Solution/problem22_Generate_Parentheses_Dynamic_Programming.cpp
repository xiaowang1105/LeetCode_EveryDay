/*************************************************************************
	> File Name: problem22_Generate_Parentheses_Dynamic_Programming.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Fri 20 Apr 2018 04:57:55 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector< vector<string> > dp(n + 1, vector<string>());
        dp[0].push_back("");
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k < i; k++) {
                for (string left : dp[k]) {
                    for (string right : dp[i - 1 - k]) {
                        dp[i].push_back("(" + left + ")" + right);
                    }
                }
            }
        }
    }
};

int main() {
    int n = 3;
    Solution solu;
    vector<string> res;
    res = solu.generateParenthesis(n);
    cout << res[0] << endl;
}
