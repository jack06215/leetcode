class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // dictionary to keep the counting of prefix sum (running sum)
        // running sum = 0 when nothing is added, i.e. {0, 1}
        unordered_map<int, int> mp{{0, 1}};
        int res{0}, sum{0};
        for (const auto& num: nums) {
            // running sum
            sum += num;
            // if sum - k exists, add it up
            if(mp.count(sum - k)) {
                res += mp[sum - k]; 
            }
            // then we update current running sum counter by 1
            mp[sum]++;
        }
        return res;   
    }
};