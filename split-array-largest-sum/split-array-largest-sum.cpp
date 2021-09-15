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
            cout << mid << endl;
            int num_bags(1);
            int cur = 0;
            for (int i = 0; i < nums.size(); cur += nums[i++]) {
                cout << cur << endl;
                if (cur + nums[i] > mid) {
                    cur = 0;
                    num_bags++;
                }
            }     
            
            if (m < num_bags) { // bags are too small
                left = mid + 1;
            }
            else{
                right = mid;
            }      
        }
        return left;
    }
};