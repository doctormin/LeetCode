# https://leetcode.com/problems/two-sum/
'''
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
'''

'''
算法思路：
    hash table (使用dict解决数据范围未知的问题)
    hash表的index表示当前nums遍历到的index, value为目标的配对值

    这里有个比较妙的处理手法，因为dict不是multiset但是num有可能 = target - num，
    所以采用了每次扫到i就搜索的手法，这样nums[i]不会与被搜索值冲突
'''
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        for i, num in enumerate(nums):
            try:
                return [dict[target - num], i]
            except:
                dict[num] = i
