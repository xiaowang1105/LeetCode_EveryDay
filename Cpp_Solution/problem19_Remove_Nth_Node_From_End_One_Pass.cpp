/*************************************************************************
	> File Name: problem20_Remove_Nth_Node_From_End_One_Pass.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Wed 18 Apr 2018 08:06:41 PM CST
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return nullptr;
        
        ListNode new_head(0);
        new_head.next = head;
        int i = 0;
        ListNode* cur = &new_head;
        ListNode* rem = &new_head;

        while (cur -> next) {
            if (i < n) {
                cur = cur -> next;
                i++;
            }
            else {
                cur = cur -> next;
                rem = rem -> next;
            }
        }

        ListNode* delete_node = rem -> next;
        rem -> next = rem -> next -> next;
        delete delete_node;

        return new_head.next;
    }
};


int main(){
    ListNode l1(0);
    auto curr = &l1;
    curr -> next = new ListNode(1), curr = curr -> next;
    curr -> next = new ListNode(2), curr = curr -> next;
    curr -> next = new ListNode(3), curr = curr -> next;
    curr -> next = new ListNode(4), curr = curr -> next;
    curr -> next = new ListNode(5), curr = curr -> next;

    Solution solu;
    curr = solu.removeNthFromEnd(l1.next, 2);

    cout << "output number is: " << curr -> val << "->"  
        << curr -> next -> val << "->" << curr -> next -> next -> val <<
        "->" << curr -> next -> next ->next -> val << endl;
    
    return 0;
}
