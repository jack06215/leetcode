class Solution {
public:
    long long modpow(long long base, long long exp, long long modulus){
        long long x = 1;
        long long y = base; 
        while (exp > 0) {
            if (exp%2 == 1) {
                x = (x*y) % modulus; // multiplying with base
            }
            y = (y*y) % modulus; // squaring the base
            exp /= 2;
        }
        return x % modulus;
    }
    
    long long countGoodNumbers(long long n) {
        // 5 possibles for even digit, 4 possibles odd digit
        long long even = modpow(5, (n + 1) / 2, 1000000007);
        long long odd = modpow(4, n / 2, 1000000007);
        cout << even << " " << odd << endl;
        long long ans = (even * odd) % 1000000007;
        return ans;
        
        
    }
};