#include<stdio.h>
#define N 5
void max_min(int a[], int n, int *max, int *min);
int main(int argc, char const *argv[])
{
    int a[N] = {11, 10, 2, 3, 5};
    int max, min;
    max_min(a, N, &max, &min);
    printf("max:%d\n", max);
    printf("min:%d", min);
    return 0;
}
void max_min(int a[], int n, int *max, int *min) 
{
    *max = a[0];
    *min = a[0];
    for (int i = 1; i < n; i++) 
    {
        if (a[i] > *max) {
            *max = a[i];
        }
        if (a[i] < *min) {
            *min = a[i];
        }
    }
}

