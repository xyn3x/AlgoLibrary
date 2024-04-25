#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int sq = 700;

struct query {
    int l, r, pos;
    bool operator < (const query &a) const {
        if(l / sq == a.l / sq) return ((l / sq) & 1) ? r > a.r : r < a.r;
        else return l / sq < a.l / sq;
    }
} q[N];

int a[N];
void addL(int pos) {
    // add Left
}

void addR(int pos) {
    // add Right
}

void delL(int pos) {
    // delete Left
}

void delR(int pos) {
    //delete Right
}
int main() {
    int n, Q; cin >> n >> Q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= Q; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].pos = i;
    }
    sort(q + 1, q + Q + 1);
    int l = 1, r = 0;
    for(int i = 1; i <= Q; ++i) {
        int L = q[i].l, R = q[i].r;
        while(l > L) addL(--l);
        while(r < R) addR(++r);
        while(l < L) delL(l++);
        while(r > R) delR(r--);
    }
    return 0;
}