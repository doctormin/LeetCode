# https://leetcode.com/problems/power-of-two/
'''
    判断n是否是2的幂
'''
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 0:
            return False
        while n != 1:
            if n % 2 != 0:
                return False
            n = n // 2
        return True