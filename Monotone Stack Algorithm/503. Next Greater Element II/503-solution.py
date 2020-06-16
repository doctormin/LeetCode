#https://leetcode.com/problems/next-greater-element-ii/
'''
问题：在循环数组中找每个元素的下一个更大元素，如果不存在就填-1
算法思路：
    使用栈进行操作，遍历数组
    如果栈空，入栈
    如果栈不空，和栈顶做比较：
        如果比栈顶大，不断将栈顶出栈，并且将之的下一个更大设为当前元素
        如果比栈顶小，入栈
    再次遍历数组
        同上
        如果当前元素是max, 遍历结束
    将所有元素出栈，并将之的下一个最大值设为-1
'''
'''
Runtime: 216 ms, faster than 94.57% of Python3 online submissions for Next Greater Element II.
Memory Usage: 15.2 MB, less than 81.75% of Python3 online submissions for Next Greater Element II.
'''
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        size = len(nums)
        if size == 0:
            return []
        Max = max(nums)
        st = []
        ans = [0] * size
        for i in range(size):
            while st and nums[i] > nums[st[-1]]:
                index = st.pop()
                ans[index] = nums[i]
            st.append(i)
        for i in range(size):
            while st and nums[i] > nums[st[-1]]:
                index = st.pop()
                ans[index] = nums[i]
            if nums[i] == Max:
                break
        while st:
            index = st.pop()
            ans[index] = -1
        return ans

