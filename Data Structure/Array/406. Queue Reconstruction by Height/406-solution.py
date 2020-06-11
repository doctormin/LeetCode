# https://leetcode.com/problems/queue-reconstruction-by-height/
'''
每次都对确定最矮的人的位置，归纳即可
'''
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort()
        ans = [[] for i in range(0, len(people))]
        for each in people:
            pos = each[1]
            count = -1
            for i in range(0, len(ans)):
                if ans[i] == [] or ans[i][0] >= each[0]:
                    count += 1
                    if count == pos:
                        ans[i] = each
        return ans


'''
也可每次确定最高的人的位置，这样更方便
'''
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people = sorted(people, key = lambda x:(-x[0],x[1]))
        print(people)
        output = []
        for p in people:
            output.insert(p[1], p)
            print(output)
        return output

'''
测试结果：
Your input
[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Your stdout
[[7, 0], [7, 1], [6, 1], [5, 0], [5, 2], [4, 4]]
[[7, 0]]
[[7, 0], [7, 1]]
[[7, 0], [6, 1], [7, 1]]
[[5, 0], [7, 0], [6, 1], [7, 1]]
[[5, 0], [7, 0], [5, 2], [6, 1], [7, 1]]
[[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]

Your answer
[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Expected answer
[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
'''
