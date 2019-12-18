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

struct item
{
    int key;
    int value;
};

struct dict
{
    struct item *data;
    int size;
};

void Create(struct dict *name, int size, int *keys, int *values)
{
    name->size = size;
    name->data = (struct item *)malloc(sizeof(struct item) * size);
    for (int i = 0; i < name->size; i++)
    {
        int addr;
        addr = (name->data) + i * sizeof(struct item);
        addr->key = keys[i];
        addr->value = values[i];
    }
}

void Drop(struct dict *name)
{
    free(name->data);
    name->data = NULL;
    name->size = 0;
}

struct item *Get(struct dict *name, int key)
{
    for (int i = 0; i < name->size; i++)
    {
        int addr;
        addr = (name->data) + i * sizeof(struct item);
        if addr->key == key)
            return name->data;
    }
    return NULL;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    return returnSize;
}

void main()
{
    struct dict test;
    int key[] = {1, 2, 3};
    int value[] = {4, 5, 6};
    Create(&test, 3, key, value);
    printf("%d",Get(&test,3)->value);
}
// @lc code=end
