#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node *next;
} Node;

//初始化链表
Node *initList(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

//单链表--头插法(的顺序和排列的顺序是相反的)
int insertHead(Node *L, ElemType e){//L相当于头节点
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
    return 1;
}

//单链表--尾插法
Node *get_tail(Node *L){
    Node *p = L;
    while(p->next != NULL){
        p = p->next;
    }
    return p;
}//先找尾巴
Node *insertTail(Node *tail, ElemType e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

//单链表--在指定位置插入数据
int insertNode(Node *L, int pos, ElemType e){
    Node *p = L;
    int i = 0;
    while(i < pos - 1){
        p = p->next;
        i++;
        if(p == NULL){
            return 0;
        }
    }

    Node *q = new Node;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

//单链表--删除节点
int deleteNode(Node *L, int pos){
    Node *p = L;
    int i = 0;
    // 检查pos是否合法
    if (pos < 1) {
        printf("位置不能小于1\n");
        return 0;
    }
    //移动到要删除节点的前一个位置
    while(i < pos - 1){
        p = p->next;
        i++;
        if(p == NULL){
            printf("要删除的位置超出链表范围\n");
            return 0;
        }
    }
// 此时p指向要删除节点的前一个节点
    if(p->next == NULL){
        printf("要删除的位置错误\n");
        return 0;
    }

    Node *q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

//单链表的长度（不包括头节点）
int lenList(Node *L){
    Node *p = L;
    int len = 0;
    while(p->next != NULL){
        p = p->next;
        len++;
    }
    return len;
}

//单链表--遍历
void listNode(Node *L){
    Node *p = L->next;
    while(p != NULL){
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("\n");
}

//释放链表
void freeList(Node *L){
    Node *p = L->next;
    Node *q;

    while(p != NULL){
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

int main() {
    // Node *list = initList();
    // insertHead(list, 2);
    // insertHead(list, 999);
    // insertHead(list, 243);
    // insertTail(get_tail(list), 666);
    // insertTail(get_tail(list), 777);
    // listNode(list);
    Node *list = initList();
    insertHead(list, 23);
    insertHead(list, 999);
    listNode(list);
    Node *tail = get_tail(list);
    tail = insertTail(tail, 321);
    tail = insertTail(tail, 823);
    listNode(list);
    insertNode(list, 2, 333);
    listNode(list);
    deleteNode(list, 5);
    listNode(list);
    printf("链表的长度为%d\n", lenList(list));
    freeList(list);
    listNode(list);
    printf("链表的长度为%d\n", lenList(list));

    cout << "这是一个提交测试" << endl;
    return 0;
}