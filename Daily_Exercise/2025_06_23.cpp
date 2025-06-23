// 排序
#include <iostream>
using namespace std;

// 直接插入排序 O(n^2)
void InsertSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];// 保存当前要插入的元素
        int j = i - 1;
        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];//后移
            j--;//当j>=0时，继续后移
        }
        a[j + 1] = key;
    }
}

// 折半插入排序 O(n^2)
// 折半查找 O(logn)
void BinaryInsertSort(int a[], int n)
{
    for(int i = 1; i < n; i++) {
        int key = a[i];

        int j;
        for(j = i - 1; j >= 0; j--){
            if(a[j] > key) {
                a[j + 1] = a[j];
            }
            else break;
        }
        
        a[j + 1] = key;
    }
}








//冒泡排序
void bubbleSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

//快速排序
void quickSort(int r[], int s, int t){
    int i = s, j = t, x = r[s];
    while(i < j){
        while(i < j && r[j] >= x) j--;
        if(i < j) r[i++] = r[j];
        while(i < j && r[i] < x) i++;
        if(i < j) r[j--] = r[i];
    }
    r[i] = x;//i和j相等
    
    if(i - 1 > s) quickSort(r, s, i - 1);
    if(j + 1 < t) quickSort(r, j + 1, t);
}

//选择排序
void selectionSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[minIndex]){
                minIndex = j;
            }
        }

        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

//堆排序
void heapSort(int a[], int n){
    // 建堆
    for(int i = n / 2 - 1; i >= 0; i--){
        adjustHeap(a, i, n);// 调整堆
    }
    // 排序
    for(int i = n - 1; i >= 0; i--){
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        adjustHeap(a, 0, i);// 调整堆
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // InsertSort(a, n);
    // BinaryInsertSort(a, n);
    // quickSort(a, 0, n - 1);
    // selectionSort(a, n);
    heapSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}