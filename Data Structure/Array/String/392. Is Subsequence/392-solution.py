# https://leetcode.com/problems/is-subsequence/
'''
Given a string s and a string t, check if s is subsequence of t.
简单的子序列匹配问题，时间复杂度O(m + n)
'''

# for loop
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        m = len(s)
        if m == 0:
            return True
        n = len(t)
        if n == 0:
            return False
        p = 0
        for i in range(0, m):
            if p == n:
                return False
            if s[i] == t[p]:
                #print(f"s[{i}] == t[{p}]")
                i += 1
                p += 1
            else:
                while s[i] != t[p]:
                    #print(f"s[{i}] != t[{p}]")
                    p += 1
                    if p == n:
                        return False
                #print(f"s[{i}] == t[{p}]")
                p += 1
                i += 1
        return True


# 双指针法 更容易写出来
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        m = len(s)
        if m == 0:
            return True
        n = len(t)
        if n == 0:
            return False
        ps = 0
        pt = 0
        while True:
            if ps == m:
                return True
            if pt == n:
                return False
            if s[ps] == t[pt]:
                ps += 1
                pt += 1
            else:
                while s[ps] != t[pt]:
                    pt += 1
                    if pt == n:
                        return False
                pt += 1
                ps += 1