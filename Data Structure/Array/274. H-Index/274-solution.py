#https://leetcode.com/problems/h-index/
'''
计算H-index, 只需要把所有的论文的引用量按照从高到低排列，然后比较数字和index, 因为index单增
数字单减，所以必然在某个index处(i)有index > 引用量，那么至少有(i-1)篇论文被引用了至少i-1次
'''
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        #首先将citations按照降序排序
        citations.sort(reverse=True)
        h_index = 0
        for index, item in enumerate(citations):
            if index + 1 <= item:
                h_index += 1
        return h_index