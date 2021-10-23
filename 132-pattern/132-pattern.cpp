class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int last = nums.size() - 1;
        stack<int> stk;
        int third = numeric_limits<int>::min();
        for (int i = last; i >= 0; i--) {
            int num = nums[i];
            if (num < third) {
                return true;
            }
            while (!stk.empty() && num > stk.top()) {
                third = stk.top();
                stk.pop();
            }
            stk.push(num);
        }
        return false;
    }
};