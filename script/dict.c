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
    printf("====\nsize:%d",len(dict));
    printf("\n{");
    while (p)
    {
        printf("%d:%d,", p->key, p->value);
        p = p->next;
    }
    printf("}\n====\n");
    return 1;
}

int main()
{
    NODE *dict = NULL;
    set(&dict, 1, 1);
    set(&dict, 2, 4);
    set(&dict, 3, 27);
    view(dict);
    del(&dict, 3);
    view(dict);
    printf("%d\n", *get(dict, 2));
}
