class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> merged;
        if (intervals.size() == 0) {
            return true;
        }
        sort(intervals.begin(), intervals.end(), [](auto lhs, auto rhs) { return lhs[0] < rhs[0]; });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        return true;
    }
};