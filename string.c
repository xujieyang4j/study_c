#include <stdio.h>
#include <string.h>
void test1();
void test2();
void str_cat1();
void str_cat2();
void str_cat3();
char *strcat_my(char *s1, const char *s2);

int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // str_cat1();
    // str_cat2();
    str_cat3();
    return 0;
}

void test1()
{
    char *p1 = "abc";
    // 注意len=4，预留\0
    char p2[4] = "edf";
    char p3[] = "cvf";
    printf("%s\n", p1);
    printf("%s\n", p3);
    printf("%s\n", p2);
    // char input[5];
    // printf("%s", "input str\n");
    // scanf("%s", input);
    // printf("%s\n", input);
}

void test2()
{
    printf("please input str:");
    char str[4];
    scanf("%s", str);
    printf("%ld\n", strlen(str));
    printf("str:%s", str);
}

void str_cat1()
{
    char str1[9] = "abc";
    char str2[4] = "efs";
    strcat(str1, str2);
    // strncat(str1, str2);
    printf("s1:%s\n", str1);
    printf("s2:%s\n", str2);
}

void str_cat2()
{
    char str1[13] = "abc";
    char str2[4] = "efs";
    strcat(str1, str2);
    printf("s1:%s\n", str1);
    printf("s2:%s\n", str2);
}

void str_cat3()
{
    char *str1 = "abc";
    char *str2 = "efs";
    strcat_my(str1, str2);
    printf("s1:%s\n", str1);
    printf("s2:%s\n", str2);
}

// 字符串连接，将s2连接到s1后面 = 把s2数组的内容复制到s1后面
// https://weread.qq.com/web/reader/36b32e5071de82f936b66dck70e32fb021170efdf2eca12
char *strcat_my(char *s1, const char *s2)
{
    // 把s1的地址复制给p
    char *p = s1;
    while (*p != '\0')
        p++;
    while (*s2 != '\0')
    {
        *p = *s2;
        p++;
        s2++;
    }
    *p = '\0';
    return s1;
}

// char *strcat_my2(char *s1, const char *s2)
// {
//     char *p = s1;
//     while (*p)
//         p++;
//     while (*p++ = *s2++)
//         ;
//     return s1;
// }