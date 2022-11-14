#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test1();
void test2();
char *concat1(const char *s1, const char *s2);
char *concat2(const char *s1, const char *s2);

int main(int argc, char const *argv[])
{
    // test1();
    test2();
    return 0;
}

void test1()
{
    char *p = malloc(4 + 1);
    if (p == NULL)
    {
        printf("malloc fail!");
        exit(EXIT_FAILURE);
    }
    strcpy(p, "abcd");
    printf("p:%s\n", p);
}
void test2()
{
    char *s1 = "ab";
    char *s2 = "cd";
    char *s3 = concat1(s1, s2);
    printf("s3:%s\n", s3);
}

char *concat1(const char *s1, const char *s2)
{
    char *rs;
    rs = malloc(strlen(s1) + strlen(s2) + 1);
    if (rs == NULL)
    {
        printf("malloc fail!");
        exit(EXIT_FAILURE);
    }
    strcpy(rs, s1);
    strcat(rs, s2);
    free(rs);
    return rs;
}

char *concat2(const char *s1, const char *s2)
{
    char *result;
    result = malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL)
    {
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}