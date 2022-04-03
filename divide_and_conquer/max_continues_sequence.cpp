//求解最大连续子序列和
#include <iostream>
using namespace std;

//返回 a b c 中最大值
long Max3(long a, long b, long c) {
    if (a < b)
        a = b;
    if (a > c)
        return a;
    else
        return c;
}

long MaxSubSum(int a[], int left, int right) {
    long maxLeftSum, maxRightSum;
    long leftBorderSum = 0, rightBorderSum = 0;
    long maxLeftBorderSum = 0, maxRightBorderSum = 0;
    if (left == right) {
        if (a[left] > 0)
            return a[left];
        else
            return 0;
    }
    int mid = (left + right) / 2;
    maxLeftSum = MaxSubSum(a, left, mid);        //求解左边的最大连续子序列之和
    maxRightSum = MaxSubSum(a, mid + 1, right);  //求解右边的最大连续子序列之和
    //求解中间最大连续子列和
    for (int i = mid; i >= left; i--) {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }
    for (int j = mid + 1; j <= right; j++) {
        rightBorderSum += a[j];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    return Max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int main() {
    int a[6] = {-2, 11, -4, 13, -5, -2};
    int b[12] = {-6, 2, 4, -7, 5, 3, 2, -1, 6, -9, 10, -2};
    cout << MaxSubSum(a, 0, 5) << endl;
    cout << MaxSubSum(b, 0, 11);
    return 0;
}