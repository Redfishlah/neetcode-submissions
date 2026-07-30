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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = root;
        while(res){
            // both smaller than root
            if(p -> val < res -> val && q -> val < res -> val) res = res -> left;
            // both bigger than root
            else if(p -> val > res -> val && q -> val > res -> val) res = res -> right;
            else return res; 
        }
        return {};
    }
};
