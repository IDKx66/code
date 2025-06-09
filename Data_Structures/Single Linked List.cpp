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

//单链表--头插法（的顺序和排列的顺序是相反的）
void insertHead(Node *head, ElemType e){
    Node *p = new Node;
    p->data = e;
    p->next = head->next;
    head->next = p;
}

//单链表--尾插法
void insertTail(Node *head, ElemType e){
    Node *tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    Node *p = new Node;
    p->data = e;
    tail->next = p;
    p->next = nullptr;
}

//单链表--在指定位置插入数据
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
    //此处p指向指定位置的前一个节点
    Node *q = new Node;
    q->data = e;
    q->next = p->next;
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
            printf("要删除的位置超出链表范围\n");
            return 0;
        }
    }
    if(p->next == nullptr){
        printf("要删除的位置错误\n");
    }

    Node *q = p->next;
    p->next = q->next;
    delete q;
    return 1;
}

//遍历单链表
void listNode(Node *head){
    Node *p = head->next;
    while(p != nullptr){
        printf("%d ", p->data);
        p = p->next;
    }
    cout << endl;
}

//单链表的长度
int lenList(Node *head){
    Node *p = head;
    int len = 0;
    while(p->next != 0){
        p = p->next;
        len++;
    }
    return len;
}

//释放链表
void freeList(Node *head){
    Node *p = head->next;
    Node *q;
    while(p != nullptr){
        q = p->next;
        delete p;
        p = q;
    }
    head->next = nullptr;
}

// 找到链表倒数第k个节点
int findNodeFS(Node *head, int k){
    // 定义快慢指针，初始都指向链表头节点的下一个节点
    Node *fast = head->next;
    Node *slow = head->next;
    // 快指针先走k步
    for(int i = 0; i < k; i++){
        fast = fast->next;
    }
    // 快慢指针同时走，直到快指针走到链表末尾
    while(fast != nullptr){
        fast = fast->next;
        slow = slow->next;
    }
    // 输出倒数第k个节点的值
    printf("倒数第%d个节点为%d\n", k, slow->data);
    // 返回倒数第k个节点的值
    return slow->data;
}

//反转链表
Node *reverseList(Node *head){
    Node *first = nullptr;
    Node *second = head->next;
    Node *third;//用来保存second的后继节点

    while(second != nullptr){
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    Node *hd = initList();
    hd->next = first;
    return hd;
}

//删除链表中间节点（偶数的话删除的是中间靠右的）
int delMiddleNode(Node *head){
    Node *fast = head->next;
    Node *slow = head;

    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *q = slow->next;
    slow->next = q->next;
    delete q;
    return 1;
}

// ⭐⭐⭐链表重新排序⭐⭐⭐
void reorderList(Node *head){
    Node *fast = head->next;
    Node *slow = head->next;
    
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *first = nullptr;//first用来保存second的前驱节点
    Node *second = slow->next;
    slow->next= nullptr;
    Node *third =nullptr;//third用来保存second的后继节点

    while(second != nullptr){
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }//反转结束后后半段的第一个就是first

    Node *p1 = head->next;
    Node *q1 = first;
    Node *p2, *q2;

    while(p1 != nullptr && q1 != nullptr){
        p2 = p1->next;
        q2 = q1->next;

        p1->next = q1;
        q1->next = p2;

        p1 = p2;
        q1 = q2;
    }
    //最后头节点还是head
}

//gpt写的，我的在上面被注释掉了，都🆗
// void reorderList(Node *head) {
//     if (!head || !head->next || !head->next->next) return;

//     Node* slow = head->next;
//     Node* fast = head->next;

//     // 1. 找到中点，slow 会停在中间位置（奇数）或中间偏右位置（偶数）
//     while (fast && fast->next && fast->next->next) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     // 2. 从 slow 之后开始反转后半段链表
//     Node* prev = nullptr;
//     Node* curr = slow->next;
//     while (curr) {
//         Node* next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }

//     // 断开前半段和后半段
//     slow->next = nullptr;

//     // 3. 合并前后两个链表（head->next 为前半部分起点，prev 为后半部分反转后的头）
//     Node* first = head->next;
//     Node* second = prev;

//     while (second) {
//         Node* tmp1 = first->next;
//         Node* tmp2 = second->next;

//         first->next = second;
//         second->next = tmp1;

//         first = tmp1;
//         second = tmp2;
//     }
// }

int main(){
    Node *list;
    list = initList();
    insertHead(list, 666);
    insertHead(list, 777);
    insertHead(list, 888);
    // insertTail(list, 234);
    // insertTail(list, 299);
    // insertTail(list, 123);
    listNode(list);
    insertNode(list, 2, 999);
    listNode(list);
    deleteNode(list, 4);
    listNode(list);
    printf("链表的长度为%d\n", lenList(list));
    // freeList(list);
    // printf("链表的长度为%d\n", lenList(list));
    findNodeFS(list, 3);
    Node *L = reverseList(list);
    listNode(L);
    delMiddleNode(L);
    listNode(L);

    L = initList();
    insertTail(L, 1);
    insertTail(L, 2);
    insertTail(L, 3);
    insertTail(L, 4);
    insertTail(L, 5);
    insertTail(L, 6);
    insertTail(L, 7);
    listNode(L);
    reorderList(L);
    listNode(L);
    return 0;
}