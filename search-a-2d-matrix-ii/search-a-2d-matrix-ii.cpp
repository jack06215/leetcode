class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        return _searchMatrix(matrix, 0, rows - 1, 0, cols - 1, target);
    }
private:
    bool _searchMatrix(vector<vector<int>>& matrix, int startRow, int endRow, int startCol, int endCol, int target) {
        // base case
        if (startRow > endRow || startCol > endCol) {
            return false;
        }
        // find middle of the matrix
        const int middleRow = ((endRow - startRow) / 2) + startRow;
        const int middleCol = ((endCol - startCol) / 2) + startCol;

        // if we found the target we solve the problem, so return true  
        if (matrix[middleRow][middleCol] == target) {
            return true;
        }

        // it is the "devide" step, basically, we define the recurrence relation for the recursion function.
        if (matrix[middleRow][middleCol] < target) {
            // let m - is our middle point.
            // if m less than the target than all points before m also less tha target (marked by x)
            // so we only need look through cells marked by 1 and 2
            // x x x 2 2
            // x x x 2 2
            // x x m 2 2
            // 1 1 1 1 1
            // 1 1 1 1 1
            return _searchMatrix(matrix, middleRow + 1, endRow, startCol, endCol, target) ||
                _searchMatrix(matrix, startRow, middleRow, middleCol + 1, endCol, target);
        }
        else {
            // let m - is our middle point.
            // if m more than the target than all points after m also bigger than the target (marked by x)
            // so we only need look through cells marked by 1 and 2
            // 1 1 2 2 2
            // 1 1 2 2 2
            // 1 1 m x x
            // 1 1 x x x
            // 1 1 x x x
            return _searchMatrix(matrix, startRow, endRow, startCol, middleCol - 1, target) ||
                _searchMatrix(matrix, startRow, middleRow - 1, middleCol, endCol, target);
        }
    }
};