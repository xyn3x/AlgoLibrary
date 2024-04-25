#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
struct segTree {
    class Node {
        // variables
        public:
        int mx, sum;
        Node() { mx = sum = 0; }
        Node(int num) { mx = sum = num; }
    } t[N << 2];
    int lz[N << 2];

    Node merge(Node x, Node y) {
        // function for merging nodes in the tree
        Node cur = *new Node();
        cur.mx = max(x.mx, y.mx);
        cur.sum = x.sum + y.sum;
        return cur;
    }

    void build(int tl = 1, int tr = N, int v = 1) {
        if(tl == tr) {
            // assign variables to the seg tree
            t[v] = *new Node();
        }
        else {
            int mid = (tl + tr) >> 1;
            build(tl, mid, v * 2);
            build(mid + 1, tr, v * 2 + 1);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }

    void lazyFunction(int tl, int tr, int v) {
        // function for updating in range
        t[v].mx = (tr - tl + 1) * lz[v];
        lz[v] = 0;
    }

    void lazy(int tl, int tr, int v) {
        // lazy propogation
        if(!lz[v]) return;
        if(tl != tr) {
            lz[v * 2] += lz[v];
            lz[v * 2 + 1] += lz[v];
        }
        lazyFunction(tl, tr, v);
    }

    void upd(int pos, int num, int tl = 1, int tr = N, int v = 1) {
        //lazy(tl, tr, v);
        if(tl == tr) {
            t[v].mx = num;
            return;
        }
        int mid = (tl + tr) >> 1;
        if(mid >= pos) upd(pos, num, tl, mid, v * 2);
        else upd(pos, num, mid + 1, tr, v * 2 + 1);
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }

    void updRange(int l, int r, int num, int tl = 1, int tr = N, int v = 1) {
        lazy(tl, tr, v);
        if(tl > r || tr < l) return;
        if(tl >= l && tr <= r) {
            lz[v] += num;
            lazy(tl, tr, v);
            return;
        }
        int mid = (tl + tr) >> 1;
        updRange(l, r, num, tl, mid, v * 2); updRange(l, r, num, mid + 1, tr, v * 2 + 1);
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }

    Node get(int l, int r, int tl = 1, int tr = N, int v = 1) {
        //lazy(tl, tr, v);
        if(tl > r || tr < l) return 0;
        if(tl >= l && tr <= r) return t[v];
        int mid = (tl + tr) >> 1;
        return merge(get(l, r, tl, mid, v * 2), get(l, r, mid + 1, tr, v * 2 + 1));
    }
};
segTree t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}
