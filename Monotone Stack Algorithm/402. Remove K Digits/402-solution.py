# https://leetcode.com/problems/remove-k-digits/
'''
算法思路：
使用贪婪法，确保每次删除都是局部最优，可以证明全局最优（此处略）
    局部最优策略：从左向右扫描，找到第一个极大值digit，删去即可
'''
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        length = len(nums)
        choose = [1 for i in range(length)]
        if length == 0:
            return 0
        cur : int = 0
        while True:
            
                
            

        