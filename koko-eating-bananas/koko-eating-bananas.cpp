class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1;
        int right = 1e9;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int k = calculate_consume_hours(piles, mid);
            if (k > H)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
private:
    int calculate_consume_hours(vector<int>& piles, int capacity) {
        int k = 0;
        for (int pile : piles)
            k += (pile + capacity - 1) / capacity;
        return k;
    }
};