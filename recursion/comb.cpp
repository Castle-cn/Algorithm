#include <iostream>
using namespace std;

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void perm(int a[], int n, int i) {
    if (i == n - 1)
        display(a, n);
    else {
        for (int j = i; j < n; j++) {
            swap(a[i], a[j]);
            perm(a, n, i + 1);
            swap(a[i], a[j]);
        }
    }
}

int main() {
    int a[] = {1, 2, 3, 4};
    perm(a, 4, 0);
    return 0;
}