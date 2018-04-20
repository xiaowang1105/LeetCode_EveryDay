/*************************************************************************
	> File Name: problem22_Generate_Parentheses.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Fri 20 Apr 2018 04:15:16 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string local = "";
        int num_left = 0, num_right = 0;
        generate_help(res, local, n, num_left, num_right);
        return res;
    }
        
    void generate_help(vector<string> &res, string local, int n, int num_left, int num_right) {
        if (num_left == n && num_right == n)
            // cout << "left " << num_left << " ; right " << num_right << "; local " << local << endl;
            res.push_back(local);
        else if (num_left == n)
            local += ')', num_right++, generate_help(res, local, n, num_left, num_right);
        else if (num_left == num_right) 
            local += '(', num_left++, generate_help(res, local, n, num_left, num_right);
        else if (num_left > num_right) {
            local += '(', num_left++, generate_help(res, local, n, num_left, num_right);
            local.pop_back(), num_left--;
            local += ')', num_right++, generate_help(res, local, n, num_left, num_right);
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
