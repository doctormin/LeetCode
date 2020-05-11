//https://leetcode.com/problems/count-primes/
/*
 * Implemented with seive of Euler
 * Time complexity is O(n)
 */
#include <iostream>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        bool isPrime[n];
        int Prime[n];
        for(int i = 2; i <= n-1; i++)
            isPrime[i] = 1; 
        int count = 0;
        for(int i = 2; i <= n-1; i++){
            if(isPrime[i])
                Prime[++count] = i;
            for(int j = 1; i*Prime[j] < n and j <= count; j++){
                isPrime[i*Prime[j]] = 0;
                if(i%Prime[j] == 0)
                    break;
            }
        }
        return count;
    }
};

int main(){
    auto s = Solution();
    s.countPrimes(10);
}