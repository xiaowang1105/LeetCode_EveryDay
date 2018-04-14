/*************************************************************************
	> File Name: problem14_Longest_Common_Prefix.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Apr 2018 03:48:19 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> & strs) {
        int len = strs.size();
        if (len == 0) return "";
        string prefix = strs[0];
        for (int i = 1; i < len; i++){
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.length() == 0) return "";
            }
        }
        return prefix;
    }
};

int main() {
    string temp[] = {"a", "ab"};
    vector <string> strs(temp, temp + 2);
    Solution solu;
    string prefix = solu.longestCommonPrefix(strs);
    cout << "common prefix is: " << prefix << endl;
}
