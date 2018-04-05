#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node(int i)
    {
        val=i;
        next=NULL;
    }
};

Node *reverseNode(Node* head)
{
    if(head==NULL||head->next==NULL)
        return head;
    Node * pre=NULL;
    Node * next=NULL;
    while(head)
    {
        next=head->next;
        head->next=pre;
        pre = head;
        head=next;
    }
    return pre;
}

int main()
{
    Node *N1=new Node(3);
    Node *N2=new Node(2);
    Node *N3=new Node(5);
    N1->next = N2;
    N2->next =N3;
    // Solution s;
    Node *res;
    res=reverseNode(N1);
while(res)
{
    cout<<res->val<<' ';
    res=res->next;
}
return 0;

}