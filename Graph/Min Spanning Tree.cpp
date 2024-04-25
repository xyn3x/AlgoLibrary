#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

const int N = 3e5 + 5;
vector<pair<int, int>> g[N];
struct prims {
    vector<int> mn, sl;
    int n;
    set<pair<int, int>> q;
    vector<pair<int, int>> mst;
    prims(int n) {
        this->n = n;
        mn.resize(n + 1, 1e9 + 7);
        sl.resize(n + 1, -1);
        q.insert({0, 1});
        mn[1] = 0;
    }
    void calc() {
        for(int i = 1; i <= n; ++i) {
            if(q.empty()) {
                mst.clear();
                break;
            }
            int v = (*q.begin()).ss;
            q.erase(q.begin());
            if(sl[v] != -1) {
                mst.push_back({v, sl[v]});
            }
            for(auto to : g[v]) {
                if(to.ss < mn[to.ff]) {
                    q.erase({mn[to.ff], to.ff});
                    mn[to.ff] = to.ss;
                    sl[to.ff] = v;
                    q.insert({mn[to.ff], to.ff});
                }
            }
        }
    }
};

vector<pair<int, pair<int, int>>> G; // 1 - weight, 2 - first node, 3 - second node 
struct kruskal {
    int n;
    int cost;
    vector<int> p;
    vector<pair<int, int>> mst;
    kruskal(int n) {
        this->n = n;
        p.resize(n + 1);
        this->cost = 0;
        mst.clear();
        iota(p.begin(), p.end(), 0);
    }
    int get(int x) {
        if(p[x] == x) return x;
        else return p[x] = get(p[x]);
    }
    void merge(int a, int b) {
        a = get(a);
        b = get(b);
        if(rand() & 1) swap(a, b);
        if(a != b) p[a] = b;
    }
    void calc() {
        sort(G.begin(), G.end());
        for(auto cur : G) {
            if(get(cur.ss.ff) != get(cur.ss.ss)) {
                cost += cur.ff;
                mst.push_back(cur.ss);
                merge(cur.ss.ff, cur.ss.ss);
            }
        }
    }

};
int main() {
    return 0;
}