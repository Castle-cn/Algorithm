//活动安排问题
#include <algorithm>
#include <iostream>
#include <cstring>
#define MAX 51
using namespace std;

struct Action {
    int b;  //活动起始时间
    int e;  //活动结束时间
    bool operator<(const Action& s) const {
        return e <= s.e;
    }
};

bool flag[MAX];  //求解结果
void Solve(Action a[], int n) {
    memset(flag, 0, sizeof(flag));  //初始化结果数组
    sort(a, a + n);
    int preend = 0;  //前一个活动的结束时间
    for (int i = 0; i < n; i++) {
        if (a[i].b >= preend) {
            flag[i] = true;
            preend = a[i].e;
        }
    }
}

int main() {
    Action a[11] = {{1, 4},  {3, 5},  {0, 6},  {5, 7},
                    {3, 8},  {5, 9},  {6, 10}, {8, 11},
                    {8, 12}, {2, 13}, {12, 15}};
    Solve(a, 11);
    for (int i = 1; i <= 11; i++) {
        if (flag[i - 1]) {
            cout << i << " ";
        }
    }
    return 0;
}
