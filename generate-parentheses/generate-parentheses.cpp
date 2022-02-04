class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        generate("", n, n);
        return ans;
    }
    void generate(string s, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }
        if (open > 0) {
            generate(s + "(", open - 1, close);
        }
        if (open < close) {
            generate(s + ")", open, close - 1);
        }
    }
};