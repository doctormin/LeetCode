#https://leetcode.com/problems/reverse-only-letters/
'''
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "
'''

class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        saved = []
        ans = []
        for i, letter in enumerate(S):
            if not letter.isalpha():
                #不是字母
                saved.append([i, letter])
            else:
                #保存纯字母
                ans.append(letter)
        #将所有字母反向
        ans.reverse()
        #将所有非字母插入        
        for each in saved:
            ans.insert(each[0], each[1])
        
        return ''.join(ans)
        