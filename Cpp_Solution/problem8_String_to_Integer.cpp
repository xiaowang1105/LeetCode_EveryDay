/*************************************************************************
	> File Name: problem8_String_to_Integer.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Apr 2018 05:05:49 PM CST
 ************************************************************************/

#include<iostream>
#include<limits.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        int i = 0;

        // remove white spaces
        while(i < n && str[i] == ' ') i++;

        // point to first valid element
        int first = str[i] - '0';
        int sign_flag = 1;
        if (first == -3 || first == -5) { // if it is a sign
            sign_flag = (first == -3) ? -1 : 1;
            i++;
            first = str[i] - '0';
        }

        if ( !(first >= 0 && first <= 9)  ) return 0; // if it is not a '+', '-' or numbers

        int ans = 0;
        int p = str[i] - '0';
        while (p >= 0 && p <= 9 && i < n) {
            int temp = ans * 10 + sign_flag * p;
            if (temp / 10 != ans) return sign_flag == -1 ? INT_MIN : INT_MAX;
            ans = temp;
            i++;
            p = str[i] - '0';
        }
        return ans;
    }

};

int main() {
    string s = "123";
    Solution solu;
    int ans = solu.myAtoi(s);
    cout << "output is: " << ans << endl;
}
