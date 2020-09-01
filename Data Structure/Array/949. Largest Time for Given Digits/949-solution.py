#https://leetcode.com/problems/largest-time-for-given-digits/
import itertools
class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        ans = ""
        for i in itertools.permutations(A):   
            if i[0]*10 + i[1] <= 23 and i[2] <= 5:
                ans = max(ans, str(i[0])+str(i[1])+":"+str(i[2])+str(i[3]))
        return ans
