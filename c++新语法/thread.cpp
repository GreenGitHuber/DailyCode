#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
using namespace std;
typedef struct 
{
  int val1;
  int val2;  
} Stu;

void* th1(void* arg)
{
    sleep(20);
    cout<<"thread 1 :doing something"<<endl;
}

void * th2(void* arg)
{
    sleep(20);
    Stu * s =(Stu *)arg;
    cout<<"val1 :"<<s->val1<<"val2:"<<s->val2<<endl;
    cout<< "thread 2: do something"<<endl;
}

int main()
{
    pthread_t p1,p2;
    Stu s1={100,200};
    Stu *ps = &s1;
    cout<<ps->val1<<" "<<ps->val2<<endl;

     //创建线程p1 去执行 th1函数 (不带参数)
    //pthread_create(pthread_t* tidp,attr,start_rtn,arg)
    //start_rtn 表示线程运行函数的开始
    //arg是传给运行函数的参数
    if(pthread_create(&p1,NULL,th1,NULL)!=0){
        cout<<"thread create error"<<endl;
    }
    if(pthread_create(&p2,NULL,th2,(void *) &s1)!=0)
    {
        cout<<"thread create error"<<endl;
    }
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    return 0;
}