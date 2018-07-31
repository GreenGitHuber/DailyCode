//
// Created by 姜倩云 on 2018/7/15.
//

/** 示例: 等待线程退出 **/
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct{
    int val1;
    int val2;
} Args;

void *thread_rotine(void *args)
{
    Args *a = (Args *)args;
    int b = a->val1;
    int e = a->val2;
    int sum = 0;
    for (int i = b; i < e; ++i)
    {
        sum+=i;
    }
    cout<<"part sum:"<<sum<<endl;
    return (void*) sum;
}


int main() {

    pthread_t thread[5];
    Args a[5];
    void* res[5];
    int sum=0;
    for(int i = 0;i<5;i++)
    {
        a[i]={i*10,i*10+10};
    }

    for (int i = 0; i < 5; ++i) {

        cout<<"i : "<<i<<endl;
        pthread_create(&thread[i], NULL, thread_rotine, (void*) & a[i]);
    }

    for (int i = 0; i < 5; ++i)
    {

        pthread_join(thread[i],&res[i]);
//        cout<<(long)res[i]<<endl;
        sum += (long) res[i];
    }

    cout<<"sum:"<<sum;
    sleep(10);

}



