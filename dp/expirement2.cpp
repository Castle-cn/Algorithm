#include <cstring>
#include <iostream>
#include <string>
#define MAX 101
#define INF 0x3f3f3f3f
#define min(x, y) (x < y ? x : y)
using namespace std;

int dp[MAX][MAX];
int solve(string str) {
    memset(dp, 0, sizeof(dp));
    int n = str.size();
    //边界条件
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            dp[i][j] = INF;
            if ((str[i] == '(' && str[j] == ')') || (str[i] == '{' && str[j] == '}') ||
                (str[i] == '[' && str[j] == ']')) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            } else if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
            } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
    }
    return dp[0][n - 1];
}

int main() {
    string str = "({)}()]";
    cout << solve(str);
    return 0;
}