#include <bits/stdc++.h>
using namespace std;

struct fenwick {
    vector<int> bit;
    int n;
    fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    fenwick(vector<int> const &a) : fenwick(a.size()) {
        for(int i = 0; i < a.size(); ++i) add(i, a[i]);
    }
    int sum(int pos) {
        if(pos < 0) return 0;
        int res = 0;
        for(; pos >= 0; pos = (pos & (pos + 1)) - 1) res += bit[pos];
        return res;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int pos, int num) {
        for(; pos < n; pos = pos | (pos + 1)) bit[pos] += num;
    }
};

int main() {
    return 0;
}