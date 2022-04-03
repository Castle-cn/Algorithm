#include <iostream>
using namespace std;
//二分查找, 返回k值的下标
int BinSearch(int a[], int low, int high, int k) {
    int mid;
    if (low <= high) {
        mid = (high - low) / 2 + low;  //防止溢出
        if (a[mid] == k)
            return mid;
        if (a[mid] > k)
            return BinSearch(a, low, mid - 1, k);
        else
            return BinSearch(a, mid + 1, high, k);
    } else
        return -1;
}

//非递归版本
int BinSearch1(int a[], int n, int k) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (high - low) / 2 + low;  //防止溢出
        if (a[mid] == k)
            return mid;
        if (a[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int n = 10;
    int k = 6;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = BinSearch(a, 0, n - 1, k);
    cout << i;
    return 0;
}