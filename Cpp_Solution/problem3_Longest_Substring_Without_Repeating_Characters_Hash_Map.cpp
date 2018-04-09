/*************************************************************************
	> File Name: problem3_Longest_Substring_Without_Repeating_Characters.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Apr 2018 04:43:54 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> char_map;
        int i = 0, j = 0, max_len = 0;
        int n = s.length();
        while(i < n && j < n){
            if(char_map.count(s[j]) == 0 || char_map[s[j]] < i) {
                char_map[s[j]] = j;
                j++;
                max_len = max(max_len, j - i);
            }
            else {
                i = char_map[s[j]] + 1;
                char_map[s[j]] = j;
                j++;
            }
        }
        return max_len;
    }
};

int main(){
    string str = "pwwkew";
    int i = 0;
    Solution solu;
    int length = solu.lengthOfLongestSubstring(str);
    cout << "max length: " << length << endl;
    int a, b;
    a, b = 0, 1;
    cout <<"dam   "<< a << ":" << b << endl;
}
