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
    int pathSum(TreeNode* root, int targetSum) {
        _ans = 0;
        _sums = {{0, 1}};
        _pathSum(root, 0, targetSum);
        return _ans;
    }
    
private:
    unordered_map<int, int> _sums;
    int _ans;
    void _pathSum(TreeNode* root, int curr, int target) {
        if (root == nullptr) {
            return;
        }
        curr += root->val;
        _ans += _sums[curr - target];
        _sums[curr]++;
        _pathSum(root->left, curr, target);
        _pathSum(root->right, curr, target);
        _sums[curr]--;
    }
};