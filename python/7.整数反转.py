#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        sign = 1 if x>0 else (-1 if x<0 else 0)
        xConvert = int(sign*int(str(abs(x))[::-1]))
        if not (-2**31<= xConvert <= 2**31 -1):
            xConvert = 0
        return xConvert

test = Solution()
res = test.reverse(2463847412)
print(res)
# @lc code=end

