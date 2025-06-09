#include<iostream>
using namespace std;

#define MAXSIZE 100

typedef struct{
    int data[MAXSIZE];
    int length;
} seqlist;

//初始化顺序表
void initElem(seqlist *L){
    L->length =  0;
}

//遍历顺序表
void listElem(seqlist *L){
    for(int i = 0; i < L->length; i++){
        printf("%d ", L->data[i]);
    }
    printf("元素为%d个\n", L->length);
}

//尾部增加元素
int appendElem(seqlist *L, int e){
    if(L->length >= MAXSIZE){
        printf("顺序表已满\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

//指定位置插入元素
int insertElem(seqlist *L, int pos, int e){
    if(pos < 1 || pos > L->length){
        printf("输入错误\n");
        return 0;
    }
    for(int i = L->length - 1; i >= pos - 1; i--){
        L->data[i + 1] = L->data[i];
    }
    L->data[pos - 1] = e;
    L->length++;
    return 1;
}

//指定位置删除元素
int deleteElem(seqlist *L, int pos, int *e){
    if(pos < 1 || pos > L->length){
        printf("输入错误\n");
        return 0;
    }
    *e = L->data[pos - 1];
    if(pos < L->length){
        for(int i = pos - 1; i < L->length; i++){
            L->data[i] = L->data[i + 1];
        }
    }
    L->length--;
    return 1;
}

//查找元素在顺序表中的位置
int findElem(seqlist *L, int e){
    for(int i = 0; i < L->length; i++){
        if(L->data[i] == e){
            return i + 1;
        }
    }
    return 0;
}

int main(){
    seqlist list;

    //初始化及遍历顺序表list
    initElem(&list);
    listElem(&list);

    //添加元素及遍历
    appendElem(&list, 12);
    appendElem(&list, 24);
    appendElem(&list, 44);
    appendElem(&list, 14);
    listElem(&list);

    //插入元素及遍历
    insertElem(&list, 3, 54250);
    printf("插入后:\n");
    listElem(&list);

    //删除元素及遍历
    int deldata;
    deleteElem(&list, 5, &deldata);//此处输入保证pos位于1到L->length之间
    printf("删除的元素是%d,删除后:\n", deldata);
    listElem(&list);

    //查找
    // int finding;
    // scanf("%d", &finding);
    // printf("%d是第%d个元素\n", finding, findElem(&list, finding));
    printf("是第%d个元素\n", findElem(&list, 54250));
    return 0;
}