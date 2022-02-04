class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> bfs;
        bfs.emplace(p, q);
        while (!bfs.empty()) {
            auto [p, q] = bfs.front();
            if (!p ^ !q || (p && q && p->val != q->val)) {
                break;
            }
            bfs.pop();
            if (p && q) {
                bfs.emplace(p->left, q->left);
                bfs.emplace(p->right, q->right);
            }
        }
        return bfs.empty();
    }
};