///
//这个程序实现的是hash的拉链法解决冲突
///
#include <iostream>
#include<vector>
using namespace std;

//定义hash
struct ListNode
{//这个ListNode是用来存放元素的
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
    
};

int hash_func(int key,int table_len)
{
    return key %table_len;
}

void insert(ListNode *hash_table[],ListNode *node,int table_len)
{
    int hash_key = hash_func(node->val,table_len);
    node->next = hash_table[hash_key];
    hash_table[hash_key] = node;
    //头插法
}

bool search(ListNode *hash_table[],int value,int table_len)
{
    int hash_key = hash_func(value,table_len);
    ListNode * head = hash_table[hash_key];
    while(head)
    {
        if(head->val==value)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

int main()
{
    const int TABLE_LEN=11;
    int test[8]={1,1,4,9,20,30,150,500};
    vector<ListNode *>hash_node_vec;
    ListNode * hash_table[TABLE_LEN]={0};
    for(int i = 0;i<8;i++)
    {
        hash_node_vec.push_back(new ListNode(test[i]));
    }
    for(int i = 0;i<hash_node_vec.size();i++)
    {
        insert(hash_table,hash_node_vec[i],TABLE_LEN);
    }
    cout<<"hash Table:"<<endl;
    for(int i = 0;i<TABLE_LEN;i++)
    {
        cout<<'['<<i<<']'<<":";
        ListNode *p=hash_table[i];
        while(p)
        {
            cout<<"->"<<p->val;
            p=p->next;
        }
        cout<<endl;
    }
    return 0;
}










