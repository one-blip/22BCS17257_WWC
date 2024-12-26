#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int minNonZeroProduct(int p) {
        long long maxNum = (1LL << p) - 1;
        long long product = 1;
        
        // Count the total number of 1-bits
        for (long long i = 1; i < maxNum; i++) {
            product = (product * i) % MOD;
        }
        
        return (product * (maxNum - 1)) % MOD;
    }
};
