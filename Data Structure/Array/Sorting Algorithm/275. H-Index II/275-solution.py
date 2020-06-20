#https://leetcode.com/problems/h-index-ii/
'''
找到第一个value <= n - index的
'''
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        return self.binarySearch(citations, 0, len(citations)-1)
    def binarySearch(self, A, left, right):
        if left >= right:
            return left
        mid = (left + right) // 2
        index = len(A) - mid
        if A[mid] > index:
            return self.binarySearch(A, left, mid)
        else:
            return self.binarySearch(A, mid, right)