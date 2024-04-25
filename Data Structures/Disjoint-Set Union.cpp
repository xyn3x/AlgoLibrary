#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int p[N];
int sz = 0, v[N], r[N];
int* t[N];
int get(int x) {
    if(p[x] == x) return x;
    else return p[x] = get(p[x]);
}

void upd(int* a, int b) {
    if(*a != b) {
        t[sz] = a;
        v[sz] = *a;
        *a = b;
        sz++;
    }
}

bool merge(int a, int b) {
    a = get(a);
    b = get(b);
    if(a == b) return 0;
    if(r[b] > r[a]) swap(a, b);
    upd(r + a, r[a] + r[b]);
    upd(p + b, a);
}

void rollback(int x) {
    for(; sz > x; ) {
        sz--;
        *t[sz] = v[sz];
    }
}
int main() {
    return 0;
}