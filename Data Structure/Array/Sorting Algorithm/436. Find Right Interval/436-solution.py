# https://leetcode.com/problems/find-right-interval/
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        count = 0
        array = []
        ans = [0] * len(intervals)
        # 制作三元组 [坐标，左/右，编号]
        for i in intervals:
            array.append([i[0], 1, count])
            array.append([i[1], 0, count])
            count += 1
        array.sort(key=lambda x : (x[0], x[1]))
        print(array)
        stack = []
        for i in array:
            #是左括号
            if i[1] == 1:
                while stack != []:
                    j = stack.pop()
                    ans[j[2]] = i[2]
            #是右括号
            else:
                stack.append(i)
        while stack != []:
            j = stack.pop()
            ans[j[2]] = -1
        return ans