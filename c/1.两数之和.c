/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.14%)
 * Likes:    7189
 * Dislikes: 0
 * Total Accepted:    731.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

//定义字典节点
//头节点即表示字典
typedef struct _NODE
{
    int key;
    int value;
    struct _NODE *next;
    struct _NODE *back;
} NODE;

// 求字典大小
int len(NODE *dict)
{
    int size = 0;
    NODE *p = dict;
    while (p)
    {
        size++;
        p = p->next;
    }
    return size;
}

// 取址: 返回节点地址
NODE *addr(NODE *dict, int key)
{
    NODE *p = dict; //一个节点也是一个字典。
    while (p && p->key != key)
        p = p->next;
    return p;
}

// 取值: 返回节点值
int *get(NODE *dict, int key)
{
    NODE *p = addr(dict, key);
    if (p != NULL)
        return &(p->value);
    return NULL;
}

// 设值
int set(NODE **dict, int key, int value)
{
    NODE *p = addr(*dict, key);
    //不存在则插入
    if (p == NULL)
    {
        //构造单节点字典。
        p = (NODE *)malloc(sizeof(NODE));
        p->key = key;
        p->value = value;
        p->next = NULL;
        p->back = NULL;

        //dict 为空的插入
        if (*dict == NULL)
        {
            *dict = p;
            return 1;
        }
        //在最前面插入新的节点
        p->next = (*dict);
        p->back = NULL;
        (*dict)->back = p;
        *dict = p;
        return 1; // 插入成功
    }

    //存在则更新
    p->value = value;
    return 0; //更新成功
}

//从哈希表中删除数据
int del(NODE **dict, int key)
{
    NODE *p = addr(*dict, key);
    if (p == NULL)
        return -1;                          //不存在节点
    if (p->next == NULL && p->back == NULL) //dict就一个node
    {
        free(p);
        *dict = NULL;
    }
    if (p->next != NULL && p->back == NULL) //第一个node
    {
        *dict = p->next;
        free(p);
    }
    if (p->next == NULL && p->back != NULL) //最后一个node
    {
        p->back->next = NULL;
        free(p);
    }
    if (p->next != NULL && p->back != NULL) //中间节点
    {
        p->back->next = p->next;
        p->next->back = p->back;
        free(p);
    }
    return 1; //删除成功
}

int view(NODE *dict)
{
    NODE *p = dict;
    //开始
    printf("====\nsize:%d", len(dict));
    printf("\n{");
    while (p)
    {
        printf("%d:%d,", p->key, p->value);
        p = p->next;
    }
    printf("}\n====\n");
    return 1;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *res = (int *)malloc(sizeof(int) * (*returnSize));
    int *other = NULL;
    NODE *dict;
    for (int i = 0; i < numsSize; i++)
    {
        other= get(dict, target - nums[i]);
        if (other == NULL)
            set(&dict,nums[i],i); // 生成{num:index}的键值对
        else
        {
            *res=*other;
            *(res+1)=i;
        }
    }
    return res;
}

// @lc code=end
