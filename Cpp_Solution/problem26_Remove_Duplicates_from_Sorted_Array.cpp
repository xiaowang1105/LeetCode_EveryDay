/*************************************************************************
	> File Name: problem26_Remove_Duplicates_from_Sorted_Array.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Sat 05 May 2018 07:13:04 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int i = 0, j = 0;
        while (i < n) {
            while (nums[i] == nums[j])
                i++;
            j++;
            nums[j] = nums[i];
        }
        return j;
    }
};

int main() {
    int temp[] = {0, 0, 1, 1, 3, 4};
    vector <int> nums(temp, temp + 6);
    Solution solu;
    int length = solu.removeDuplicates(nums);
    for (int i = 0; i < length; i++) {
        cout << nums[i] << endl;
    }
}
