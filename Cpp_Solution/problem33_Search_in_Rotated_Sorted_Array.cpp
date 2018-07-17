/*************************************************************************
	> File Name: problem33_Search_in_Rotated_Sorted_Array.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Tue 17 Jul 2018 09:58:31 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = int(nums.size()) - 1;
        while (lo < hi) {
            int mid = (hi + lo) / 2;
            if ((nums[0] > nums[mid]) ^ (target > nums[mid]) ^ (target < nums[0]))
                lo = mid + 1;
            else 
                hi = mid;
        }

        return lo == hi && nums[lo] == target ? lo : -1;
    }
};

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    Solution solu;
    int ans = solu.search(nums, target);
    cout << ans << endl;
}
