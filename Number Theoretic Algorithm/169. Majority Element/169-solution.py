class Solution:
    def majorityElement(self, nums) -> int:
        nums.sort()
        return nums[len(nums)//2]

if __name__ == "__main__":
    x = Solution()
    print(x.majorityElement([1,2,2,1,3,2]))