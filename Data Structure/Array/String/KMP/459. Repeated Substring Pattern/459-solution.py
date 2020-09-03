#https://leetcode.com/problems/repeated-substring-pattern/
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        s += '*'
        s = '*' + s
        print(s)
        l = len(s)
        next = [0]*l
        next[1] = -1
        next[2] = 0
        for i in range(2, l):
            j = next[i-1] + 1
            while s[i-1] != s[j] and j > 0:
                j = next[j] + 1
            next[i] = j
        return next[l-1] != 0 and (l-1) % ((l-1) - next[l-1]) == 0