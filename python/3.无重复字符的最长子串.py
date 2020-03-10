#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#


# @lc code=start
class Solution:

    # # answer 1
    # def lengthOfLongestSubstring2(self, s: str) -> int:
    #     stringLength = len(s)
    #     if stringLength < 2:
    #         return stringLength
    #     i = 0
    #     j = 1
    #     l = 1
    #     while j< stringLength:
    #         if s[j] not in s[i:j]:
    #             l = max(l, j - i+1)
    #             j = j + 1
    #         else:
    #             while s[j] in s[i:j]:
    #                 i = i + 1
    #     return l
    # # answer 2
    def lengthOfLongestSubstring(self, s: str) -> int:
            slen = len(s)
            d = {e:index for index,e in enumerate(s)}
            start = 0
            maxlen = 0

            for i in range(slen):
                newIndex = d[s[i]]
                if start<=newIndex<i: # 新字符在子串。
                    start = newIndex+1
                else:
                    maxlen = max(maxlen, i - start + 1)
                
            return maxlen

test = Solution()
#res = test.lengthOfLongestSubstring('tmmzuxt')
res = test.lengthOfLongestSubstring('tmm')
print(res)

# @lc code=end
