#include <stdio.h>
int main(int argc, char const *argv[])
{
    char *p[] = {"ab", "cd", "ef"};
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", p[i]);
    }
    return 0;
}
