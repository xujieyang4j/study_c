#include <stdio.h>
#include <stdlib.h>
struct node2
{
    int value;
    struct node2 *next;
};
void add_to_head2(struct node2 **list, int value);

int main(int argc, char const *argv[])
{
    // 头结点
    struct node2 *list = NULL;
    add_to_head2(&list, 1);
    add_to_head2(&list, 2);
    add_to_head2(&list, 3);

    printf("first node value:%d", list->value);

    return 0;
}

// 指针也是按值传递
void add_to_head2(struct node2 **first, int value)
{
    // 创建结点new_node，插入链表头部
    struct node2 *new_node;
    new_node = malloc(sizeof(struct node2));
    if (new_node == NULL)
    {
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }
    // (*new_node).value = value;
    new_node->value = value;
    new_node->next = *first;
    *first = new_node;
}