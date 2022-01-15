class Solution {
public:
    vector<vector<int>> pascal;

    vector<int> getVector(vector<int> vec, vector<int> preVec, int i) {
        // i starts from 2 and goes till the previous vector length of the triangle
        if (i == preVec.size()) {
            return vec;
        }
        vec[i] = preVec[i - 1] + preVec[i];
        return getVector(vec, preVec, ++i);
    }
    vector<vector<int>> makeTriangle(int made, int n_rols) {
        if (made == n_rols) {
            return pascal;
        }
        // initializing the first and last elements of the vector to be added
        vector<int> vec(made + 1, 0);
        vec[0] = 1;
        vec[made] = 1;

        // gets the vector
        pascal.push_back(getVector(vec, pascal[made - 1], 1));
        return makeTriangle(++made, n_rols);
    }
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return pascal;
        }
        else if (numRows == 1) {
            return { {1} };
        }
        else if (numRows == 2) {
            return { {1},{1,1} };
        }
        pascal = { {1},{1,1} };   // Now that the triangle definitely has more than 2 rows
        return makeTriangle(2, numRows);
    }
};