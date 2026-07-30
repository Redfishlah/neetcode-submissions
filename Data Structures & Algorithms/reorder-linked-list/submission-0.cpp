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
    void reorderList(ListNode* head) {
        if(!head -> next) return;
        // find middle
        ListNode *slow = head, *fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        // partially reverse
        ListNode *prev = nullptr, *cur = slow -> next;
        slow -> next = nullptr; // seperate into two lists
        while(cur){
            ListNode *tmp = cur -> next;
            cur -> next = prev;
            prev = cur; // would be second half
            cur = tmp;
        }
        // merge
        while(prev){
            ListNode *front = head -> next, *behind = prev -> next;
            head -> next = prev;
            prev -> next = front;
            head = front;
            prev = behind;
        }
    }
};
