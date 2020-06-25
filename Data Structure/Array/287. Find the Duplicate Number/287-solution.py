#https://leetcode.com/problems/find-the-duplicate-number/
'''
算法思路：使用计数排序，时间复杂度O(n+n) = O(n)
'''
from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        L = len(nums) #长度为n+1, 数据范围为[1,n]
        C = [0]*L #计数数组
        for each in nums:
            C[each] += 1
        for i, each in enumerate(C):
            if each > 1:
                return i