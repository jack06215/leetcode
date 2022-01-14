class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels = "aeiou";
        int count = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            // if any vowel is inserted from right-> increment
            if (vowels.find(s[i]) != string::npos) {
                count++;
                
            }
            // move sliding window, and if any vowel is removed from left-> decrement
            if (i >= k && vowels.find(s[i - k]) != string::npos) {
                count--;
            }
            res = max(res, count);
        }
        return res;
    }
};