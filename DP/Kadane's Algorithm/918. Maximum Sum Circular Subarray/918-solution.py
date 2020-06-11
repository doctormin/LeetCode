# https://leetcode.com/problems/maximum-sum-circular-subarray/
'''
使用Kadane's Algorithm, （本质接近动态规划，因为使用了最优子结构）
时间O(n), 空间O(1)

定义两个变量:
@localMax : 以当前下标元素为结尾的最大subarray的和
@Max :  遍历过程中localMax的最大值

因为现在考虑的是首尾相接的循环数组，所以有两种情况：
case1: 和传统的max subarray问题一样
case2: subarray的分布跨越了nums[len(nums) - 1]，循环了过来

对于case1, 传统的kadane's algorithm足矣
对于case2, 反转思路，求原数列的min subarray, 然后用sum - min 得到的就是case2中的max subarray, 但是要注意min subarray的元素选取完全等于array的特殊情况

Kadane's algorithm过程是将序列从头到尾遍历一次，维护localMax和Max:
localMax = max{nums[i], localMax + nums[i]} (即要么把前面都甩掉，要么都留着)
Max = max{localMax, Max}

特殊情况：有时min subarray就是array, 此时min = Sum
那么假设我们只要min = Sum就输出max会伤及无辜吗
case1 : min = Sum && min subarray = array: 输出max是对的
case2 : min = Sum && min subarray != array : 此时max >= 0 >= Sum - Min, 也是对的
'''
class Solution:
    def maxSubarraySumCircular(self, A: List[int]) -> int:
        localMax = A[0] #[最大值， 最大subarray的起始元素的Index]
        localMin = A[0]
        Sum = A[0]
        Min = localMin
        Max = localMax
        for each in A[1:]:
            localMax = max(each, localMax + each)
            Max = max(Max, localMax)
            localMin = min(each, localMin + each)
            Min = min(Min, localMin)
            Sum += each
        if Sum  == Min:  
            return Max
        else:
            return max(Max, Sum - Min)
        
            