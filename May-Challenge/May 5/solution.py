class Solution:
    def firstUniqChar(self, s: str) -> int:
        dict = {}
        for each in s:
            if dict.get(each, -1) == -1:
                dict[each] = 1
            else:
                dict[each] += 1
        for each in dict:
            if(dict[each] == 1):
                return s.find(each)
        return -1

if __name__ == "__main__":
    x = Solution()
    print(x.firstUniqChar("lelove"))


