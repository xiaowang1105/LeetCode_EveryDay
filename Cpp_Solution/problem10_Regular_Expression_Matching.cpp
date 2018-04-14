/*************************************************************************
	> File Name: problem10_Regular_Expression_Matching.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Apr 2018 04:07:01 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // set up bottom cases, immediately returns if length of pattern is <= 1
        if (p.length() == 0)
            return (s.length() == 0);
        if (p.length() == 1)
            return (s.length() == 1) && (s[0] == p[0] || p[0] == '.');

        // consider if the pattern has star
        if (p[1] != '*'){
            if (s.length() == 0) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while (s.length() != 0 && (s[0] == p[0] || p[0] == '.')){
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};

int main() {
    string s = "ab";
    string p = ".*c";
    Solution solu;
    bool is_match = solu.isMatch(s, p);
    cout << "result is: " << is_match << endl;
}
