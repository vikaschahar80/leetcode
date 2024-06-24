class Solution {
private:
    static const int MOD = 1000003;

    // Function to compute factorial modulo MOD
    long long factorial(long long m) {
        long long result = 1;
        for (long long i = 2; i <= m; i++) {
            result = (result * i) % MOD;
        }
        return result;
    }

    // Function to compute modular exponentiation
    long long mod_exp(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    // Function to compute modular inverse using Fermat's Little Theorem
    long long mod_inverse(long long a, long long mod) {
        return mod_exp(a, mod - 2, mod);
    }

public:
    int nCr(long long n, long long r) {
        if (r > n || r < 0) {
            return 0;
        }
        long long numerator = factorial(n);
        long long denominator = (factorial(r) * factorial(n - r)) % MOD;
        return (numerator * mod_inverse(denominator, MOD)) % MOD;
    }
};
