//二叉树的链式存储结构  
#include<iostream>
#include<queue>
using namespace std;

typedef char ElemType;

typedef struct TreeNode{
    ElemType data;
    TreeNode *lchild;
    TreeNode *rchild;

    // TreeNode(char x) : data(x), lchild(nullptr), rchild(nullptr) {}
} TreeNode;

typedef struct TreeNode *BiTree;//BiTree是指向结构体TreeNode的指针类型   struct可省略

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
    return 0;
}