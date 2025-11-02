#include <vector>
#include <functional>
#define ll long long
using namespace std;

//色付き探索(DFS)でサイクル検出
int n;
vector<ll> f(n);

vector<int> color(n, 0); // 0:未訪問, 1:探索中, 2:探索済み
int cycleCount = 0;

function<void(int)> dfs = [&](int v){
    color[v] = 1;
    int to = f[v];
    if(color[to] == 0){
        dfs(to);
    } else if(color[to] == 1){
        // 再び探索中のノードに戻った => サイクル検出
        cycleCount++;
    }
    color[v] = 2;
};