#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
struct vertex {
    vertex *lft, *rght;
    int sum;
    vertex(int num): lft(nullptr), rght(nullptr), sum(num) {}
    vertex(vertex *lft, vertex *rght): lft(lft), rght(rght), sum(0) {
        if(lft) sum += lft->sum;
        if(rght) sum += rght->sum;
    }
};

int a[N];
vertex* build(int tl = 1, int tr = N) {
    if(tl == tr) {
        return new vertex(a[tl]);
    }
    int mid = (tl + tr) >> 1;
    return new vertex(build(tl, mid), build(mid + 1, tr));
}

int get(int l, int r, vertex* cur, int tl = 1, int tr = N) {
    if(l > r) return 0;
    if(l == tl && r == tr) return cur->sum;
    int mid = (tl + tr) >> 1;
    return get(l, r, cur->lft, tl, mid) + get(l, r, cur->rght, mid + 1, tr);
}

vertex* upd(int pos, int num, vertex* cur, int tl = 1, int tr = N) {
    if(tl == tr) {
        return new vertex(num);
    }
    int mid = (tl + tr) >> 1;
    if(mid >= pos) return new vertex(upd(pos, num, cur->lft, tl, mid), cur->rght);
    else return new vertex(cur->lft, upd(pos, num, cur->rght, mid + 1, tr));
}

int main() {

    return 0;
}