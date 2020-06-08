# https://leetcode.com/problems/reverse-integer/
class Solution:
    def reverse(self, x: int) -> int:
        a = x if x >= 0 else (-1 * x)
        l = list(str(a))
        #print(l)
        l.reverse()
        n = ''.join(l)
        num =  int(n) if a == x else -1 * (int(n))
        return num if num < 2**31 and num >= -1 * (2**31) else 0