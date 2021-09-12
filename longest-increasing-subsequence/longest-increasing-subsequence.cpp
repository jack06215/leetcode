class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int cur_size = result.size();
            if (result.size() == 0 || result[cur_size - 1] < nums[i]) {
                result.push_back(nums[i]);
            }
            else {
                int left = 0;
                int right = cur_size - 1;
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
        for (const int& val: result) cout << val << " ";
        cout << endl;
        return result.size();
    }
};
