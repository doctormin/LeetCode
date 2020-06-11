# https://leetcode.com/problems/search-insert-position/
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        return self.binarySearch(nums, target, 0, len(nums) - 1)
    
    def binarySearch(self, nums, target, left, right):
        if left == right:
            if nums[left] == target:
                return left
            elif nums[left] < target:
                return left + 1
            else:
                return left
        mid = (left + right) // 2
        if nums[mid] >= target:
            return self.binarySearch(nums, target, left, mid)
        else:
            return self.binarySearch(nums, target, mid + 1, right)