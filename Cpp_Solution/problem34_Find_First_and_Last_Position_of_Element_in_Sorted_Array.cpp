/*************************************************************************
	> File Name: problem34_Find_First_and_Last_Position_of_Element_in_Sorted_Array.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Tue 17 Jul 2018 10:45:26 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans(2);
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] >= target) 
                hi = mid;
            else 
                lo = mid + 1;
        }
        if (lo == hi && nums[lo] == target) ans[0] = lo;
        else {
                ans[0] = -1;
                ans[1] = -1;
                return ans;
        }
                
        hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2 + 1;
            if (nums[mid] > target) 
                hi = mid - 1;
            else 
                lo = mid;
        }
        ans[1] = hi;
        return ans;    
    }
};


int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    Solution solu;
    vector<int> ans = solu.searchRange(nums, target);
}

