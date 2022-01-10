class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size();
        while (head < tail) {
            int mid = head + (tail - head) / 2;
            
            int num = (nums[mid] < nums[0]) == (target < nums[0])
                    ? nums[mid]
                    : target < nums[0] ? numeric_limits<int>::min() : numeric_limits<int>::max();
                    
            if (num < target)
                head = mid + 1;
            else if (num > target)
                tail = mid;
            else
                return mid;
        }
        return -1;
    }
};