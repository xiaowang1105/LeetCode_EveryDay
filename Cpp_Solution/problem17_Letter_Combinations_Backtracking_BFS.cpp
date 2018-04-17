/*************************************************************************
	> File Name: problem17_Letter_Combinations_Backtracking_BFS.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Tue 17 Apr 2018 05:15:19 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        
        unordered_map <char, string> num2char;
        num2char['2'] = "abc", num2char['3'] = "def", num2char['4'] = "ghi", num2char['5'] = "jkl";
        num2char['6'] = "mno", num2char['7'] = "pqrs", num2char['8'] = "tuv", num2char['9'] = "wxyz";
        
        int index = 0;
        vector <string> res, temp;
        res.push_back("");
        while (index < digits.size()) {
            for (int i = 0; i < res.size(); i++){
                for (int j = 0; j < num2char[digits[index]].size(); j++) {
                    temp.push_back(res[i] + num2char[digits[index]][j]);
                }
            }
            res.swap(temp);
            temp.clear();
            index++;
        }
    return res;
    }
};

int main() {
    string digits = "23";
    Solution solu;
    int  num = solu.letterCombinations(digits).size();
    cout << "num of ans: " << num << endl;
}
