//任务分配
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define N 4  //待分配人数
#define M 4  //任务个数
using namespace std;

int bestx[N];       //最优待分配方案
int mincost = INF;  //最小成本
//成本矩阵
int cost[N][M] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}};

struct Node {
    int no;       //当前层数
    int best[N];  //解向量,-1代表还未分配
    int work[M];  //表示作业分配情况,0表示未分配, 1表示已分配
    int c;        //到当前结点总成本
    int lb;       //下界
};

int Bound(Node e) {
    int minsum;
    int lb = e.c;
    for (int i = 0; i < N; i++) {
        if (e.best[i] == -1) {
            minsum = INF;
            for (int j = 0; j < M; j++) {
                if (e.work[j] == 0) {
                    if (cost[i][j] < minsum) {
                        minsum = cost[i][j];
                    }
                }
            }
            lb += minsum;
        }
    }
    return lb;
}

//在所有可行子节点中进行查找, 找出lb最小的那个
Node Select(vector<Node> p) {
    int minmum = INF;
    Node t;
    for (Node n : p) {
        if (n.lb < minmum) {
            t = n;
            minmum = n.lb;
        }
    }
    return t;
}

void Bfs() {
    vector<Node> p;  //用来暂时存储所有可行子节点
    queue<Node> q;

    Node root;  //根结点
    root.no = -1;
    root.c = 0;
    memset(root.best, -1, sizeof(root.best));  //初始化分配矩阵
    memset(root.work, 0, sizeof(root.best));   //初始化任务矩阵
    root.lb = Bound(root);

    q.push(root);
    while (!q.empty()) {
        Node temp = q.front();
        q.pop();
        //如果到达搜索树的最底层
        if (temp.no == N - 1) {
            if (temp.c < mincost) {
                mincost = temp.c;
                memcpy(bestx, temp.best, N * sizeof(int));  //复制分配方案
            }
        } else {
            for (int i = 0; i < M; i++) {
                
                //如果第i个任务还未分配
                if (temp.work[i] != 1) {
                    Node temp2;
                    temp2.no = temp.no + 1;
                    temp2.c = temp.c + cost[temp2.no][i];
                    memcpy(temp2.best, temp.best, N * sizeof(int));  //复制分配方案
                    memcpy(temp2.work, temp.work, M * sizeof(int));  //复制任务分配方案
                    temp2.work[i] = 1;                               //第i个工作已分配
                    temp2.best[temp2.no] = i + 1;                    //第i号员工已分配任务
                    temp2.lb = Bound(temp2);
                    p.push_back(temp2);
                }
            }
            q.push(Select(p));  //进行剪枝
            p.clear();          //清空p
        }
    }
}

int main() {
    Bfs();
    for (int i : bestx) {
        cout << i << " ";
    }
    cout << endl;
    cout << mincost;
    return 0;
}