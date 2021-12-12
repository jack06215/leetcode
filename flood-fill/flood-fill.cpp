class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n_rows = image.size();
        n_cols = image[0].size();
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        if (r >= n_rows || r < 0 || c >= n_cols || c < 0) {
            return;
        }
        if (image[r][c] != oldColor || image[r][c] == newColor) {
            return;
        }
        image[r][c] = newColor;
        dfs(image, r + 1, c, oldColor, newColor);
        dfs(image, r - 1, c, oldColor, newColor);
        dfs(image, r, c + 1, oldColor, newColor);
        dfs(image, r, c - 1, oldColor, newColor);
    }
private:
    int n_rows;
    int n_cols;
};