/*************************************************************************
	> File Name: problem16_3Sum_Closest.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Apr 2018 11:12:44 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include <stdlib.h> 
using namespace std;

class Solution {
public:
    int threeSumClosest(vector <int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int first, second, third;
        for (first = 0; first < nums.size(); first++) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            second = first + 1, third = nums.size() - 1;
            while (second < third) {
                int cur_sum = nums[first] + nums[second] + nums[third];
                if (cur_sum == target)
                    return closest;
                if (abs(target - cur_sum) < abs(target - closest))
                    closest = cur_sum;

                if (cur_sum < target)
                    second++;
                else if (cur_sum > target)
                    third;
            }
        }
        return closest;
    }
};

int main() {
    int temp[] = {-1, 2, 1, -4}, target = 1;
    vector <int> nums(temp, temp + 4);
    Solution solu;
    int ans = solu.threeSumClosest(nums, target);
    cout << "output is: " << ans << endl;
}
