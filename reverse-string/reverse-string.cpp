class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() == 1) return;
        int head = 0;
        int tail = s.size() - 1;
        while (head < tail) {
            swap(s[head++], s[tail--]);
        }
    }
};