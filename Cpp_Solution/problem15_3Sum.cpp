/*************************************************************************
	> File Name: problem15_3Sum.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Apr 2018 03:55:09 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector < vector<int> > threeSum(vector<int> &nums) {
        vector< vector<int> > res;
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++){
            int front = i + 1, back = nums_size - 1;
            int target = -nums[i];
            while (front < back) {
                int temp_sum = nums[front] + nums[back];
                
                if (temp_sum < target)
                    front++;
                else if (temp_sum > target)
                    back--;
                else {
                    vector <int> temp_tri(3, 0);
                    temp_tri[0] = nums[i],temp_tri[1] = nums[front], temp_tri[2] = nums[back];
                    res.push_back(temp_tri);
                    while (front < back && temp_tri[1] == nums[front] )
                        front++;
                    while (front < back && temp_tri[2] == nums[back])
                        back--;
                    while (i + 1 < nums_size && nums[i + 1] == nums[i])
                        i++;
                }
            }
        }
        return res;
    }
};

int main() {
    int temp[] = {-1, 0, 1, 2, -1, -4};
    vector <int> nums(temp, temp + 6);
    Solution solu;
    vector< vector<int> > vec;
    vector <int> tri (3, 0);
    vec.push_back(tri), vec.push_back(tri);
    vec = solu.threeSum(nums);
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << endl;
        }
    }
}
