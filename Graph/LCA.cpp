#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
vector<int> g[N];
int tin[N], tout[N], timer, par[N][20], lg;

void dfs(int v, int p) {
    tin[v] = timer++;
    par[v][0] = p;
    for(int i = 1; i <= lg; ++i) par[v][i] = par[par[v][i - 1]][i - 1];
    for(auto to : g[v]) {
        if(to != p) dfs(to, v);
    }
    tout[v] = timer++;
}

bool isGood(int a, int b) {
    return tin[a] >= tin[b] && tout[a] <= tout[b];
}

int lca(int a, int b) {
    if(isGood(a, b)) return b;
    if(isGood(b, a)) return a;
    for(int i = lg; i >= 0; --i) {
        if(!isGood(par[a][i], b)) {
            a = par[a][i];
        }
    }
    return par[a][0];
}

int main() {
    int n; cin >> n;
    while((1 << lg) <= n) lg++;
    return 0;
}