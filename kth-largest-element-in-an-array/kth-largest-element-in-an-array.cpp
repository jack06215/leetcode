class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        struct cmp {
            bool operator()(const int& left, const int& right) {
                return left > right;
            }
        };
        priority_queue<int, vector<int>, cmp> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
            if (q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }
};