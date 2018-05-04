/*************************************************************************
	> File Name: problem24_Swap_Nodes_in_Pairs_Recursive.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Fri 04 May 2018 07:02:19 PM CST
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head -> next == NULL)  return head;
        if (head -> next -> next == NULL) {
            ListNode* second = head -> next;
            second -> next = head;
            head -> next = NULL;
            return second;
        }
        ListNode* second = head -> next;
        ListNode* third = second -> next;
        second -> next = head;
        head -> next = swapPairs(third);
        return second;
    }
};

int main(){
    ListNode l1(0);
    ListNode* curr = &l1;
    curr -> next = new ListNode(1), curr = curr -> next;
    curr -> next = new ListNode(2), curr = curr -> next;
    curr -> next = new ListNode(4), curr = curr -> next;

    Solution solu;
    ListNode* new_head = solu.swapPairs(l1.next);
    cout << "input number 1 is: " << l1.next -> val << "->"  
        << l1.next -> next -> val << "->" << l1.next -> next -> next -> val << endl;

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
