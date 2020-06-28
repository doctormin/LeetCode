#https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # in-place 
        nums[:] = [nums[i] for i in range(0, len(nums)) if (i == len(nums)-1) or (nums[i] != nums[i+1])]
        return len(nums)