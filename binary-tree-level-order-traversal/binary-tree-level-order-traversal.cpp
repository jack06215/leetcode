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
    vector<vector<int>> levelOrder(TreeNode* root) {
        buildVector(root, 0);
        return res;
    }
    
private:
    vector<vector<int>> res;
    void buildVector(TreeNode *root, int depth) {
        if (root == nullptr) {
            return;
        }
        
        if (res.size() == depth) {
            res.resize(depth + 1);
        }

        res[depth].push_back(root->val);
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
    }
};