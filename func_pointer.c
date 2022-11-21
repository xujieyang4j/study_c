#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct vstring
{
    int len;
    // char str[1];
    char str[];
};
void test001();
void test002();
void tabulate(double (*f)(double), double first, double last, double incr);

int main(int argc, char const *argv[])
{
    // test001();
    test002();
    return 0;
}

void test001()
{
    double first = 1.1;
    double last = 7.9;
    double incr = 0.5;
    printf("tan:\n");
    tabulate(tan, first, last, incr);
    printf("sin:\n");
    tabulate(sin, first, last, incr);
}

void test002()
{
    int n = 64;
    struct vstring *strs = malloc(sizeof(struct vstring) + n);
    strs->len = n;
    // printf("strs len:%d\n", (int)(sizeof(strs->str) / sizeof(strs->str[0])));
    // strs->str = "abcd";
}

// 第一个参数是函数指针，代表入参double和出参double的函数
void tabulate(double (*f)(double), double first, double last, double incr)
{
    double x;
    int i, num;
    num = ceil((last - first) / incr);
    for (int i = 0; i < num; i++)
    {
        x = first + i * incr;
        printf("%10.5f %10.5f\n", x, (*f)(x));
    }
}