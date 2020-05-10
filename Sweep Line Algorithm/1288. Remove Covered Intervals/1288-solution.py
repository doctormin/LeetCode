import heapq
import functools
class Solution:
    def removeCoveredIntervals(self, intervals) -> int:
        delete_num = 0
        points = [] 
        # 对于进入点：
        # x越大越靠后，若x相等，对应的离开点x越小越靠后
        # 对于离开点：
        # x越大越靠后，若x相等，对应的进入点x越小越靠后
        id = 0
        for each in intervals:
            points.append([each[0], 1, id, each[1], 0])
            points.append([each[1], -1, id, each[0], 0])
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
                else:
                    if A[3] < B[3]:
                        return 1
                    else:
                        return -1
                        
        points.sort(key=functools.cmp_to_key(compare))
        ptr = 0
        for point in points:
            if point[1] == -1: # leaving point
                while(points[ptr][4] == 1):
                    ptr += 1
                if points[ptr][2] == point[2]: # 最左边的点的确是对应的左端点
                    #print(point, " leaving 1, now the left most one is ", points[0])
                    points[ptr][4] = 1 # 删去左端点
                    point[4] = 1 # 删去右端点
                else:
                    # 这个集合被包含了，要在计数时删去
                    #print(point, " leaving 2, now the left most one is ", points[0])
                    delete_num += 1
                    point[4] = 1
                    counter = 0
                    for each in points:
                        if each[2] == point[2]:
                            #print("del ", points[counter])
                            points[counter][4] = 1
                        counter += 1
        return (len(intervals) - delete_num)
        

if __name__ == "__main__":
    x = Solution()
    print(x.removeCoveredIntervals([[1,4],[1,6],[1,5]]))




