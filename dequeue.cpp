#include<iostream>
#include<queue>
using namespace std;

// int main()
// {
//     deque<int> deq;
//     deq.push_back(10);
//     deq.push_back(20);
//     deq.push_front(3);
//     cout<<deq.size()<<endl;
//     return 0;

// }
int main(int argc,char**argv){
    int a[4]={1,2,3,4};
    int*ptr=(int*)(&a+1);
    cout<<*(ptr-1);
}