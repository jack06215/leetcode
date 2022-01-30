class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        vector<int> dp(s.size() + 1, 0);
        int res = 0;
        for (int i = 1; i <= s.size(); i++) {
            if (s[i - 1] == '(') {
                stk.push(i - 1);
                dp[i] = 0;
            }
            else if (s[i - 1] == ')') {
                if (stk.empty()) {
                    dp[i] = 0;
                }
                if (!stk.empty() && s[stk.top()] == '(') {
                    dp[i] = dp[i - 1] + dp[stk.top()] + 1;
                    stk.pop();
                }
            }
            res = max(res, dp[i]);
        }
        return 2 * res;
    }
};