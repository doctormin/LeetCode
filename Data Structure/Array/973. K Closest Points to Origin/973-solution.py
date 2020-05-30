# https://leetcode.com/problems/k-closest-points-to-origin/

class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        sorted = []
        ans    = []
        for i in range(0, len(points)):
            x = points[i][0]
            y = points[i][1]
            sorted.append([x**2 + y**2, i])
        sorted.sort()
        for i in range(0, K):
            ans.append(points[sorted[i][1]])
        return ans
