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
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1;
    }
    vector<int> dfs(TreeNode* root){
        if(!root) return {1, 0};
        // see if left tree is balanced
        vector<int> l = dfs(root -> left);
        // see if right tree is balanced
        vector<int> r = dfs(root -> right);
        // see if new tree is balanced
        bool bal = (l[0] == 1 && r[0] == 1) && abs(l[1] - r[1]) <= 1;
        // return {if balanced, the height of the tree}
        return {bal, 1 + max(l[1], r[1])};
    }
};
