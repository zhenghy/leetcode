/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (32.19%)
 * Likes:    2857
 * Dislikes: 0
 * Total Accepted:    295.2K
 * Total Submissions: 916.9K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// @lc code=start

int lengthOfLongestSubstring(char *s)
{
    int maxlen=0;
    int start=0;
    int end=0;
    int map[128] = {0};

    map[s[start]] = 1;
    while (s[end] != 0)
    {
        maxlen = maxlen > (end - start + 1) ? maxlen : (end - start + 1);
        end++;
        while (map[s[end]] != 0) //新字符存在,截断
        {
            map[s[start++]] = 0;
        }
        map[s[end]] = 1;
    }

    return maxlen;
}

// @lc code=end

int main()
{
    int res;
    char *s = "tmmzuxt";
    res = lengthOfLongestSubstring(s);
    printf("%d", res);
    return 0;
}
