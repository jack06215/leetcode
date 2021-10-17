class Solution {
public:
    string simplifyPath(string path) {
        string result{""}, token{};
        istringstream tokenizer(path);
        vector<string> dir;
        while (getline(tokenizer, token, '/')) {
            if (token == "." || token == "") continue;
            else if (token=="..") {
                if (!dir.empty()) {
                    dir.pop_back();
                }
            }
            else dir.push_back(token);
        }
        if (dir.empty()) return "/";
        for(int i = 0; i < dir.size(); ++i)
            result = result + '/' +dir[i];
        return result;
    }
};