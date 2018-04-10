/*************************************************************************
	> File Name: problem5_Longest_Palindromic_Substring_Dynamic_Programming.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Apr 2018 07:50:01 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s){
        int n = s.length();
        bool P[n][n];
        // store answers while doing dynamic programming
        int ans[2] = {0, 0};

        // set up base cases
        for (int j = 0; j < n; j++) P[j][j] = true;
        for (int j = 0; j < n - 1; j++){
            P[j][j + 1] = (s[j] == s[j + 1]);
            if (P[j][j + 1] && 2 > (ans[1] - ans[0] + 1)) ans[0] = j, ans[1] = j + 1;
        }

        // bottom up
        for (int i = 3; i <= n; i++){
            for (int j = 0; j < n - i + 1; j++){
                P[j][j + i - 1] = P[j + 1][j + i - 2] && (s[j] == s[j + i - 1]);
                if (P[j][j + i - 1] && i > (ans[1] - ans[0] + 1)) ans[0] = j, ans[1] = j + i - 1;
            }
        }
        return s.substr(ans[0], ans[1] - ans[0] + 1);
    }
};

int main() {
    string s = "babad";
    Solution solu;
    string ans = solu.longestPalindrome(s);
    cout << "original string is: " << s << endl;
    cout << "output sub_string is: " << ans << endl;
}


