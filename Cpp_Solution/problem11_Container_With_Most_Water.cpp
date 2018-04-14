/*************************************************************************
	> File Name: problem11_Container_With_Most_Water.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Apr 2018 01:57:18 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int max_area = 0;
        while (i < j) {
            int temp = (j - i) * min(height[i], height[j]);
            max_area = temp > max_area ? temp : max_area;
            if (height[i] > height[j]) j--;
            else i++;
        }
        return max_area;
    }
};

int main() {
    int temp[] = {1, 2};
    vector <int> nums(temp, temp + 2);
    Solution solu;
    int ans = solu.maxArea(nums);
    cout << "output is: " << ans << endl;
}
