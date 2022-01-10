class Solution {
    const int maxx = numeric_limits<int>::max();
    const int minn = numeric_limits<int>::min();
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int num = (nums[mid] < nums[0]) == (target < nums[0])
                ? nums[mid]
                : target < nums[0] ? minn : maxx;
            if (num == target) {
                return mid;
            }
            else if (num < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return -1;
    }
};