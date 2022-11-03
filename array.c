#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a[5] = {1, 2, 3, 4, 5};
    int len = (int)(sizeof(a) / sizeof(a[0]));
    printf("len:%d", len);
    return 0;
}
