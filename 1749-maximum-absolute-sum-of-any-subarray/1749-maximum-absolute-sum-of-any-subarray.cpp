class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        vector<vector<int>> dp(2, vector<int>(size + 1));
        for (int i = 1; i <= size; i++) {
            dp[0][i] = min(dp[0][i - 1] + nums[i - 1], nums[i - 1]);
            dp[1][i] = max(dp[1][i - 1] + nums[i - 1], nums[i - 1]);
        }

        for (int i = 0; i <= size; i++) {
            res = max(res, max(abs(dp[0][i]), abs(dp[1][i])));
        }

        return res;
    }
};