/*************************************************************************
	> File Name: problem3_Longest_Substring_Without_Repeating_Characters.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Apr 2018 04:43:54 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, max_len = 0;
        int n = s.length();
        while(i < n && j < n){
            if(allUnique(s, i, j)) {j++; max_len = max(max_len, j - i);}
            else {i++;}
        }
        return max_len;
    }
    bool allUnique(string s, int start, int end){
        for(int i = start; i < end; i++){
            if(s[i] == s[end]) {return false;}
        return true;    
        }
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
