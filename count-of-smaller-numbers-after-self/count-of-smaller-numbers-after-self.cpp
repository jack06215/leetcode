class FenwickTree{
public:
    FenwickTree(int n): bit(n + 1, 0) {}
    
    void update(int i, int val) {
        while (i < bit.size()) {
            bit[i] = bit[i] + val;
            i = i + lowbit(i);
        }
    }
    
    int get(int i) {
        int ans = 0;
        while (i > 0) {
            ans = ans + bit[i];
            i = i - lowbit(i);
        }
        return ans;
    }
private:
    static inline int lowbit(int x) {
        return x & (-x);
    }
    vector<int> bit;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        int mn= *min_element(nums.begin(), nums.end());
        int mx= *max_element(nums.begin(), nums.end());
        
        // to make every element positive, and 1-indexed
        FenwickTree tree(mx - mn + 1);
        
        vector<int> cnt(n);
        for(int i = n - 1; i >= 0; i--) {
            
            // we want only smaller so subtract m[nums[i]] (count of current element)
            cnt[i] = tree.get(nums[i] - mn);
            
            // update fenwick tree (increase freq of element by 1)
            tree.update(nums[i] - mn + 1, 1);
        }
        return cnt;
    }
};