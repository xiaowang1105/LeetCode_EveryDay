/*************************************************************************
	> File Name: problem25_Reverse_Nodes_in_k-Group.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Fri 04 May 2018 09:00:35 PM CST
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = lengthOfList(head);
        int round = len / k;
        
        ListNode* newHead = new ListNode(0);
        newHead -> next = head;
        ListNode* prev = newHead;
        ListNode* nextPrev = NULL;

        for (int i = 0;i < round; i++) {
            for (int j = 0; j < k; j++) {
                if (j == 0) nextPrev = head;
                ListNode* saveNext = head -> next;
                head -> next = prev -> next;
                prev -> next = head;
                head = saveNext;
            }
            prev = nextPrev;
        }
        prev -> next  = head;
        return newHead -> next;
    
    }

private:
    int lengthOfList(ListNode* head) {
        int len = 0;
        while(head) {
            len ++;
            head = head -> next;
        }
        return len;
    }
};

int main(){
    ListNode l1(0);
    ListNode* curr = &l1;
    curr -> next = new ListNode(1), curr = curr -> next;
    curr -> next = new ListNode(2), curr = curr -> next;
    curr -> next = new ListNode(4), curr = curr -> next;
    curr -> next = new ListNode(3), curr = curr -> next;

    Solution solu;
    cout << "input number 1 is: " << endl;
    ListNode* Input = l1.next;
    while (Input -> next) {
        cout << Input -> val;
        cout << "->";
        Input = Input -> next;
    }
    cout << Input -> val;
    cout << endl;

    ListNode* head = solu.reverseKGroup(l1.next, 2);
    cout << "output number is: " << endl;
    while (head -> next) {
        cout << head -> val;
        cout << "->";
        head = head -> next;
    }
    cout << head -> val;
    cout << endl;
    return 0;
}
