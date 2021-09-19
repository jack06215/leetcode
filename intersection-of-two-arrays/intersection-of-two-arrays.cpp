class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> res;
        for (int& num1: nums1) {
            int val = binarySearch(nums2, num1, 0, nums2.size() - 1);
            if (val != -1) {
                res.emplace_back(val);
            }
        }
        return res;
    }
private:
    int binarySearch(vector<int>& arr, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                arr.erase(remove(arr.begin(), arr.end(), target), arr.end());
                return target;
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};