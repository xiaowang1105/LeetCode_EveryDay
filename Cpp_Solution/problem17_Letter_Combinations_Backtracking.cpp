/*************************************************************************
	> File Name: problem17_Letter_Combinations_Backtracking.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Apr 2018 04:52:54 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map <char, string> num2char;
        num2char['2'] = "abc", num2char['3'] = "def", num2char['4'] = "ghi", num2char['5'] = "jkl";
        num2char['6'] = "mno", num2char['7'] = "pqrs", num2char['8'] = "tuv", num2char['9'] = "wxyz";

        vector<string> res;
        string local = "";
        int index = 0;

        backtracking(digits, num2char, local, index, res);
        return res;
    }

    void backtracking(string digits, unordered_map <char, string> num2char, string local, int index, vector<string> res) 
    {
        if (index == digits.size() && local != "") 
            res.push_back(local);
        else {
            for (int i = 0; i < num2char[digits[index]].size(); i++) {
                local += num2char[digits[index]][i];
                backtracking(digits, num2char, local, index + 1, res);
                local.pop_back();
            }
        }
    }
};

int main() {
    string digits = "23";
    Solution solu;
    solu.letterCombinations(digits);
}
