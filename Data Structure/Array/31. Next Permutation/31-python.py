# https://leetcode.com/problems/next-permutation/
'''
我们通过观察原数组可以发现，如果从末尾往前看，数字逐渐变大，
到了2时才减小的，然后再从后往前找第一个比2大的数字，是3，
那么我们交换2和3，再把此时3后面的所有数字转置一下即可，步骤如下：

1　　|2|　　7　　4　　|3|　　1

1　　|3|　　7　　4　　|2|　　1

1　　|3|　　1　　2　　4　　7
'''
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        lastInc = None
        for i in range(len(nums)-1, -1, -1):
            if i == 0:
                break
            if nums[i] > nums[i-1]:
                lastInc = i
                break
        
        #此时已是最大（递减顺序的序列）
        if not lastInc:
            nums[:] = reversed(nums)
            return
        
        #从后向前找到第一个比lastInc大的数
        cur = len(nums) - 1
        while nums[lastInc-1] >= nums[cur]:
            cur -= 1

        # swap
        nums[lastInc-1], nums[cur] = nums[cur], nums[lastInc-1]
        
        # reverse (essentially sort) the rest
        nums[lastInc:] = reversed(nums[lastInc:])