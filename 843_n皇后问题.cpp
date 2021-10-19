//
// Created by MapMap on 10/19/2021.
//

#include <iostream>
using namespace std;

int n;
const int N = 10;
int path[N];
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {
    if(u == n) { //找到最后一层的时候
        for(int i = 0; i < n; ++i) puts(g[i]); //输出该层的所有字母
        puts("");
        return;
    }
    for(int i = 0; i < n; ++i) {
        //判断三个方向是否存在皇后，行、正斜线、反斜线
        //x = u, y = i; 注意递归完成了之后要把bool数组的元素值还原
        //n-u+i的由来:y=x+b -> b=y-x; y=-x+b -> b=y+x. y-x不一定大于0,所有加上一个n的长度
        if(!col[i] && !dg[u+i] && !udg[n-u+i]) {
            g[u][i] = 'Q';
            col[i] = dg[u+i] = udg[n-u+i] = true;
            dfs(u+1);
            col[i] = dg[u+i] = udg[n-u+i] = false;
            g[u][i] = '.';
        }
    }
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) g[i][j] = '.';
        dfs(0);
        return 0;
}
