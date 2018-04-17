/*************************************************************************
	> File Name: problem18_4Sum.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Tue 17 Apr 2018 09:13:24 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        vector< vector<int> > ans;
        std::sort(nums.begin(), nums.end());
        int first, second, third, fourth;
                
        if (nums.size() < 4) return ans;
                
        for (first = 0; first < nums.size() - 3; first++) {
            for (second = first + 1; second < nums.size() - 2; second++) {
                third = second + 1, fourth = nums.size() - 1;
                while (third < fourth) {
                    int temp_sum = nums[first] +  nums[second] + nums[third] + nums[fourth];
                    if (temp_sum > target)
                        fourth--;
                    else if (temp_sum < target)
                                            third++;
                    else {
                        vector<int> temp(4, 0);
                        temp[0] = nums[first], temp[1] = nums[second], temp[2] = nums[third], temp[3] = nums[fourth];
                        ans.push_back(temp);
                        third++, fourth--;
                        while (temp[2] == nums[third] && third < fourth)
                            third++;
                        while (temp[3] == nums[fourth] && third < fourth)
                            fourth--;
                    }
                }
                    while (second < nums.size() - 2 && nums[second] == nums[second + 1])
                        second++;    
            }
                    while (first < nums.size() - 3 && nums[first] == nums[first + 1])
                        first++;
        }
        return ans;    
    }
};

int main() {
    int temp[] = {1, 0, -1, 0, -2, 2}, target = 0;
    vector <int> nums(temp, temp + 6);
    Solution solu;
    solu.fourSum(nums, target);
    // cout << "output is: " << ans << endl;
}
