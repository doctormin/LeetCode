# https://leetcode.com/problems/powx-n/
# 题目要求计算x^n
# 使用快速幂，时间复杂度为O(logn)
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n > 0:
            return self.Pow(x, n)
        else:
            return self.Pow(1/x, -n)
    def Pow(self, x: float, n: int) -> float:
        if n % 2 == 0:
            if n == 2:
                return x * x
            result = self.Pow(x, n/2)
            return pow(result, 2)
        else:
            if n == 1:
                return x
            result = self.Pow(x, (n-1)/2)
            return x * pow(result, 2)