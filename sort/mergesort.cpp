#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

//归并排序
//将两个有序数组进行归并
void Merge(int a[], int low, int mid, int high) {
    vector<int> temp;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i++]);
        } else {
            temp.push_back(a[j++]);
        }
    }
    if (i <= mid) {
        for (; i <= mid; i++) {
            temp.push_back(a[i]);
        }
    }
    if (j <= high) {
        for (; j <= high; j++) {
            temp.push_back(a[j]);
        }
    }
    for (int x : temp) {
        a[low++] = x;
    }
}

//自顶向下归并排序
void MergeSort_1(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort_1(a, low, mid);
        MergeSort_1(a, mid + 1, high);

        cout << "待归并子集：";
        cout << "[";
        for (int i = low; i <= high; i++) {
            if (i == mid + 1) {
                cout << "]";
                cout << "[";
            }
            cout << a[i] << " ";
        }
        cout << "]";
        cout << endl;

        Merge(a, low, mid, high);
    }
}

//自底向上归并排序
void MergeSort_2(int a[], int n) {
    //外层循环是为了确定每次合并的长度(1,2,4,8)
    for (int length = 1; length < n; length = 2 * length) {
        int i;
        //内层循环是为了确定每一组(两个)的第一个的起始下标i
        for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length) {
            cout << "待归并子集：";
            cout << "[";
            for (int j = i; j <= i + 2 * length - 1; j++) {
                if (j == i + length - 1 + 1) {
                    cout << "]";
                    cout << "[";
                }
                cout << a[j] << " ";
            }
            cout << "]";
            cout << endl;

            Merge(a, i, i + length - 1, i + 2 * length - 1);
        }

        //如果还有余下的子表(一定是两个),后者的长度小于length
        if (i + length - 1 < n) {
            cout << "待归并子集：";
            cout << "[";
            for (int j = i; j <= n - 1; j++) {
                if (j == i + length - 1 + 1) {
                    cout << "]";
                    cout << "[";
                }
                cout << a[j] << " ";
            }
            cout << "]";
            cout << endl;

            Merge(a, i, i + length - 1, n - 1);
        }
    }
}

int main() {
    int a[] = {2, 5, 1, 7, 10, 6, 9, 4, 3, 8};
    cout << endl << "自底向上归并算法   数科191    谭堡烽" << endl;
    cout << "***********************************" << endl;
    cout << "排序前：";
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    // MergeSort_1(a, 0, 9);
    MergeSort_2(a, 10);

    cout << "排序后：";
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}