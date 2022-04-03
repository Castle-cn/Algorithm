//求解图的单源最短路径

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define N 6  //图顶点的个数
using namespace std;

int dist[N];  //定义从源点到顶点i的最短路径长度
int pre[N];   //从源点到顶点i的最短路径中顶点i的前驱结点
int v = 0;
struct Node {
    //顶点序号
    int no;
    //到此顶点的权重
    int weight;
};
//采用领接表来存储图
vector<Node> nodes[N];

//采用广度优先来搜索最短路径
void Bfs() {
    memset(dist, INF, sizeof(dist));  //初始化dist
    queue<Node> q;
    Node e = {v, 0};
    q.push(e);  //源顶点入队
    dist[v] = 0;
    pre[v] = 0;
    while (!q.empty()) {
        e = q.front();
        q.pop();
        vector<Node> node = nodes[e.no];
        for (Node n : node) {
            if (dist[n.no] > dist[e.no] + n.weight) {
                q.push(n);
                dist[n.no] = dist[e.no] + n.weight;
                pre[n.no] = e.no;
            }
        }
    }
}

void Printres() {
    for (int i = 1; i < N; i++) {
        if (dist[i] != INF) {
            cout << "从源点" << v << "到顶点" << i
                 << "的最短路径长度:" << dist[i] << " ";
            cout << "路径:";
            int j = i;
            vector<int> res;
            res.push_back(j);
            while (pre[j] != v) {
                res.push_back(pre[j]);
                j = pre[j];
            }
            res.push_back(v);
            reverse(res.begin(), res.end());
            for (int k : res) {
                cout << k << " ";
            }
            cout << endl;
        } else {
            cout << "从源点" << v << "到顶点" << i << "没有路径" << endl;
        }
    }
}

int main() {
    //初始化邻接表
    nodes[0].push_back({2, 10});
    nodes[0].push_back({4, 30});
    nodes[0].push_back({5, 100});
    nodes[1].push_back({2, 4});
    nodes[2].push_back({3, 50});
    nodes[3].push_back({5, 10});
    nodes[4].push_back({3, 20});
    nodes[4].push_back({5, 60});
    Bfs();
    Printres();
    return 0;
}