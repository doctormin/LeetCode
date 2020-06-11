# https://leetcode.com/problems/rectangle-overlap/
class Solution:
    def isRectangleOverlap(self, rec1: list[int], rec2: list[int]) -> bool:
        Ax = rec1[0]
        Ay = rec1[1]
        Bx = rec1[2]
        By = rec1[3]
        Cx = rec2[0]
        Cy = rec2[1]
        Dx = rec2[2]
        Dy = rec2[3]
        return not (Cx >= Bx or Cy >= By or Dy <= Ay or Ax >= Dx)
