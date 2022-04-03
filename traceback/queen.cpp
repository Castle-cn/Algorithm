#include <iostream>
using namespace std;
// #define N 20
// int q[N];

//判断(i,j)位置是否可以放置棋子,q为每一行所放置的列号
bool Place(int i, int j, int q[]) {
    if (i == 1)
        return true;
    else {
        for (int k = 1; k < i; k++) {
            if (j == q[k] || (abs(q[k] - j) == abs(i - k)))
                return false;
        }
        return true;
    }
}

void Queen(int i, int n, int q[]) {
    if (i > n) {
        for (int k = 1; k <= n; k++)
            printf("(%d,%d)", k, q[k]);
        cout << endl;
    } else {
        for (int j = 1; j <= n; j++) {
            if (Place(i, j, q)) {
                q[i] = j;
                Queen(i + 1, n, q);
            }
        }
    }
}

int main() {
    int q[21];
    Queen(1, 20, q);
    return 0;
}