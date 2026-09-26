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
    int preIndex = 0;
    unordered_map<int, int> inMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 1. Build a Hash Map to find values in inorder array in O(1) time
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        // 2. Start the recursive build
        return build(preorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, int inStart, int inEnd) {
        // Base case: If the range is invalid, there is no tree to build
        if (inStart > inEnd) return nullptr;

        // The current root is always the next unused value in preorder
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find where this root is in the inorder array
        int mid = inMap[rootVal];

        // Recursively build the left and right subtrees
        root->left = build(preorder, inStart, mid - 1);
        root->right = build(preorder, mid + 1, inEnd);

        return root;
    }
};