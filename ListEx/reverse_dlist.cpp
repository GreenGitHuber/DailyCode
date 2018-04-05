// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
#include <future>
#include <thread>
#include <string>

//using namespace std;

struct Node
{
    int data;
    Node *next; // 指向下一个节点
    Node *prev; // 指向前一个节点
};

//对链表进行反转
Node*  reverse(Node *head)
{
    // //摘下head结点，将后面的结点 前插入 head
    // Node *current = head->next;
    // head->next = NULL;
    // head->prev = NULL;

    // while (current != NULL)
    // {
    //  //记录current的下一个结点
    //  Node * current_next = current->next;
        
    //  current->next = NULL;
    //  current->prev = NULL;
    //  //将current结点 前插入head之前
    //  current->next = head;
    //  head->prev = current;

    //  //更改head的位置，让head指向最前
    //  head = current;
    //  current = current_next;
    // }
    // return head;
    Node * pre=NULL;
    Node* next=NULL;
    if(head==NULL||head->next==NULL)
        return head;
    while(head)
    {
        next=head->next;
        head->next=pre;
        head->prev=next;
        pre=head;
        head = next;
    }
    return pre;
}

// 给定链表的头指针(head)以及一个整数，插入一个新的节点至链表的头部  
// 之所以传入双指针，因为函数中需要修改链表  
Node* push(Node* head, int newData)
{
    //1. 分配新节点内存  
    Node* newNode = new Node;

    //2. 赋值  
    newNode->data = newData;

    //3. 将原始头节点做为新节点的后向指针，而前向指针置为NULL  
    newNode->next = (head);
    newNode->prev = NULL;

    //4. 将原始头节点的前向指针置为新的节点  
    if ((head) != NULL)
        (head)->prev = newNode;

    //5. 将头指针置为新的节点  
    (head) = newNode;
    return head;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        std::cout << " " << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}


int main()
{
    //初始化链表为：10<->8<->6<->4<->2<->0
    Node* head = NULL;
    head = push(head, 0);
    head = push(head, 2);
    head = push(head, 4);
    head = push(head, 6);
    head = push(head, 8);
    head = push(head, 10);

    std::cout << "Original DLL is: ";
    printList(head);

    head = reverse(head);

    std::cout << "Reversed DLL is: ";
    printList(head);

    system("pause");
    return 0;
}