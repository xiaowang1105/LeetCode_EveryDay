/*************************************************************************
	> File Name: problem21_Merge_Two_Sorted_Lists.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Thu 19 Apr 2018 02:56:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* cur = &head;
       
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        while (l1 && l2) {
            if (l1 -> val < l2 ->val)
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
    ListNode l1(0);
    ListNode* curr = &l1;
    curr -> next = new ListNode(1), curr = curr -> next;
    curr -> next = new ListNode(2), curr = curr -> next;
    curr -> next = new ListNode(4), curr = curr -> next;
    ListNode l2(0);
    curr = &l2;
    curr -> next = new ListNode(1), curr = curr -> next;
    curr -> next = new ListNode(3), curr = curr -> next;
    curr -> next = new ListNode(4), curr = curr -> next;

    Solution solu;
    ListNode* new_head = solu.mergeTwoLists(l1.next, l2.next);
    cout << "input number 1 is: " << l1.next -> val << "->"  
        << l1.next -> next -> val << "->" << l1.next -> next -> next -> val << endl;

    cout << "input number 2 is: " << l2.next -> val << "->"  
        << l2.next -> next -> val << "->" << l2.next -> next -> next -> val << endl;
    cout << "output number is: " << endl;
    while (new_head -> next) {
        cout << new_head -> val;
        cout << "->";
        new_head = new_head -> next;
    }
    cout << new_head -> val;
    cout << endl;
    
    return 0;
}
