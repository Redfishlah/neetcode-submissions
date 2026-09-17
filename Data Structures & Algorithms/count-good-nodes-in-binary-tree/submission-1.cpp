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
    int goodNodes(TreeNode* root) {
        return dfs(root, root -> val);
    }
private:
    int dfs(TreeNode* node, int maxNode){
        if(!node) return 0;
        int res = (node -> val >= maxNode)? 1: 0;
        maxNode = max(node -> val, maxNode);
        res += dfs(node -> right, maxNode);
        res += dfs(node -> left, maxNode);
        return res;
    }
};
