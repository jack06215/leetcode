class Solution {
public:
    int trap(vector<int>& heights) {
        if (heights.empty()) return 0; 
        int res = 0;

        stack<int> stk;   
        for(int i = 0; i < heights.size(); i++) {
			// 
            while (!stk.empty() && heights[i] > heights[stk.top()]) {
                // we have a concave area
				int concaveIdx = stk.top();
				stk.pop();
                
				// we have left
                if (!stk.empty()) {
					int leftIdx = stk.top();
					int width = i - leftIdx - 1;
					int height = min(heights[i], heights[leftIdx]) - heights[concaveIdx];
					res += height * width;
				}
            }
            stk.push(i);
        }
        return res;
    }
};