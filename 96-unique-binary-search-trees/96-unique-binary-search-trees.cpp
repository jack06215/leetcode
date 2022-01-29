class Solution {
    vector<vector<int>> dp;
public:
    int helper(int i, int j) {

        if (i >= j) {
            return 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int temp = 0;
        int left;
        int right;

        for (int k = i; k <= j; ++k) {
            left = helper(i, k - 1);
            right = helper(k + 1, j);
            temp += left * right;
        }
        return dp[i][j] = temp;
    }

    int numTrees(int n) {
        dp.resize(20, vector<int>(20, -1));
        return helper(0, n - 1);
    }
};