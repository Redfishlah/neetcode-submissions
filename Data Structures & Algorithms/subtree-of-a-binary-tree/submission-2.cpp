/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(!subRoot) return true;
        if(!subRoot || isSameTree(root, subRoot)) return true;
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
    bool isSameTree(TreeNode* x, TreeNode* y){
        if(!x && !y) return true;
        if(x && y && x -> val == y -> val){
            return isSameTree(x -> left, y -> left) && isSameTree(x -> right, y -> right);
        }
        return false;
    }
};
