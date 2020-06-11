#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int bits = 0;
        unsigned tmp = num;
        while(num != 0){
            num >>= 1;
            bits++;
        }
        tmp <<= (32 - bits);
        unsigned reverse = ~tmp;
        reverse >>= (32-bits);
        return reverse;
    }
};

int main()
{
    Solution s;
    cout << s.findComplement(1);
}