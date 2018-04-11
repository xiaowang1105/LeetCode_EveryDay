/*************************************************************************
	> File Name: problem6_ZigZag_Conversion.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Apr 2018 09:33:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
    public:
    string convert(string s, int numRows) {
        int n = s.length();
        if (numRows == 1) return s;
        string zigzag;
        int step = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++){
            for (int j = i; j < n; j += step){
                zigzag.push_back(s[j]);
                if (i > 0 && i < numRows - 1 && j + step - 2 * i < n) zigzag.push_back(s[j + step - 2 * i]);
            }
        }
        return zigzag;
    }

};

int main() {
    string s = "PAYPALISHIRING";
    Solution solu;
    string zigzag = solu.convert(s, 3);
    cout << "output is: " << zigzag << endl;
}
