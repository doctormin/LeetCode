# https://leetcode.com/problems/sort-an-array/

'''
当然可以直接
    ```
    nums.sort()
    return nums
    ```
但是为了练手，这里使用mergeSort实现
'''
from typing import List
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        if len(nums) == 1:
            return nums
        mid = len(nums) // 2
        #print(nums[:mid])
        #print(nums[mid:])
        left = self.sortArray(nums[:mid])
        right = self.sortArray(nums[mid:])
        return self.merge(left, right)

    def merge(self, A, B) -> List[int]:
        p1 = 0
        p2 = 0
        ans = []
        while True:
            if A[p1] <= B[p2]:
                ans.append(A[p1])
                p1 += 1
                if p1 == len(A):
                    ans += B[p2 :]
                    break
            else:
                ans.append(B[p2])
                p2 += 1
                if p2 == len(B):
                    ans += A[p1:]
                    break
        #print(f"A = {A}, B = {B},  ans = {ans}")
        return ans