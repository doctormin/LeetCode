# https://leetcode.com/problems/single-element-in-a-sorted-array/

# O(n) solution - Stack
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        stack = []
        if len(nums) == 1:
            return nums[0]
        for each in nums:
            if len(stack) == 0:
                stack.append(each)
            else:
                tmp = stack.pop()
                if tmp != each:
                    return tmp
        return stack[0]

# O(logn) solution - Binary Search
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        return self.binarySearch(nums, 0, len(nums) - 1)
    def binarySearch(self, nums, left, right) -> int:
        print("(", left, ", ", right, ")")
        if left >= right:
            return nums[left]
        mid = int((left + right) / 2)
        if ((right - left)/2)%2 == 0:
            if nums[mid] == nums[mid + 1]:
                print("case 1-1")
                return self.binarySearch(nums, mid + 2, right)
            elif nums[mid] == nums[mid - 1]:
                print("case 1-2")
                return self.binarySearch(nums, left, mid - 2)
            else: 
                print("case 1-3")
                return nums[mid]
        else:
            if nums[mid] == nums[mid + 1]:
                print("case 2-1")
                return self.binarySearch(nums, left, mid - 1)
            if nums[mid] == nums[mid - 1]:
                print("case 2-2")
                return self.binarySearch(nums, mid + 1, right)



