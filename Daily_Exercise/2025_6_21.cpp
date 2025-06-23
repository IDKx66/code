//线索二叉树
#include <iostream>
using namespace std;

// 线索二叉树节点结构
typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;  // tag=0表示指针指向孩子，tag=1表示指针指向线索
} ThreadNode, *ThreadTree;

// 全局变量，始终指向刚访问过的节点
ThreadTree pre = NULL;

// 创建二叉树（按前序遍历次序输入）
void CreateTree(ThreadTree &T){
    int data;
    cin >> data;
    if(data == -1) T = NULL;  // 输入-1表示空节点
    else{
        T = new ThreadNode;
        T->data = data;
        T->ltag = 0;
        T->rtag = 0;
        CreateTree(T->lchild);  // 递归创建左子树
        CreateTree(T->rchild);  // 递归创建右子树
    }
}

// 中序遍历线索化二叉树
void InThread(ThreadTree &T){
    if(T != NULL){
        InThread(T->lchild);  // 递归线索化左子树
        
        // 处理当前节点的前驱线索
        if(T->lchild == NULL){
            T->lchild = pre;  // 左孩子为空，建立前驱线索
            T->ltag = 1;      // 标记为线索
        }
        
        // 处理前驱节点的后继线索
        if(pre != NULL && pre->rchild == NULL){
            pre->rchild = T;  // 前驱节点的右孩子为空，建立后继线索
            pre->rtag = 1;    // 标记为线索
        }
        
        pre = T;  // 更新pre为当前访问的节点
        
        InThread(T->rchild);  // 递归线索化右子树
    }
}

// 创建中序线索二叉树
void CreateInThread(ThreadTree &T){
    pre = NULL;  // 初始化pre指针
    if(T != NULL){
        InThread(T);
        // 处理最后一个节点的右指针
        if(pre->rchild == NULL){
            pre->rtag = 1;  // 最后一个节点的右线索标记
        }
    }
}

// 找到以P为根的子树中，第一个被中序遍历的节点
ThreadTree FirstNode(ThreadTree p){
    // 循环找到最左下节点
    while(p->ltag == 0) p = p->lchild;
    return p;
}

// 在中序线索二叉树中找到节点p的后继节点
ThreadTree NextNode(ThreadTree p){
    // 如果右标志为线索，直接返回后继线索
    if(p->rtag == 1) return p->rchild;
    // 否则，返回右子树中第一个被中序遍历的节点
    return FirstNode(p->rchild);
}

// 利用线索实现中序遍历
void InOrder_Thread(ThreadTree T){
    ThreadTree p = FirstNode(T);  // 找到第一个节点
    while(p != NULL){
        cout << p->data << " ";  // 访问当前节点
        p = NextNode(p);         // 找后继节点
    }
}

// 普通中序遍历（用于对比验证）
void InOrder(ThreadTree T){
    if(T != NULL){
        if(T->ltag == 0) InOrder(T->lchild);  // ltag=0时才是真正的左孩子
        cout << T->data << " ";
        if(T->rtag == 0) InOrder(T->rchild);  // rtag=0时才是真正的右孩子
    }
}

int main(){
    ThreadTree T;
    cout << "请按前序遍历顺序输入节点值，-1表示空节点：" << endl;
    CreateTree(T);
    
    cout << "中序遍历结果（线索化前）：" << endl;
    InOrder(T);
    cout << endl;
    
    CreateInThread(T);  // 线索化
    
    cout << "利用线索进行中序遍历结果：" << endl;
    InOrder_Thread(T);
    cout << endl;
    
    return 0;
}