/*************************************************************************
	> File Name: problem10_Regular_Expression_Matching.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Apr 2018 04:07:01 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector< vector<bool> > dp(p.size() + 1, vector<bool>(s.size() + 1, false));

        dp[0][0] = true;
        for (int i = 1; i <= p.size(); i++)
            dp[i][0] = (p[i - 1] == '*') ? dp[max(i - 2, 0)][0] : false;

        for (int i = 0; i < p.size(); i++){
            for (int j = 0; j < s.size(); j++){
                if (s[j] == p[j] || p[i] == '.')
                    dp[i + 1][j + 1] = dp[i][j];
                else if (p[i] == '*')
                    dp[i + 1][j + 1] = dp[max(i - 1, 0)][j + 1] || dp[i + 1][j] && (s[j] == p[i - 1] || p[i - 1] == '.');
            }
        }
        return dp[p.size()][s.size()];
    }
};

int main() {
    string s = "ab";
    string p = ".*c";
    Solution solu;
    bool is_match = solu.isMatch(s, p);
    cout << "result is: " << is_match << endl;
}
