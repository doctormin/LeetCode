#https://leetcode.com/problems/the-skyline-problem/

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        length = len(buildings)
        if length == 2:
            prev = buildings[0]
            tail = buildings[1]
            answer = []
            if prev[1] < tail[0]: #两个根本不重叠
                answer.append([prev[0], prev[2]])
                answer.append([prev[1] ,0])
                answer.append([tail[0], tail[2]])
                answer.append([tail[1], 0])
                return answer
            elif prev[1] >= tail[1]:
                if prev[2] >= tail[2]:
                    answer.append([prev[0], prev[2]])
                    answer.append([prev[1], 0])
                    return answer
                else:
                    answer.append([prev[0], prev[2]])
                    answer.append([tail[0], tail[2]])
                    if prev[1] != tail[1]:
                        answer.append([tail[1], prev[2]])
                    answer.append([prev[1], 0])
                    return answer
            else:
                answer.append([prev[0], prev[2]])
                if prev[2] > tail[2]:
                    answer.append([prev[1], tail[2]])
                elif prev[2] < tail[2]:
                    answer.append([tail[0], tail[2]])
                else:
                    pass
                answer.append([tail[1], 0])
                return answer
        else:
            list1 = self.getSkyline(buildings[0:int (length/2)])
            list2 = self.getSkyline(buildings[int (length/2+1):])
            return merge(list1, list2)
    def merge(self, prev: List[List[int]], tail: List[List[int]])-> List[List[int]]:
        list = prev + tail
        new_prev = []
        new_tail = []
        for each in prev:
            new_prev.append[each[0], each[1], 1]
        for each in tail:
            new_tail.append[each[0], each[1], -1]
        list = new_prev + new_tail
        list.sort()
        prev_height = 0
        tail_height = 0
        answer = []
        for each in list:
            if each[2] == 1: # 是前一个轮廓的点
                prev_height = each[1]
                if prev_height > tail_height:
                    answer.append([each[0], each[1]])
            if each[2] == -1: # 是后一个轮廓的点
                tail_height = each[1]
                if tail_height > prev_height:
                    answer.append([each[0], each[1]])