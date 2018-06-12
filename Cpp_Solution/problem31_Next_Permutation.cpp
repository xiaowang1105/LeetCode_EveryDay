/*************************************************************************
	> File Name: problem31_Next_Permutation.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Tue 12 Jun 2018 08:16:23 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, k = i, tmp;
        while (i >0 && nums[i - 1] >= nums[i]) {
            i--;
        }
        for (int j = i; j < k; j++, k--) {
            swap(nums[j], nums[k]);
        }
        if (i > 0) {
            k = i--;
            while (nums[k] <= nums[i])
                k++;
        }
        swap(nums[i], nums[k]);
    }
};

int main() {
    static const int arr[] = {16,2,77,29};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    Solution solu;
    solu.nextPermutation(nums);
    int len = nums.size();
    for (int i = 0; i < len; i++)
        std::cout << nums[i] << ' ' << endl;
}
