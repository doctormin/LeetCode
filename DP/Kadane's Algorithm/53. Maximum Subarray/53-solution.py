# https://leetcode.com/problems/maximum-subarray/
'''
使用Kadane's Algorithm, （本质接近动态规划，因为使用了最优子结构）
时间O(n), 空间O(1)

定义两个变量:
@localMax : 以当前下标元素为结尾的最大subarray的和
@Max :  遍历过程中localMax的最大值

算法过程是将序列从头到尾遍历一次，维护localMax和Max:
localMax = max{nums[i], localMax + nums[i]} (即要么把前面都甩掉，要么都留着)
Max = max{localMax, Max}
'''

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        localMax = nums[0]
        Max = nums[0]
        for each in nums[1:]:
            localMax = max(each, localMax + each)
            Max = max(Max, localMax)
        return Max