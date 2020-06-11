# https://leetcode.com/problems/longest-increasing-subsequence/
'''
著名的最长子序列问题 --- LIS
使用数归的思想 可以做到 O(nlogn)  (原数列长度为n)

算法思路：
 ->归纳假设，对于任意 k < n 知道如何 BIS(k) (if exists)
   BIS(K) 指 best incresing subusequence whose length is k 
   何谓best ? 即所有的长度为 k 的 LIS 中末尾最小的即是 BIS(k)

   遍历原序列，假设当前处理的元素是xm
   那么xm可以加长BIS(k)(即BIS(k) + xm = BIS(k+1))的充分必要条件是
        (1) xm > BIS(k).tail()           //才有可能加进来
        (2) xm <= BIS(k+1).tail()         //这样加长之后得到的新的才是BIS(k+1)
'''

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        //TODO：