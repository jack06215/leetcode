class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode* >> stk;
        stk.emplace(p, q);
        while (!stk.empty()) {
            auto [p, q] = stk.top();
            if (!p ^ !q || (p && q && p->val != q->val)) {
                break;
            }
            stk.pop();
            if (p && q) {
                stk.emplace(p->right, q->right);
                stk.emplace(p->left, q->left);
            }
        }
        return stk.empty();
    }
};