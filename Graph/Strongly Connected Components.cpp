#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

vector<int> g[N], rg[N];
bool used[N];
vector<int> ord;
void dfs1(int v) {
    used[v] = 1;
    for(auto to : g[v]) {
        if(!used[to]) dfs1(to);
    }
    ord.push_back(v);
}
vector<int> comp;
void dfs2(int v)  {
    comp.push_back(v);
    used[v] = 1;
    for(auto to : rg[v]) {
        if(!used[to]) dfs2(to);
    }
}
int main() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int l, r; cin >> l >> r;
        g[l].push_back(r);
        rg[r].push_back(l);
    }
    fill(used + 1, used + n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        if(!used[i]) dfs1(i);
    }
    reverse(ord.begin(), ord.end());
    fill(used + 1, used + n + 1, 0);
    for(auto v : ord) {
        if(!used[v]) {
            dfs2(v);
            // current scc
            for(auto cur : comp) cout << cur << " ";
            cout << "\n";
            comp.clear();
        }
    }
    return 0;
}