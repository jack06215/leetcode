class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n_rows = image.size();
        int n_cols = image[0].size();
        int oldColor = image[sr][sc];
        if (newColor == oldColor) {
            return image;
        }

        stack<pair<int, int>> dfs;
        dfs.push({ sr, sc });
        while (!dfs.empty()) {
            auto [row, col] = dfs.top();
            dfs.pop();
            if (image[row][col] == oldColor) {
                image[row][col] = newColor;
            }
            if (row >= 1 && image[row - 1][col] == oldColor) {
                dfs.push({ row - 1, col });
            }
            if (row + 1 < n_rows && image[row + 1][col] == oldColor) {
                dfs.push({ row + 1, col });
            }
            if (col >= 1 && image[row][col - 1] == oldColor) {
                dfs.push({ row, col - 1 });
            }
            if (col + 1 < n_cols && image[row][col + 1] == oldColor) {
                dfs.push({ row, col + 1 });
            }
        }
        return image;
    }
};