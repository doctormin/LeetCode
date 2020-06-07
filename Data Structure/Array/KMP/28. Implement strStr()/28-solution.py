# https://leetcode.com/problems/implement-strstr/

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == []:
            return 0
        next = self.computeNext(needle)
        i = 0 
        j = 0 
        while i <= len(haystack):
            if haystack[i] == needle[j]:
                i += 1
                j += 1
            if j == len(needle):
                return i - len(needle)
            else:
                while needle[j] != haystack[i]:
                    j = next[j] + 1
                    if j == 0:
                        i += 1
                        j += 1
                        break
        return -1
        
    def computeNext(self, needle: str):
        next    = []
        next.insert(0, -1)
        if len(needle) > 1:
            next.insert(1, 0)
        if len(needle) > 2:
            for i in range(2, len(needle) - 1):
                j = next[i-1] + 1
                while needle[i-1] != needle[j] and j > 0:
                    j = next[j] + 1
                next.insert(i, j)    
        print(next)
        return next


if __name__ == "__main__":
    x = Solution()
    print(x.strStr("hello", "llo"))


