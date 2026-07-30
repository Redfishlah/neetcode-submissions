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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode* root, int& res){
        if(!root) return 0;
        // know the longest on left
        int l = dfs(root -> left, res);
        // know the longest on right
        int r = dfs(root -> right, res);
        // update the only res
        res = max(res, l + r);
        // return the longer wing
        return 1 + max(l, r);
    }
};
