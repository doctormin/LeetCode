# https://leetcode.com/problems/reverse-string/
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        prev = 0
        tail = len(s) - 1
        while prev < tail:
            s[prev], s[tail] = s[tail], s[prev]
            prev += 1
            tail -= 1
        