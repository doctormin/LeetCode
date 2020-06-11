#https://leetcode.com/problems/contiguous-array/

'''
算法思路：
    https://leetcode.com/problems/contiguous-array/discuss/653541/Python-HashMap-solution-%2B-Thinking-Process-Diagram
'''

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        if not nums or len(nums) == 0:
            return 0
        count = 0
        result = 0
        dic = {0:-1}
        for i in range(0, len(nums)):
            count += 1 if nums[i] == 1 else -1
            if count in dic:
                result = max(result, i - dic[count])
            else:
                dic[count] = i
        return result