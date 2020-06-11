#https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/
class Solution:
    def findJudge(self, N: int, trust) -> int:
        answer = [[None, None, None]]
        for i in range(1, N + 1):
            answer.append([i, False, 0])
        for each in trust:
            self_id = each[0]
            trusted_id = each[1]
            answer[self_id][1] = True
            answer[trusted_id][2] += 1
        for each in answer:
            if each == [None, None, None]:
                continue
            if each[1] == False and each[2] == N - 1:
                return each[0]
        return -1
if __name__ == '__main__':
    x = Solution()
    print(x.findJudge(2, [[1,2]]))