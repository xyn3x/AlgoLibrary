#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

#define ff first
#define ss second

vector<pair<int, int>> g[N];
int dist[N];

void dijkstra(int v) {
    set<pair<int, int>> q = {{0, v}};
    for(int i = 1; i < N; ++i) dist[i] = 1e9 + 7;
    dist[v] = 0;
    while(!q.empty()) {
        int cur = (*q.begin()).ss, d = (*q.begin()).ff;
        q.erase(q.begin());
        for(auto to : g[v]) {
            if(dist[to.ff] > (d + to.ss)) {
                q.erase({dist[to.ff], to.ff});
                dist[to.ff] = d + to.ss;
                q.insert({dist[to.ff], to.ff});
            }
        }
    }
}

int main() {
    return 0;
}