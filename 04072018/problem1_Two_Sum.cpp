/*************************************************************************
	> File Name: problem1_Two_Sum.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Apr 2018 08:06:00 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector <int> &nums, int target){
        vector <int> ans;
        for(int i = 0;i < nums.size();i++){
            for(int j = 0;j < nums.size();j++){
                if(nums[j] == target - nums[i]){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
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
