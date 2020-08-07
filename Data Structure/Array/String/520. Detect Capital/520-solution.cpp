// https://leetcode.com/problems/detect-capital/
#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap_count = count_if(word.begin(), word.end(), [] (char c) {return c <= 'Z';});
        return cap_count == 0 or cap_count == word.size() or (cap_count == 1 and word[0] <= 'Z');
    }
};