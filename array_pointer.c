#include<stdio.h>
#define N 5
void for1();
void for2();
void for3();
void for4();
int findL1(int a[], int n);
int findL2(int *a, int n);
int main(int argc, char const *argv[])
{
    // int a[N] = {1, 2, 3, 4, 5};
    
    //for3();
    
    // int lNum = findL2(a, N);
    // printf("lNum:%d\n", lNum);  
    
    for4();
    return 0;
}

void for1() {
    int a[N] = {1, 2, 3, 4, 5};
    int sum = 0;
    int *p;
    for (p = &a[0]; p < &a[N]; p++) {
        sum += *p;
    }
    printf("sum:%d", sum);
}

void for2() {
    int a[N] = {1, 2, 3, 4, 5};
    int sum = 0;
    int *p;
    //  数组名作为指针
    for (p = a; p < a + N; p++) {
        sum += *p;
    }
    printf("sum:%d\n", sum);  
}

void for3() {
    int a[N] = {1, 2, 3, 4, 5};
    int sum = 0;
    int *p;
    //  数组名作为指针
    for (p = a + N - 1; p >= a; p--) {
        sum += *p;
    }
    printf("sum:%d", sum); 
}

void for4() {
    int a[N] = {1, 2, 3, 4, 5};
    int sum = 0;
    int *p = a;
    //  指针作为数组名
    for (int i = 0; i < N; i++) {
        sum += p[i];
    }
    printf("sum:%d", sum); 
}

int findL1(int a[], int n) {
    int tmp = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > tmp) {
            tmp = a[i];
        }
    }
    return tmp;
}

int findL2(int *a, int n) {
    int tmp = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > tmp) {
            tmp = a[i];
        }
    }
    return tmp;
}