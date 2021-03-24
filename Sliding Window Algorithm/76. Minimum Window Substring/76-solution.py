class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # 从s中找到包含t的字符的最小window
        if s == '' or t == '':
            return ''
        l, r = -1, -1 # window的两个pointer
        # Step1 - 确定t的字符集合
        t_chars = {}
        for each in t:
            t_chars[each] = 1
        window_chars = {}
        min_pair = []
        min_len = len(s) + 1
        # Step2 - sliding window
        def window_cover(m: dict, n: dict) -> bool:
            for each in n:
                if each in m:
                    if m[each] < n[each]:
                        return False
                else:
                    return False
            return True
        flag = False
        while r < len(s):
            while not window_cover(window_chars, t_chars):
                r += 1
                if r ==  len(s):
                    break
                if s[r] in window_chars:
                    window_chars[s[r]] += 1
                else :
                    window_chars[s[r]] = 1
            while window_cover(window_chars, t_chars):
                l += 1
                flag = True
                window_chars[s[l]] -= 1
                if window_chars[s[l]] == 0:
                    del window_chars[s[l]]
            if r - l + 1 < min_len:
                min_pair = [l, r + 1]
                min_len = r - l + 2
        if flag:
            return s[min_pair[0]:min_pair[1]]
        else:
            return ''

        