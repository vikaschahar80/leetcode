#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000000; // Maximum value for input integers
vector<int> divisor_count(MAXN + 1, 0);

void precompute_divisors() {
    // Using a modified Sieve of Eratosthenes to count divisors
    for (int i = 1; i <= MAXN; ++i) {
        for (int j = i; j <= MAXN; j += i) {
            divisor_count[j]++;
        }
    }
}

int main() {
    precompute_divisors(); // Precompute the number of divisors for every integer up to MAXN
    
    int n;
    cin >> n;
    
    vector<int> results;
    results.reserve(n);
    
    while (n--) {
        int x;
        cin >> x;
        results.push_back(divisor_count[x]);
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
