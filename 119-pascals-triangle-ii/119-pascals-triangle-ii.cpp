class Solution {
public:
    vector<int> getRow(int row) {

        if (row == 0) {
            return { 1 };
        }
        vector<int> temp = getRow(row - 1);
        const int n = temp.size();

        vector<int> res(n + 1);
        for (int i = 0; i < n + 1; i++) {
            // add
            if (i - 1 >= 0 && i < n) {
                res[i] = temp[i - 1] + temp[i];
            }
            // last element
            else {
                res[i] = 1;
            }
        }

        return res;
    }
};