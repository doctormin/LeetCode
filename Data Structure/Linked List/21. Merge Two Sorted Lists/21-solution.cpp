// https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto p1 = l1;
        auto p2 = l2;
        ListNode * head = new ListNode();
        auto p = head;
        if(p1 == nullptr)
            return p2;
        if(p2 == nullptr)
            return p1;
        while(p1 != nullptr and p2 != nullptr){
            if(p1->val <= p2->val){
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }else{
                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
            if(p1 == nullptr){
                p->next = p2;
            }
            else if(p2 == nullptr){
                p->next = p1;
            }
        }
        return head->next;
    }
};
