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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head), *res = dummy, *fast = head;
        while(n > 0 && fast != nullptr){
            fast = fast -> next;
            n--;
        }
        while(fast != nullptr){
            fast = fast -> next;
            res = res -> next;
        }
        res -> next = res -> next -> next;
        return dummy -> next;
    }
};
