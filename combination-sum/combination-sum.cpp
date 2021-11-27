class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> combs;
    void combinationSum(vector<int>& candidates, int target, int begin) {
        if (target == 0) {
            res.push_back(combs);
            return;
        }
        for (int i = begin; i < candidates.size(); ++i) {
            if (target >= candidates[i]) {
                combs.push_back(candidates[i]);
                combinationSum(candidates, target - candidates[i], i);
                combs.pop_back();
            }
        }
    }
};