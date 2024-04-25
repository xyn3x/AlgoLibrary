#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
vector<int> g[N];
int fup[N], tin[N], timer;
bool used[N];

// Bridge 
void dfs(int v, int p = -1) {
    fup[v] = tin[v] = timer++;
    used[v] = 1;
    for(auto to : g[v]) {
        if(to == p) continue;
        if(used[to]) fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if(fup[to] > tin[v]) {
                cout << v << " " << to << "\n";
            }
        }
    }
}

//Cutpoint
void dfs(int v, int p = -1) {
    fup[v] = tin[v] = timer++;
    used[v] = 1;
    int child = 0;
    for(auto to : g[v]) {
        if(to == p) continue;
        if(used[to]) fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if(fup[to] >= tin[v] && p != -1) {
                cout << v << "\n";
            }
            child++;
        }
    }
    if(p == -1 && child > 1) {
        cout << v << "\n";
    } 
}

int main() {
    return 0;
}