/*************************************************************************
	> File Name: problem23_Merge_k_Sorted_Lists_Heap.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Wed 02 May 2018 09:58:17 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

struct compare {
    bool operator()(const ListNode* l1, const ListNode* l2) {
        return l1->val > l2->val; 
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> min_heap;
        ListNode head(0);
        ListNode* cur = &head;
        for (ListNode* l : lists) if (l) min_heap.emplace(l);
        while (!min_heap.empty()) {
            cur -> next = min_heap.top();
            min_heap.pop();
            cur = cur -> next;
            if (cur -> next) min_heap.emplace(cur -> next);
        }
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
