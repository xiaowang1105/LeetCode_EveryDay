/*************************************************************************
	> File Name: problem4_Median_of_Two_Sorted_Arrays.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 09 Apr 2018 02:05:02 PM CST
 ************************************************************************/

// Running Time is O(m + n) not accepted.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> merge(m + n, 1);
        int i = 0, j = 0, curr = 0;
        vector<int> target(2, 1);
        
        if((n + m) % 2 == 0) {
            target[0] = (n + m - 2)/2, target[1] = (n + m)/2;
        }
        else {target[0] = (n + m)/2, target[1] = (n + m)/2;}

        while(curr < n + m && i < n && j < m){
            if(nums1[i] > nums2[j]) {merge[curr] = nums2[j]; j++; curr++;}
            else {merge[curr] = nums1[i]; i++; curr++;}
        }
        
        if(i == n && curr < n + m) {for( ; j < m; j++ ) {merge[curr] = nums2[j];curr++;}}
        else if(j == m && curr < n + m){for( ; i < n; i++ ) {merge[curr] = nums1[i];curr++;}}
                
        double ans = (merge[target[0]] + merge[target[1]]) / 2.0;
        return ans;    
    };
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
