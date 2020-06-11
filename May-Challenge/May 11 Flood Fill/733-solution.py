# https://leetcode.com/problems/flood-fill/
'''
# first try -- failed --- stack overflow 
class Solution:
    def floodFill(self, image, sr: int, sc: int, newColor: int):
        old_color = image[sr][sc]
        x_len = len(image)
        y_len = len(image[0])
        image[sr][sc] = newColor
        if sr < x_len - 1:
            if image[sr + 1][sc] == old_color:
                self.floodFill(image, sr + 1, sc, newColor)
        if sr > 0:
            if image[sr - 1][sc] == old_color:
                self.floodFill(image, sr - 1, sc, newColor)
        if sc < y_len - 1:
            if image[sr][sc + 1] == old_color:
                self.floodFill(image, sr, sc + 1, newColor)
        if sc > 0:
            if image[sr][sc - 1] == old_color:
                self.floodFill(image, sr, sc - 1, newColor)
        return image
'''

# second try --- BFS
import queue
class Solution:
    def floodFill(self, image, sr: int, sc: int, newColor: int):
        q = queue.Queue()
        x_len = len(image)
        y_len = len(image[0])
        old_color = image[sr][sc]
        isChosen = [[0 for i in range(y_len)] for j in range(x_len)]
        q.put((sr, sc))
        isChosen[sr][sc] = 1
        while not q.empty():
            node = q.get()
            x = node[0]
            y = node[1]
            image[x][y] = newColor
            if x != x_len - 1:
                if image[x + 1][y] == old_color  and not isChosen[x + 1][y]:
                    q.put((x + 1, y)) 
                    isChosen[x + 1][y] = 1
            if x != 0:
                if image[x - 1][y] == old_color and not isChosen[x - 1][y]:
                    q.put((x - 1, y))
                    isChosen[x - 1][y] = 1
            if y != y_len - 1:
                if image[x][y + 1] == old_color and not isChosen[x][y + 1]:
                    q.put((x, y + 1))
                    isChosen[x][y + 1] = 1
            if y != 0:
                if image[x][y - 1] == old_color and not isChosen[x][y - 1]:
                    q.put((x, y - 1))
                    isChosen[x][y - 1] = 1
        return image

if __name__ == '__main__':
    x = Solution()
    print(x.floodFill([[1,1,1],[1,1,0],[1,0,1]], 1, 1, 2))
