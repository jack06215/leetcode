class Solution {
public:
    void reverseString(vector<char>& s) {
        function<void(int, int)> _reverseString = [&](int left, int right) {
            if (left >= right) {
                return;
            }
            swap(s[left], s[right]);
            _reverseString(left + 1, right - 1);
        };
        _reverseString(0, s.size() - 1);
    }
};