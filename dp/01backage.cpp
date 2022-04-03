//动态规划法
//求解0/1背包问题的算法
#include <stdio.h>
#include <iomanip>
#include <iostream>
using namespace std;
#define max(x, y) ((x) > (y) ? (x) : (y))
#define MAXN 20   //最多物品数
#define MAXW 100  //最大限制重量
//问题表示
// int n = 5, W = 100;                     // 5种物品,限制重量不超过100
// int w[MAXN] = {0, 10, 20, 30, 40, 50};  //下标0不用
// int v[MAXN] = {0, 20, 30, 66, 40, 60};  //下标0不用
int n = 5, W = 10;                 // 5种物品,限制重量不超过10
int w[MAXN] = {0, 2, 2, 6, 5, 4};  //下标0不用
int v[MAXN] = {0, 6, 3, 5, 4, 6};  //下标0不用
//求解结果表示
int dp[MAXN][MAXW];
int x[MAXN];
int maxv;  //存放最优解的总价值

void Knap()  //动态规划法求0/1背包问题
{
    int i, r;
    for (i = 0; i <= n; i++)  //置边界条件dp[i][0]=0
        dp[i][0] = 0;
    for (r = 0; r <= W; r++)  //置边界条件dp[0][r]=0
        dp[0][r] = 0;
    for (i = 1; i <= n; i++) {
        for (r = 1; r <= W; r++)
            if (r < w[i])
                dp[i][r] = dp[i - 1][r];
            else
                dp[i][r] = max(dp[i - 1][r], dp[i - 1][r - w[i]] + v[i]);
    }
}
void Buildx()  //回推求最优解
{
    int i = n, r = W;
    maxv = 0;
    while (i >= 0)  //判断每个物品
    {
        if (dp[i][r] != dp[i - 1][r]) {
            x[i] = 1;  //选取物品i
            cout << "       选取物品" << i << endl;
            maxv += v[i];  //累计总价值
            r = r - w[i];
        } else
            x[i] = 0;  //不选取物品i
        i--;
    }
}
int main() {
    cout << endl << "动态规划   数科191    谭堡烽" << endl;
    cout << "***************************************" << endl;
    Knap();
    cout << "\n求解dp矩阵:" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "     ";
        for (int j = 0; j <= W; j++) {
            cout << setw(2) << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n逆推过程:" << endl;
    Buildx();

    printf("\n求解结果(最优方案)\n");  //输出结果
    printf("    选取的物品: ");
    for (int i = 1; i <= n; i++)
        if (x[i] == 1)
            printf("%d ", i);
    printf("\n");
    printf("    总价值=%d\n", maxv);
    return 0;
}
