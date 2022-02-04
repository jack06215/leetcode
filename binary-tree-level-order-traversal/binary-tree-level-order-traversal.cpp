class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> add;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int count = que.size();
            for (int i = 0; i < count; i++) {
                root = que.front();
                que.pop();
                add.push_back(root->val);
                if (root->left != nullptr) {
                    que.push(root->left);
                }
                if (root->right != nullptr) {
                    que.push(root->right);
                }
            }
            ans.push_back(add);
            add.clear();
        }

        return ans;
    }
};