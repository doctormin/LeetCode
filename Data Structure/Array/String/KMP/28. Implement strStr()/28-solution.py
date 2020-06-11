# https://leetcode.com/problems/implement-strstr/

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        A = "x" + haystack
        B = "x" + needle
        n = len(haystack) 
        m = len(needle)

        next = self.computeNext(B, m)
        i = 1
        j = 1 

        while i <= n:
            if A[i] == B[j]:
                i += 1
                j += 1
            if j == m + 1:
                return i - len(needle) - 1
            else:
                while i <= n and B[j] != A[i]:
                    j = next[j] + 1
                    if j == 0:
                        i += 1
                        j = 1
                        break
        return -1
        
    def computeNext(self, B: str, m: int):
       next = []
       next.insert(0, "x")
       next.insert(1, -1)
       next.insert(2, 0)
       for i in range(3, m+1):
           j = next[i-1] + 1
           while B[j] != B[i - 1] and j > 0:
               j = next[j] + 1
           next.insert(i, j)
       return next


if __name__ == "__main__":
    x = Solution()
    print(x.strStr("mississippi", "issip"))


