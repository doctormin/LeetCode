# https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/
# Way 1 : intuitive way 
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i = 1
        while(num > 0):
            num -= i
            i += 2
        return num == 0

# Way 2 : binary search  😁FASTER ！
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        return self.binarySearch(0, num, num)
    def binarySearch(self, left, right, num) -> bool:
        mid = (left + right) // 2
        if mid * mid == num:
            return True
        if left >= right:
            return False
        if mid * mid < num:
            return self.binarySearch(mid + 1, right, num)
        else:
            return self.binarySearch(left, mid - 1, num)