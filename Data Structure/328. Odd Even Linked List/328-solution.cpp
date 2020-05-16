// https://leetcode.com/problems/odd-even-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        auto odd_p = head;
        auto even_p = head->next;
        auto node = head->next->next;
        bool odd_f = 1;
        auto tmp = head->next;
        while(node != nullptr){
            if(odd_f){
                odd_p->next = node;
                odd_f = 0;
                odd_p = odd_p->next;
            }
            else{
                even_p->next = node;
                odd_f = 1;
                even_p = even_p->next;
            }
            node = node->next;
        }
        even_p->next = nullptr;
        odd_p->next = tmp;
        return head; 
    }
};