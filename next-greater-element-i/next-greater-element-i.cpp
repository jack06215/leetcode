class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    unordered_map<int, int> next;
    for (int num2 : nums2) {
      while (!s.empty() && num2 > s.top()) {
        next[s.top()] = num2;
        s.pop();
      }
      s.push(num2);
    }
    vector<int> ans;
    for (int num : nums1)
      ans.push_back(next.count(num) ? next[num] : -1);
    return ans;
  }
};