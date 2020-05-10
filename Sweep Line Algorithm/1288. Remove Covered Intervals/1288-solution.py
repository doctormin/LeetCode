# This file is buggy


import heapq
import functools
class Solution:
    def removeCoveredIntervals(self, intervals) -> int:
        length = len(intervals)
        delete_num = 0
        points = [] 
        # 对于进入点：
        # x越大越靠后，若x相等，对应的离开点x越小越靠后
        # 对于离开点：
        # x越大越靠后，若x相等，对应的进入点x越小越靠后
        process_heap = [] # 一个最小堆，记录所有已扫描过的左端点（同时右端点还没扫描到）
        id = 0
        for each in intervals:
            points.append([each[0], 1, id, each[1]])
            points.append([each[1], -1, id, each[0]])
            id += 1
        def compare(A , B):
            if A[0] < B[0]:
                return -1
            elif A[0] > B[0]:
                return 1
            else:
                if A[1] == 1 and B[1] == -1:
                    return -1
                elif A[1] == -1 and B[1] == 1:
                    return 1
                elif A[1] == 1 and B[1] == 1:
                    if A[3] < B[3]:
                        return 1
                    else:
                        return -1
                else:
                    if A[3] < B[3]:
                        return 1
                    else:
                        return -1

        points.sort(key=functools.cmp_to_key(compare))
        for point in points:
            if point[1] == 1: # entering 
                #print(point, " entering !")
                heapq.heappush(process_heap, point)
            else: # leaving 
                # 检查是否被包含，即检查对应的左节点的左边是不是还有点
                if process_heap[0][2] == point[2]: # 最左边的点的确是对应的左端点
                    #print(point, " leaving 1, now the left most one is ", process_heap[0])
                    heapq.heappop(process_heap)
                else:
                    # 这个集合被包含了，要在计数时删去
                    #print(point, " leaving 2, now the left most one is ", process_heap[0])
                    delete_num += 1
                    # 从process_heap中删去左节点
                    counter = 0
                    for each in process_heap:
                        if each[2] == point[2]:
                            del process_heap[counter]
                            heapq.heapify(process_heap)
                        counter += 1
        return (length - delete_num)
        

if __name__ == "__main__":
    x = Solution()
    print(x.removeCoveredIntervals([[1,4],[1,6],[1,5]]))




