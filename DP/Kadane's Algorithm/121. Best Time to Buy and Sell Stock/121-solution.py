# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
'''
使用Kadane's Algorithm, （本质接近动态规划，因为使用了最优子结构）
时间O(n), 空间O(1)

可以看成求max sub-array的问题, 因为股价序列相当于利润序列
比如：已知股价序列[7,1,5,3,6,4]
那么利润序列就是[-6, 4, 2, 3, 2]
求最大销售利润等价于求利润序列的max sub-array

定义两个变量:
@localMax : 以当前下标元素为结尾的最大sub-array的和
@Max :  遍历过程中localMax的最大值

算法过程是将序列从头到尾遍历一次，维护localMax和Max:
（此处num[i]表示利润序列的第i个，即股价序列的i+1个减去i个的差值
localMax = max{nums[i], localMax + nums[i]} (即要么把前面都甩掉，要么都留着)
Max = max{localMax, Max}
'''
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0
        localMax = prices[1] - prices[0]
        Max = localMax
        for i in range(2, len(prices)):
            localMax = max(prices[i] - prices[i-1], localMax + prices[i] - prices[i-1])
            Max = max(localMax, Max)
        return max(Max, 0)
            