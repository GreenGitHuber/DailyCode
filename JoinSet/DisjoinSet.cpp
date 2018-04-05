///
//这个程序实现的是并查集的森林实现方法
//并查集两个关键的操作就是查询和合并
///
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class DisjoinSet
{
private:
    std::vector<int> id;
    std::vector<int> size;
    int count;
public:
    void print_set()
    {
        cout<<"元素：";
        for(int i=0;i<id.size();i++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"集合：";
        for(int i=0;i<id.size();i++)
        {
            cout<<id[i]<<" ";
        }
        cout<<endl;
        cout<<"朋友圈个数为："<<count<<endl;
    }
    DisjoinSet(int n)
    {
        for(int i=0;i<n;i++)
        {
            id.push_back(i);
            size.push_back(1);
        }
        count = n;
    }
    int find(int p)
    {
        while(id[p]!=p)
        {
            id[p]=id[id[p]];//路径压缩，把该点父节点设定为父节点的父节点
            p=id[p];
        }
        return p;
    }
    void unionMen(int p,int q)
    {
        int p_p = find(p);
        int q_p = find(q);
        if(p_p==q_p)return;
        if(p_p!=q_p)
        {
            if(size[q_p]<size[p_p])
                {
                    id[q_p]=p_p;
                    size[p_p]+=size[q_p];
                }
            else
            {
                id[p_p]=q_p;
                size[q_p]+=size[p_p];
            }
            count--;
        }
    }
};

int main()
{
    DisjoinSet disjoin_set(8);
    disjoin_set.print_set();
    cout<<"Union(0,5)"<<endl;
    disjoin_set.unionMen(0,5);
    disjoin_set.print_set();
    cout<<"Find(0)="<<disjoin_set.find(0)<<endl;
    cout<<"Find(5)="<<disjoin_set.find(5)<<endl;
    disjoin_set.unionMen(2,4);
    disjoin_set.print_set();
    disjoin_set.unionMen(0,4);
    disjoin_set.print_set();
}











