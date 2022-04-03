#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

void disp(int a[], int n, int i) {
    cout << "   第" << i << "次交换：";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

//冒泡排序
void BubbleSort(int a[], int n) {
    // exchange 防止做无用功
    bool exchange = false;
    for (int i = 0; i < n; i++) {
        cout << "第" << i + 1 << "次排序过程：" << endl;
        int count = 1;
        for (int j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                swap(a[j], a[j - 1]);
                disp(a, 10, count++);
                exchange = true;
            }
        }
        //如果这一趟没发生交换, 说明已经排序好了
        if (!exchange)
            return;
    }
}

int main() {
    int a[] = {2, 5, 1, 7, 10, 6, 9, 4, 3, 8};
    cout << endl << "冒泡排序   数科191    谭堡烽" << endl;
    cout << "***********************************" << endl;
    cout << "排序前：";
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
    BubbleSort(a, 10);
}
