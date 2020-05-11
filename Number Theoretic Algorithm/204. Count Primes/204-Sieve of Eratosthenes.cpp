//https://leetcode.com/problems/count-primes/
/*
 * Implemented with seive of Eratosthenes
 * Time complexity is O(nloglogn)
 */
#include <vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1)
            return 0;
        vector<int> isPrime(n + 1, 1); //vector<bool> is toooooo slow 
        for(int i = 2; i * i < n; i++){
            if(!isPrime[i])
                continue;
            for(int j = i * i; j < n; j += i){
                isPrime[j] = 0;
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++){
            if(isPrime[i])
                ++count;
        }
        return count;
    }
};