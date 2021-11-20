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
    vector<int> rightSideView(TreeNode* root) {
        _rightView(root, 1);
        return ans;
    }
private:
    vector<int> ans;
    int maxLevel = 0;

    void _rightView(TreeNode* root, int level) {
        if (root == nullptr) {
            return;
        }
        if (maxLevel < level) {
            ans.push_back(root->val);
            maxLevel = level;
        }
        _rightView(root->right, level + 1);
        _rightView(root->left, level + 1);
    }
};