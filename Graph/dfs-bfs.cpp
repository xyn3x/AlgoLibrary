#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

vector<int> g[N];
bool used[N];
void dfs(int v) {
    used[v] = 1;
    for(auto to : g[v]) {
        if(!used[to]) dfs(to);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    used[v] = 1;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto to : g[v]) {
            if(!used[to]) {
                used[to] = 1;
                q.push(to);
            }
        }
    }
}

int main() {

}