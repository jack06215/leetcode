class Solution { // 8 ms, faster than 91.61%
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (res.empty() || res[res.size() - 1] < nums[i]) {
                res.push_back(nums[i]);
            }
            else {
                auto it = lower_bound(begin(res), end(res), nums[i]);
                *it = nums[i];
            }
        }
        return res.size();
    }
};