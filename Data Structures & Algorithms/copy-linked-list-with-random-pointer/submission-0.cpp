/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> tmp;
        // Create a copy of every node with only values
        for(Node* curr = head; curr; curr = curr -> next){
            tmp[curr] = new Node(curr -> val);
        }
        //  Link the "next" and "random" pointers
        for(Node* curr = head; curr; curr = curr -> next){
            tmp[curr] -> next = tmp[curr -> next];
            tmp[curr] -> random = tmp[curr -> random]; 
        }
        return tmp[head];
    }
};
