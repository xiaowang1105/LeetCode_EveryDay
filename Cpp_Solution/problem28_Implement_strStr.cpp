/*************************************************************************
	> File Name: problem28_Implement_strStr.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Sat 05 May 2018 08:02:54 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int lenNee = needle.length();
        int lenHay = haystack.length();
        int j = 0;
        for (int i = 0; i < lenHay; i++) {
            if (haystack[i] == needle[j]) j++;
            else 
                i -= j, j = 0;
            if (j == lenNee)
                return i - j + 1;   
        }
        return -1;    
    }
};
int main() {
    string haystack = "absd";
    string needle = "bs";
    Solution solu;
    int pos = solu.strStr(haystack, needle);
    cout << pos << endl;
}
