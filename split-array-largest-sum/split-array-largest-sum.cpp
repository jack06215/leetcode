class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 1);
        for (auto num: nums) {
            left = max(left, num);
        }
        while(left < right) {
            int mid = (left + right) / 2; 
            if (splitBags(nums, mid) > m) {
                left = mid + 1;
            }
            else{
                right = mid;
            }      
        }
        return left;
    }
private:
    int splitBags(vector<int>& nums, int target) {
        int sum = 0;
        int n_bags = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > target) {
                sum = 0;
                n_bags++;
            }
            sum += nums[i];
        }
        return n_bags;
    }
};