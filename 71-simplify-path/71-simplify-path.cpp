class Solution {
public:
    string simplifyPath(string path) {
        string result;
        string token;
        istringstream tokenizer(path);
        vector<string> dir;
        while (getline(tokenizer, token, '/')) {
            // no change
            if (token == "." || token == "") {
                continue;
            }
            // back to parent directory
            else if (token == "..") {
                // skip if it's already root directory
                if (!dir.empty()) {
                    dir.pop_back();
                }
            }
            // go inner directory
            else {
                dir.push_back(token);
            }
        }
        // root directory
        if (dir.empty()) {
            return "/";
        }

        // make conanical directory
        for (const auto& it : dir) {
            result += '/' + it;
        }
        return result;
    }
};