'''
@index 5
@title 最长回文子串
@difficulty 中等
@tags string,dynamic-programming
@draft false
@link https://leetcode.cn/problems/longest-palindromic-substring/description/
@frontendId 5
@solved false
'''

class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expendAroundCenter(left, right):
            nonlocal start, max_length
            while left >=0 and right < len(s) and s[left] == s[right]:
                if right - left + 1 > max_length:
                    max_length = right - left + 1
                    start = left
                left -= 1
                right += 1
            print(start, max_length)
        max_length = 1
        start = 0
        for i in range(len(s)):
            expendAroundCenter(i - 1, i + 1) # a b a
            expendAroundCenter(i, i + 1) # a b b a
        return s[start: start + max_length]


