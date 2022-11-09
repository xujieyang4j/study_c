#include <stdio.h>
void test1();
int *arry_copy_my(int a[], int b[]);
int main(int argc, char const *argv[])
{
    int a[3] = {1, 2, 3};
    int b[3] = {4, 5, 6};
    arry_copy_my(a, b);
    return 0;
}

void test1()
{
    int a[5] = {1, 2, 3, 4, 5};
    int len = (int)(sizeof(a) / sizeof(a[0]));
    printf("len:%d", len);
}

int *arry_copy_my(int a[], int b[])
{
    int len1 = (int)(sizeof(a) / sizeof(a[0]));
    int len2 = (int)(sizeof(a) / sizeof(a[0]));
    int rs[len1 + len2 + 1];
    for (int i = 0; i < len1; i++)
    {
        rs[i] = a[i];
    }
    for (int j = 0; j < len2; j++)
    {
        rs[len1 + j] = b[j];
    }
    return rs;
}