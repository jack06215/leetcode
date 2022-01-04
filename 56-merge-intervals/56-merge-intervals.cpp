class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](auto a, auto b){ return a[1] < b[1]; });
        for (auto& interval: intervals) {
            int left = interval[0];
            int right = interval[1];
            while (!res.empty() && left <= res.back()[1]) {
                left = min(left, res.back()[0]);
                res.pop_back();
            }
            res.push_back({left, right});
        }
        return res;
    }
};