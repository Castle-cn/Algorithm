#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

//简单选择排序
void SelectSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                swap(a[i], a[j]);
            }
        }
    }
}

int main() {
    return 0;
}