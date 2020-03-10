/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (36.18%)
 * Likes:    3585
 * Dislikes: 0
 * Total Accepted:    281.5K
 * Total Submissions: 777.6K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     struct ListNode *next;
// };

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *res, *p;
    res = NULL;
    p = NULL;
    int dec = 0;
    while (l1 || l2)
    {
        if (p == NULL)
        {
            res = (struct ListNode *)malloc(sizeof(struct ListNode));
            p = res;
        }
        else
        {
            p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            p = p->next;
        }

        p->val = dec;
        p->next = NULL;

        if (l1)
        {
            p->val += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            p->val += l2->val;
            l2 = l2->next;
        }

        dec = 1 ? p->val >= 10 : 0; //下次进位
        p->val = p->val % 10;       //本次最终值
    }
    if (dec == 1)
    {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->val = 1;
        p->next->next = NULL;
    }
    return res;
}

// @lc code=end
