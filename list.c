#include <stdio.h>
#include <stdlib.h>
struct node *add_to_head(struct node *first, int value);
struct node *search_list(struct node *first, int value);
struct node *del_list(struct node *list, int value);
struct node
{
    int value;
    struct node *next;
};

int main(int argc, char const *argv[])
{
    // 头结点
    struct node *first = NULL;
    for (int i = 1; i <= 10; i++)
    {
        first = add_to_head(first, i);
    }

    // struct node *rs = search_list(first, 4);
    // printf("rs:%d\n", rs->value);

    struct node *delRs = del_list(first, 3);

    return 0;
}

struct node *add_to_head(struct node *first, int value)
{
    // 创建结点new_node，插入链表头部
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    // (*new_node).value = value;
    new_node->value = value;
    new_node->next = first;
    return new_node;
}

struct node *search_list(struct node *list, int value)
{
    struct node *p;
    for (p = list; p != NULL; p = p->next)
    {
        if (p->value == value)
        {
            return p;
        }
    }
    return NULL;
}

/*
for (cur = list, prev = NULL;
     cur  != NULL && cur->value != n;
     prev = cur, cur = cur->next)
  ;
*/
struct node *del_list(struct node *list, int value)
{
    // for (cur = list, prev = NULL;
    //     cur != NULL && cur->value != value;
    //     prev = cur, cur = cur->next);
    struct node *prev = NULL;
    struct node *cur = list;
    for (;;)
    {
        if (cur == NULL)
        {
            break;
        }
        if (cur->value == value)
        {
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    // del no node
    if (cur == NULL)
    {
        return list;
    }
    // del fist node
    if (prev == NULL)
    {
        list = list->next;
        return list;
    }
    prev->next = cur->next;
    free(cur);
    return list;
}
