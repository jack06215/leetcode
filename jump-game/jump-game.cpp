class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size() - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                return false;
            }
            nums[i + 1] = max(nums[i + 1],nums[i] - 1);
        }
        return true;
    }
};