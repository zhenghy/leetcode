/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start

// int reverse(int x)
// {
//     int sign, m, y, tmp;
//     sign = x < 0 ? -1 : (x > 0 ? 1 : 0);
//     if (x == -1 * __INT_MAX__ - 1)
//     {
//         return 0;
//     }
//     tmp = x < 0 ? -1 * x : x;
//     y = 0;
//     while (tmp > 0)
//     {
//         m = tmp % 10;
//         if (y > (__INT_MAX__ - m) / 10)
//         {
//             y = 0;
//             break;
//         }
//         y = 10 * y + m;
//         tmp = (tmp - m) / 10;
//     }
//     return sign * y;
// }

int reverse(int x)
{
    int max = __INT_MAX__;
    long rs = 0;
    while (x)
    {
        rs = rs * 10 + x % 10;
        x = x / 10;
    }
    return rs > max || rs < -1 * max - 1 ? 0 : rs;
}

// @lc code=end
