

/*1.哈希表的C实现
  查找使用的方法是“除留余数法”，解决冲突使用的方法是“链地址法”。
  2. Map 是map, Hash 是hash.不是一回事
  3. Map 就像python 中的字典。
  4. Hash 是一种储存技术。
  5. 第一题目刚好可以用hash技术而已。
  6. 以下代码无关hash，主要是用C的链表实现python 字典功能
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //memset

//定义数据节点
//NODE：{key,value,next}. next是一个NODE类型的地址.
typedef struct _NODE
{
    int key;
    int value;
    struct _NODE *next;
} NODE;

// 定义字典
// DICT: {很多个NODE的地址}.
typedef struct _DICT
{
    NODE *node;
    int size;
} DICT;

// 创建字典
void Create(DICT *dict, int size)
{
    dict->node = (NODE *)malloc(sizeof(NODE) * size);
    memset(dict->node, 0, sizeof(NODE) * size); // 初始化dict
    dict->size = size;
}

// 查找函数
int Get(DICT *dict, int key)
{
    if (dict == NULL)
        return NULL;
    NODE *pNode;
    pNode = dict->node;
    while (pNode)
    {
        if (data == pNode->data)
            return pNode;
        pNode = pNode->next;
    }
    return NULL;
}
//在哈希表中插入数据
STATUS Set(DICT *dict, int data)
{
    NODE *pNode;
    // 字典是空，则不能插入?
    if (dict == NULL)
        return FALSE;
    // 值已经存在
    if (NULL != Get(dict, data))
        return FALSE;
    // 在字典的最后位置插入
    pNode = dict->value[data % 10];
    while (pNode != NULL)
        pNode = pNode->next;
    pNode = (NODE *)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    pNode->data = data;
    return TRUE;
}
//从哈希表中删除数据
STATUS Del(DICT *dict, int data)
{
    NODE *pHead;
    NODE *pNode;
    if (dict == NULL)
        return FALSE;
    pNode = Get(dict, data);
    pHead = dict->value[data % 10];
    while (pNode != pHead->next)
        pHead = pHead->next;
    pHead->next = pNode->next;
    return TRUE;
}

STATUS Show(DICT *dict)
{
    NODE *p;
    if (dict == NULL)
    {
        printf("NULL");
        return FALSE;
    }
    else
    {
        printf("HEAD->");
    }
    p = dict->value;
    while (p)
    {
        printf("%d", p->data);
        p = p->next;
    }
    printf("NULL");
    return TRUE;
}

int main()
{
    DICT *dict = Create();
    Set(dict, 1);
    Set(dict, 4);
    Set(dict, 11);
    Set(dict, 21);
    NODE *node1 = Get(dict, 11);
    NODE *node2 = Get(dict, 21);
    Show(dict);
    Del(dict, 21);
    Show(dict);
    Get(dict, 21);
}