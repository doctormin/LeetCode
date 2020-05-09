class Solution:
    def checkStraightLine(self, coordinates) -> bool:
        length = len(coordinates)
        if length == 2:
            return True
        flag = False
        x : int = 0
        y : int = 0
        if coordinates[0][0] == coordinates[1][0]:
            flag = True
        else:
            y = (coordinates[1][1] - coordinates[0][1])
            #print("y = ", y)
            x = (coordinates[1][0] - coordinates[0][0])
            #print("x = ", x)
        for i in range(2, length - 1):
            if flag:
                if coordinates[i][0] != coordinates[0][0]:
                    return False
            else:
                _y = (coordinates[i][1] - coordinates[0][1])
                #print("_y = ", _y)
                _x = (coordinates[i][0] - coordinates[0][0])
                #print("_x = ", _x)
                if (_y * x != _x * y):
                    return False
        return True     
        
if __name__ == "__main__":
    x = Solution()
    print(x.checkStraightLine([[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]))