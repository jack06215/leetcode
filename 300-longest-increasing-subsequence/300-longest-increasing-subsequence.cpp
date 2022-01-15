class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int cur_size = result.size();
            int left = 0;
            int right = cur_size - 1;
            if (result.empty() || result[right] < nums[i]) {
                result.push_back(nums[i]);
            }
            else {
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (result[mid] >= nums[i]) {
                        right = mid;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                result[left] = nums[i];
            }
        }
        return result.size();
    }
};