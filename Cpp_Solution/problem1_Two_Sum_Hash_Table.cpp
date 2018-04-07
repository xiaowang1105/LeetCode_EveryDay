/*************************************************************************
	> File Name: problem1_Two_Sum.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Apr 2018 08:06:00 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector <int> &nums, int target){
        unordered_map<int, int> lookup;
        vector <int> ans;
        for(int i = 0;i < nums.size();i++){
            if(lookup.count(target - nums[i])){
                ans.push_back(i);
                ans.push_back(lookup[target - nums[i]]);
                return ans;
            }
            lookup[nums[i]] = i;
        }
    }
};

int main()
{
    int temp[] = {2, 7, 11, 15};
    vector<int> nums(temp, temp + 4);
    int target = 9;
    Solution solu;
    vector <int> ans (2, 0);
    ans = solu.twoSum(nums, target);
    cout << "first number position:" << ans.front() << endl;
    cout << "second number position:" << ans.back() << endl;
    return 0;
}
