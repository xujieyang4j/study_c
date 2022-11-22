#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 线程函数1
void thread_func1(void *arg)
{
    int num = (intptr_t)arg;
    for (int i = 0; i <= num; i++)
    {
        printf("This is a pthread_1.\n");
        if (i == 2)
        {
            pthread_exit(0);
        }
        sleep(1);
    }
}

// 线程函数2
void thread_func2(void)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("This is a pthread_2.\n");
    }
    pthread_exit(0);
}

int main(int argc, char const *argv[])
{
    pthread_t t1, t2;

    // 创建线程1
    int r1 = pthread_create(&t1, NULL, (void *)thread_func1, (void *)(intptr_t)6);
    if (r1 != 0)
    {
        printf("Create pthread error!\n");
        return -1;
    }
    // 创建线程2
    int r2 = pthread_create(&t2, NULL, (void *)thread_func2, NULL);
    if (r2 != 0)
    {
        printf("Create pthread error!\n");
        return -1;
    }

    // sleep(5);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
