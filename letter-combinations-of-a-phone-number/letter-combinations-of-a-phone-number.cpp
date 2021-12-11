class Solution {
public:
    vector<string> dial = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        list<string> q;
        vector<string> ans;

        q.push_back("");
        while (!q.empty()) {
            string curr = q.front();
            q.pop_front();

            if (curr.length() == digits.length()) {
                ans.push_back(curr);
            }
            else {
                string s = dial[digits[curr.length()] - '0'];
                for (auto x : s) {
                    q.push_back(curr + x);
                }
            }

        }
        return ans;
    }
};