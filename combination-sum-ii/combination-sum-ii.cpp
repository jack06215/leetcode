class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        _combinationSum2(candidates, target, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> combs;

    void _combinationSum2(vector<int>& candidates, int target, int begin) {
        if (target == 0) {
            res.push_back(combs);
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {
            if (target >= candidates[i] && (i == begin || candidates[i] != candidates[i - 1])) {
                combs.push_back(candidates[i]);
                _combinationSum2(candidates, target - candidates[i], i + 1);
                combs.pop_back();
            }
        }
    }
};