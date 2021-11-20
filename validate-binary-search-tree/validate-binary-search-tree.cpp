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
    bool _isValid (TreeNode* node, TreeNode* minn, TreeNode* maxx) {
        if (node == nullptr) {
            return true;
        }
        if (minn && node->val <= minn->val) {
            return false;
        }
        if (maxx && node->val >= maxx->val) {
            return false;
        }
        return _isValid (node->left, minn, node) && _isValid (node->right, node, maxx);
    }
    
    bool isValidBST(TreeNode* root) {
        return _isValid (root, nullptr, nullptr);
    }
};