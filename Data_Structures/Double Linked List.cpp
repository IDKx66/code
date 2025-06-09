#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct node{
    ElemType data;
    node *prev, *next;
} Node;

//初始化链表
Node* initList(){
    Node *head = new Node;
    head->data = 0;
    head->next = nullptr;
    head->prev = nullptr;
    return head;
}

//头插法
int insertHead(Node *head, ElemType e){
    Node *p = new Node;
    p->data = e;
    p->prev = head;
    p->next = head->next;

    if(head->next != nullptr){
        head->next->prev = p;
    }

    head->next = p;
    return 1;
}

//遍历  
void listNode(Node *head){
    Node *p = head->next;
    while(p != nullptr){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl; 
}

//获取尾部节点
Node* get_tail(Node *head){
    Node *p = head;
    while(p->next != nullptr){
        p = p->next;
    }
    return p;
}

//尾插法
Node* insertTail(Node *tail, ElemType e){
    Node *p = new Node;
    p->data = e;
    p->prev = tail;
    tail->next = p;
    p->next = nullptr;
    return p;
}

//指定位置插入(此处输入需保证pos<节点数)
int insertNode(Node *head, int pos, ElemType e){
    Node *p = head;
    int i = 0;
    while(i < pos - 1){
        p = p->next;
        i++;
        if(p == nullptr){
            return 0;
        }
    }

    Node *q = new Node;
    q->data = e;
    q->prev = p;
    q->next = p->next;
    p->next->prev = q;
    p->next = q;

    return 1;
}

//删除节点
int deleteNode(Node *head, int pos){
    Node *p = head;
    int i = 0;
    while(i < pos - 1){
        p = p->next;
        i++;
        if(p == nullptr){
            return 0;
        }
    }

    Node *q = p->next;
    if(q->next == nullptr){
        p->next = nullptr;
        delete q;
        return 1;
    }//单独处理删除节点为最后一个节点的问题

    p->next = q->next;
    q->next->prev = p;
    delete q;
    return 1;
}
int main(){
    Node *list = initList();
    Node *tail = get_tail(list);
    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);

    listNode(list);
    deleteNode(list, 5);
    listNode(list);
    tail = get_tail(list);
    tail = insertTail(tail, 5);
    listNode(list);
    return 0;
}