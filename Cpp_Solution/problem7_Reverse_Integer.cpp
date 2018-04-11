/*************************************************************************
	> File Name: problem7_Reverse_Integer.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Apr 2018 04:49:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x) {
            int temp = ans * 10 + x % 10;
            if (temp / 10 != ans)
                return 0;
            ans = temp;
            x /= 10;
        }
        return ans;
    }
};

int main() {
    int x = 100;
    Solution solu;
    int y = solu.reverse(x);
    cout << "output is: " << y << endl;
}
