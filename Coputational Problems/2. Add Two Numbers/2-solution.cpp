/*
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans   = new ListNode(-1);
        auto      cur   = ans;
        int       sum   = 0;
        int       carry = 0;
        while(l1 != nullptr and l2 != nullptr){
            sum   = l1->val + l2->val + carry;
            carry = sum / 10;
            cur->next   = new ListNode(sum%10);
            cur   = cur->next;
            l1    = l1->next;
            l2    = l2->next;
        }
        while(l1){
            sum   = l1->val + carry;
            carry = sum / 10;
            cur->next   = new ListNode(sum%10);
            cur   = cur->next;
            l1    = l1->next;
        }
        while(l2){
            sum = l2->val + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            l2 = l2->next;
        }
        if(carry == 1){
            cur->next = new ListNode(1);
        }

        return ans->next;
    }
};