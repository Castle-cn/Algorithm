// 0-1 背包问题
#include <iostream>
#include <queue>
#include <vector>
#define MAXW 30
using namespace std;

int W[3] = {16, 15, 15};
double V[3] = {45, 25, 25};
int maxv = -999;
int num = 3;

//分支节点
struct Node {
    //上界
    double ub;
    //当前考虑的物品序号
    int i;
    //当前已装入的总价值
    int value;
    //当前已装入的总重量
    int weight;
};

//限界函数
double Bound(Node node, int n) {
    int i = node.i + 1;
    double v = node.value;
    int w = node.weight;
    while (w + W[i] <= MAXW && i < n) {
        w += W[i];
        v += V[i];
        i++;
    }
    //如果还有余下的物品
    if (i < n) {
        //计算物品价值密度
        v += (MAXW - w) * (V[i] / W[i]);
    }
    return v;
}

//生成左右子节点, i=0生成左子节点, i=1生成右子节点
Node Createchild(Node node, int i) {
    Node n;
    n.i = node.i + 1;
    if (i == 0) {
        n.value = node.value + V[n.i];
        n.weight = node.weight + W[n.i];
    } else {
        n.value = node.value;
        n.weight = node.weight;
    }
    n.ub = Bound(n, num);
    return n;
}

//深度优先搜索
vector<int> v;
vector<vector<int>> res;
void Dfs(Node node) {
    if (node.i < num - 1) {
        int i = node.i + 1;
        if (maxv < node.value)
            maxv = node.value;
        //判断左子树(选取)
        if (node.weight + W[i] <= MAXW) {
            //生成左孩子
            Node lnode = Createchild(node, 0);
            v.push_back(1);
            Dfs(lnode);
            v.pop_back();
        }
        //右子树先创建后判断(不选择)
        Node rnode = Createchild(node, 1);
        if (rnode.ub >= maxv) {
            v.push_back(0);
            Dfs(rnode);
            v.pop_back();
        }
    } else {
        res.push_back(v);
        cout << node.value << endl;
    }
}

//广度优先搜索
queue<Node> q;
int best[3];
int temp[3];
void Bfs(Node root) {
    q.push(root);
    while (!q.empty()) {
        Node node = q.front();
        int i = node.i + 1;
        if (maxv < node.value) {
            maxv = node.value;
            for (int k = 0; k < num; k++)
                best[k] = temp[k];
        }
        if (i < num) {
            //判断左子树
            if (node.weight + W[i] <= MAXW) {
                Node lnode = Createchild(node, 0);
                temp[i] = 1;
                q.push(lnode);
            }
            //判断右子树
            Node rnode = Createchild(node, 1);
            if (rnode.ub >= maxv) {
                temp[i] = 0;
                q.push(rnode);
            }
        }
        q.pop();
    }
    cout << maxv << endl;
}
int main() {
    Node root;
    root.i = -1;
    root.ub = Bound(root, 3);
    root.value = 0;
    root.weight = 0;
    // Dfs(root);
    // for (vector<int> v : res) {
    //     for (int n : v) {
    //         cout << n << " ";
    //     }
    //     cout << endl;
    // }
    Bfs(root);
    for (int i : best) {
        cout << i << " ";
    }

    return 0;
}