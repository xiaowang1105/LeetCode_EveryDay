/*************************************************************************
	> File Name: problem4_Median_of_Two_Sorted_Arrays.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 09 Apr 2018 02:05:02 PM CST
 ************************************************************************/

// Running Time is O(log(m + n)).

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double get_Kth(vector <int> nums1, vector <int> nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        // make sure n <= m
        if (n > m) return get_Kth(nums2, nums1, k);

        // set up bottom case
        if (n == 0) return nums2[k - 1];
        if (k == 1) return min(nums1[0], nums2[0]);

        // divide k_th position finding into half
        int i = min(n, k / 2), j = min(m, k / 2);
        if (nums1[i - 1] > nums2[j - 1])
            return get_Kth(nums1, vector <int> (nums2.begin() + j, nums2.end()), k - j);
        else
            return get_Kth(vector <int> (nums1.begin() + i, nums1.end()), nums2, k - i);
    }
        

    double findMedianSortedArrays(vector <int> &nums1, vector <int> &nums2) {
        int n = nums1.size(), m = nums2.size();
        int l = (n + m + 1) >> 1, r = (n + m + 2) >> 1;
        return (get_Kth(nums1, nums2, l) + get_Kth(nums1, nums2, r)) / 2.0 ;
    }
};

int main(){
    int a1[2] = {1, 2};
    int a2[2] = {3, 4};
    vector <int> nums1(a1, a1 + 2);
    vector <int> nums2(a2, a2 + 2);
    Solution solu;
    double ans = solu.findMedianSortedArrays(nums1, nums2);
    cout << "median is: " << ans << endl;

}
