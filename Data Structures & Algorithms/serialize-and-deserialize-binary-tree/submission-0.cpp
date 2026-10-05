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

class Codec {
private:
    // Helper to recursively serialize the tree
    void serializeHelper(TreeNode* node, ostringstream& out) {
        if (node == nullptr) {
            out << "N "; // 'N' marks a null pointer, followed by a space
            return;
        }
        // Preorder: Root -> Left -> Right
        out << node->val << " ";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }
    // Helper to recursively deserialize the string
    TreeNode* deserializeHelper(istringstream& in) {
        string val;
        in >> val; // Automatically grabs the next chunk of text until a space
        if (val == "N" || val.empty()) return nullptr;
        // Preorder reconstruction: Root -> Left -> Right
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }
};