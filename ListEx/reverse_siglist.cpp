#include <iostream>

struct Node
{
    int data;
    Node *next; // 指向下一个节点
};

Node* reverse(Node * head)
{
    if(head==NULL||head->next ==NULL)
    {
        return head;
    }

    Node *pre = NULL;
    Node *next=NULL;
    while(head)
    {
        next = head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    return pre;
}
