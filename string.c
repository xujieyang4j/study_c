#include<stdio.h>
#include<string.h>
void strConcat();

int main(int argc, char const *argv[])
{
    char *p1 = "abc";
    // 注意len=4，预留\0
    char p2[4] = "edf";
    char p3[4] = {'r', 't', 'p'};
    printf("%s\n", p1);
    printf("%s\n", p3);
    printf("%s\n", p2);
    // char input[5];
    // printf("%s", "input str\n");
    // scanf("%s", input);
    // printf("%s\n", input);

    strConcat();

    return 0;
}

void strConcat() {
    char str1[9] = "abc";
    char str2[4] = "efs";
    strcat(str1, str2);
    // strncat(str1, str2);
    printf("s1:%s\n", str1);
    printf("s2:%s\n", str2);
}
