/*************************************************************************
	> File Name: problem23_Merge_k_Sorted_Lists_Divide_and_Conquer.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Tue 01 May 2018 09:41:56 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};


class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)
            return NULL;
        else if (k == 1)
            return lists[0];
        else if (k == 2)
            return merge2Lists(lists);
        else {
            int kHalf = k / 2;
            vector<ListNode*> listLeft(lists.begin(), lists.begin() + kHalf);
            vector<ListNode*> listRight(lists.begin() + kHalf, lists.end());
            ListNode* MergedListLeft = mergeKLists(listLeft);
            ListNode* MergedListRight = mergeKLists(listRight);
                        
            vector<ListNode*> TwoLists;
            TwoLists.push_back(MergedListLeft);
            TwoLists.push_back(MergedListRight);
            return merge2Lists(TwoLists);
        }
    }

    ListNode* merge2Lists(vector<ListNode*>& lists) {
        ListNode head(0);
        ListNode* cur = &head;
        ListNode* l1 = lists[0];
        ListNode* l2 = lists[1];

        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        while (l1 && l2) {
            if (l1 -> val < l2 -> val)
                cur -> next = l1, l1 = l1 -> next;
            else 
                cur -> next = l2, l2 = l2 -> next;
            cur = cur -> next;
        }
        cur -> next = l1 ? l1 : l2;
        return head.next;
    }
};

int main(){
    vector<ListNode*> lists;
    ListNode l1(0);
    ListNode* curr = &l1;
    curr -> next = new ListNode(1), curr = curr -> next;
    curr -> next = new ListNode(2), curr = curr -> next;
    curr -> next = new ListNode(4), curr = curr -> next;
    ListNode l2(0);
    curr = &l2;
    curr -> next = new ListNode(1), curr = curr -> next;
    curr -> next = new ListNode(3), curr = curr -> next;
    curr -> next = new ListNode(5), curr = curr -> next;
    ListNode l3(0);
    curr = &l3;
    curr -> next = new ListNode(10), curr = curr -> next;
    curr -> next = new ListNode(11), curr = curr -> next;
    curr -> next = new ListNode(12), curr = curr -> next;
   lists.push_back(l1.next), lists.push_back(l2.next), lists.push_back(l3.next);

    Solution solu;
    ListNode* new_head = solu.mergeKLists(lists);
    
    while (new_head -> next) {
        cout << new_head -> val;
        cout << "->";
        new_head = new_head -> next;
    }
    cout << new_head -> val;
    cout << endl;
    
    return 0;
}
