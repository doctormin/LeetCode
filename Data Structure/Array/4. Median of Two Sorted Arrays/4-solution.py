#https://leetcode.com/problems/median-of-two-sorted-arrays/

'''
时间复杂度要求：O(log(m+n))
法一：归并+找中位数 (O(m+n))
法二：分情况讨论：
    如果两个数列可以首位相接，那么就是O(1)
    如果两个数列不能首位相接
'''
#way 1:
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        #merge:
        s = []
        m = len(nums1)
        n = len(nums2)
        i = 0;
        j = 0;
        while True:
            if(nums1[i] < nums2[j]):
                s += nums1[i]
                i += 1
                if(i == m):
                    s += nums2[j:n]
                    break
            else:
                s += nums2[j]
                j += 1
                if(j == n):
                    s += nums1[i:m]
                    break
        if (m+n) % 2 == 0:
            return (s[(m+n)//2] + s[(m+n)//2 + 1]) / 2
        else: 
            return s[(m+n) //2 + 1]


