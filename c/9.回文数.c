/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start

bool isPalindrome(int x)
{
    long y = 0;
    int p = x;
    while (p)
    {
        y = 10 * y + p % 10;
        p = p / 10;
    }
    return x>=0 && (y==x);
}

// @lc code=end
