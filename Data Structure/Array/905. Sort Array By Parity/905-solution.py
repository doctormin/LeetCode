#https://leetcode.com/problems/sort-array-by-parity/
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        odd = []
        even = []
        for i in A:
            if i % 2 == 0:
                even.append(i)
            else:
                odd.append(i)
        even += odd
        return even
