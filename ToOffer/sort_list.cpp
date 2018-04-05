#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 class ListNode {
 public:
     int val;
      ListNode *next;
    ListNode(int val) {
       this->val = val;
       this->next = NULL;
     }
};



class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode * sortList(ListNode * head) {
        // write your code here
        if (head==NULL)
        return NULL;
        vector<int> tem;
        while(head)
        {
            tem.push_back(head->val);
            head =head->next;
        }
        sort(tem.begin(),tem.end());
        vector<int>::iterator it=tem.begin();
        int a= *it;
        ListNode *n_head=new ListNode(a);
        ListNode *p = n_head;
        it++;
        for(it;it!=tem.end();it++)
        {
            ListNode *newnode=new ListNode(*it);
            p->next = newnode;
            p=p->next;
        }
        return n_head;
    }
};

int main()
{
    ListNode *N1=new ListNode(3);
    ListNode *N2=new ListNode(2);
    ListNode *N3=new ListNode(5);
    N1->next = N2;
    N2->next =N3;
    Solution s;
    ListNode *res;
    res=s.sortList(N1);
while(res)
{
    cout<<res->val<<' ';
    res=res->next;
}
return 0;

}
