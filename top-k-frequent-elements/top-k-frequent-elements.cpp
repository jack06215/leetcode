class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]]++;
        }
        vector<int> res;
        priority_queue<pair<int, int>> pq; 
        for(auto it = map.begin(); it != map.end(); it++) {
          pq.push(make_pair(it->second, it->first));
          if(pq.size() > map.size() - k) {
              res.push_back(pq.top().second);
              pq.pop();
          }
        }
        return res;
    }
};