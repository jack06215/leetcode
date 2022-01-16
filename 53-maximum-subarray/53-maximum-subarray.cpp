class Solution {
    vector<int> arr;
public:
    int cross(int left, int right, int mid) {
        int ans1 = numeric_limits<int>::min();
        int ans2 = numeric_limits<int>::min();
        for (int i = mid, sum = 0; i >= left; i--) {
            sum += arr[i];
            ans1 = max(ans1, sum);
        }
        for (int i = mid + 1, sum = 0; i <= right; i++) {
            sum += arr[i];
            ans2 = max(ans2, sum);
        }
        return ans1 + ans2;
    }

    int _maxSubArray(int left, int right) {
        if (left >= right) {
            return arr[left];
        }

        int mid = left + (right - left) / 2;
        int sl = _maxSubArray(left, mid);
        int sr = _maxSubArray(mid + 1, right);

        int sumCross = cross(left, right, mid);
        return max(sumCross, max(sl, sr));
    }

    int maxSubArray(vector<int>& nums) {
        arr = nums;
        int n = nums.size();
        return _maxSubArray(0, n - 1);
    }
};