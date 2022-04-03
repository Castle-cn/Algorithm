#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

//快速排序
//划分算法
int Partition(int a[], int s, int t) {
    //用序列的第1个记录作为基准
    int temp = a[s];
    int i = s, j = t;
    //从序列两段交替向中间扫描, 直到i=j为止
    while (i != j) {
        //从右向左扫描, 直到找到第1个关键字小于temp的a[j]
        while (i < j && a[j] >= temp)
            j--;
        a[i] = a[j];
        //从左向右扫描, 直到找到第1个关键字大于temp的a[i]
        while (i < j && a[i] <= temp)
            i++;
        a[j] = a[i];
        //注意两个while的顺序不能交换,因为刚开始时a[s]的value被记录下来
        //但是a[j]的value没有被记录下来
    }
    a[i] = temp;

    cout << "[ ";
    for (int j = s; j < i; j++) {
        cout << a[j] << " ";
    }
    cout << "] ";

    cout << a[i] << " ";

    cout << "[ ";
    for (int j = i + 1; j <= t; j++) {
        cout << a[j] << " ";
    }
    cout << "] " << endl << endl;

    return i;
}

int c = 1;
void QuickSort(int a[], int s, int t) {
    //序列内至少存在两个元素的情况
    if (s < t) {
        cout << "第" << c++ << "次划分: ";
        int i = Partition(a, s, t);
        QuickSort(a, s, i - 1);
        QuickSort(a, i + 1, t);
    }
}

int main() {
    int b[10] = {2, 5, 1, 7, 10, 6, 9, 4, 3, 8};
    cout << endl << "快速排序   数科191    谭堡烽" << endl;
    cout << "***********************************" << endl;
    cout << "排序前：";
    for (int x : b) {
        cout << x << " ";
    }
    cout << endl << endl;

    QuickSort(b, 0, 9);

    cout << "排序后：";
    for (int i : b) {
        cout << i << " ";
    }
    return 0;
}