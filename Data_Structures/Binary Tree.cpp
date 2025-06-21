//二叉树的链式存储结构  
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

typedef char ElemType;

typedef struct TreeNode{
    ElemType data;
    TreeNode *lchild;
    TreeNode *rchild;

    // TreeNode(char x) : data(x), lchild(nullptr), rchild(nullptr) {}
} TreeNode;

typedef struct TreeNode *BiTree;//BiTree是指向结构体TreeNode的指针类型   struct可省略

// 二叉树节点指针栈定义
typedef struct{
    BiTree *data;  // 存储BiTree指针的数组
    int top;
} TreeStack;

#define MAXSIZE 100

// 初始化树节点栈
TreeStack* initTreeStack(){
    TreeStack *s = new TreeStack;
    s->data = new BiTree[MAXSIZE];
    s->top = -1;
    return s;
}

// 判断树节点栈是否为空
int isEmptyTree(TreeStack *s){
    if(s->top == -1){
        return 1;
    }
    else return 0;
}

// 树节点进栈
int pushTree(TreeStack *s, BiTree e){
    if(s->top >= MAXSIZE - 1){
        cout << "栈满了" << endl;
        return 0;
    }

    s->top++;
    s->data[s->top] = e;
    return 1;
}

// 树节点出栈
int popTree(TreeStack *s, BiTree *e){
    if(s->top == -1){
        cout << "栈为空" << endl;
        return 0;
    }

    *e = s->data[s->top];
    s->top--;
    return 1;
}


//先序创造二叉树
BiTree createBiTree(){
    ElemType ch;
    cin >> ch;
    BiTree T;
    if(ch == '#') T = nullptr;
    else{
        T = new TreeNode;
        T->data = ch;
        T->lchild = createBiTree();
        T->rchild = createBiTree();
    }
    return T;
}

//先序遍历:根左右
void preOrder(BiTree T){
    if (T == nullptr) return;
    cout << T->data << " ";
    preOrder(T->lchild);
    preOrder(T->rchild);
}

//中序遍历:左根右
void inOrder(BiTree T){
    if(T == nullptr) return;
    inOrder(T->lchild);
    cout << T->data << " ";
    inOrder(T->rchild);
}

//后序遍历:左右根
void postOrder(BiTree T){
    if(T == nullptr) return;
    postOrder(T->lchild);
    postOrder(T->rchild);
    cout << T->data << " ";
}

//层序遍历
void levelOrder(BiTree T){
    if(T == nullptr) return;
    queue<TreeNode*> q;
    q.push(T);
    while(!q.empty()){       
        TreeNode* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if(temp->lchild != nullptr) q.push(temp->lchild);
        if(temp->rchild != nullptr) q.push(temp->rchild);
    }
}

// 非递归前序遍历
void iterPreOrder(BiTree T){
    if(T == nullptr) return;
    TreeStack *s = initTreeStack();
    while(T != nullptr || !isEmptyTree(s)){
        while(T != nullptr){
            cout << T->data << " ";
            pushTree(s, T);
            T = T->lchild;
        }

        popTree(s, &T);
        T = T->rchild;
    }
}


//复制二叉树
void copyTree(BiTree T, BiTree &newT){
    if(T == nullptr){
        newT = nullptr;
        return;
    }
    newT = new TreeNode;
    newT->data = T->data;
    copyTree(T->lchild, newT->lchild);
    copyTree(T->rchild, newT->rchild);
}

int main(){

    // 手动构造如下二叉树：
    //         A
    //        / \
    //       B   C
    //      / \   \
    //     D   E   F


    // TreeNode* root = new TreeNode('A');
    // root->lchild = new TreeNode('B');
    // root->rchild = new TreeNode('C');
    // root->lchild->lchild = new TreeNode('D');
    // root->lchild->rchild = new TreeNode('E');
    // root->rchild->rchild = new TreeNode('F');

    BiTree root = createBiTree();

    cout << "先序遍历：";
    preOrder(root);
    cout << endl;

    cout << "中序遍历：";
    inOrder(root);
    cout << endl;

    cout << "后序遍历：";
    postOrder(root);
    cout << endl;

    cout << "层序遍历：";
    levelOrder(root);
    cout << endl;

    cout << "非递归前序遍历：";
    iterPreOrder(root);
    cout << endl;

    // cout << "中序遍历非递归：";
    // inOrderNonRecursive(root);
    // cout << endl;
    return 0;
}