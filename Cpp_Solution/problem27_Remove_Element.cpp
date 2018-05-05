/*************************************************************************
	> File Name: problem27_Remove_Element.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Sat 05 May 2018 07:41:42 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0, j = 0;
        if (n == 0) return 0;
        while (i < n) {
            while (nums[i] == val)
                i++;
            if (i > n - 1)
                return j;
            nums[j] = nums[i];
            j++, i++;
        }
        return j;
    }
};

int main() {
    int temp[] = {0, 0, 1, 1, 3, 4};
    vector <int> nums(temp, temp + 6);
    Solution solu;
    int length = solu.removeElement(nums, 0);
    for (int i = 0; i < length; i++) {
        cout << nums[i] << endl;
    }
}
