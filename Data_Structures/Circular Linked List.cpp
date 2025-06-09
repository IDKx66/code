#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct node{    
    ElemType data;
    node *next;
} Node;

//初始化链表
Node *initList(){
    Node *head = new Node;
    head->data = 0;
    head->next = nullptr;
    return head;
}

//找尾巴
Node* get_tail(Node *head){
    Node *p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    return p;
}
//单链表--尾插法
Node* insertTail(Node *head, ElemType data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    Node *tail = get_tail(head);
    tail->next = newNode;
    return newNode;
}

//遍历
void listNode(Node *head){
    Node *p = head->next;
    while(p != nullptr){
        printf("%d ", p->data);
        p = p->next;
    }
    cout << endl;
}


//判断链表是否有环的经典算法 —— 快慢指针法（Floyd 判圈算法）
int hasCycle(Node *head) {
    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;     // 快指针走两步
        slow = slow->next;           // 慢指针走一步

        if (slow == fast) {
            return 1; // 有环
        }
    }

    return 0; // 无环
}

//找环的入口
Node* findBegin(Node *head){
    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;     // 快指针走两步
        slow = slow->next;           // 慢指针走一步

        if (slow == fast) {
            Node *p = fast;
            int count = 1;
            while (p->next != slow) {
                p = p->next;
                count++;
            }

            fast = head;
            slow = head;

            while(count--){
                fast = fast->next;
            }//fast比slow多走环的长度的步

            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }

            return slow; // 环的入口
        }
    }

    return nullptr;
}


int main(){
    Node *L = initList();
    Node *tail = nullptr;

    tail = insertTail(L, 1);
    tail = insertTail(L, 2);
    tail = insertTail(L, 3);
    Node *three = tail;
    tail = insertTail(L, 4);
    tail = insertTail(L, 5);
    tail = insertTail(L, 6);
    tail = insertTail(L, 7);
    tail  = insertTail(L, 8);
    tail->next = three; //形成环

    // listNode(L);

    if (hasCycle(L)) {
        cout << "链表有环" << endl;
    }
    else {
        cout << "链表无环" << endl;
    }
    
    Node *begin = findBegin(L);
    cout << "环的入口是：" << begin->data << endl;
    return 0;
}