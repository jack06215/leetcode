class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // increment step by middle point
            int mid = left + (right - left) / 2;
            
            // we found the answer!
            if (nums[mid] == target) {
                return mid;
            }
            
            // too big, shift the high bound
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            // too small, sift the low bound
            else {
                left = mid + 1; 
            }
        }
        return left;
    }
};