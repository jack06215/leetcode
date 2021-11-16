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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, stk);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> stk;
    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        targetSum = targetSum - root->val;
        // we reach the end of node
        if (!root->left && !root->right) {
            // valid path is found
            if (targetSum == 0) {
                ans.push_back(path);
            }
        }
        else {
            dfs(root->left, targetSum, path);
            dfs(root->right, targetSum, path);
        }
        // backtracking
        path.pop_back();
    }
};