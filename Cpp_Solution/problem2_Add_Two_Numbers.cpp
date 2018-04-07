/*************************************************************************
	> File Name: problem2_Add_Two_Numbers.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Apr 2018 09:32:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head{0};
        auto curr = &head;
        auto carry = 0;
        while(l1 || l2 || carry){
            auto a = l1 ? l1 -> val : 0, b = l2 ? l2 -> val : 0;
            auto val = a + b + carry;
            curr -> next = new ListNode{val % 10};
            carry = val / 10;
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
            curr = curr -> next;
        }
        return head.next;
    }

};

int main(){

    return 0;
}
