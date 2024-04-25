#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct Line {
    ll m, c;
    ll get(ll x) {
        return m * x + c;
    }
};
struct node {
    Line line;
    node* left = nullptr;
    node* right = nullptr;
    node(Line line): line(line) {}
    void add(Line cur, int l, int r, int L, int R) {
        if(l > r) return;
        if(l > R || r < L) return;
        int m = (l + 1 == r ? l : (l + 1) >> 1);
        if(l >= L && r <= R) {
            bool lef = cur.get(l) < line.get(l);
            bool mid = cur.get(m) < line.get(m);
            if(mid) swap(line, cur);
            if(l == r) return;
            if(lef != mid) {
                if(left == nullptr) left = new node(cur);
                else left -> add(cur, l, m, L, R);
            }
            else {
                if(right == nullptr) right = new node(cur);
                else right -> add(cur, m + 1, r, L, R);
            }
            return;
        }
        if(max(l, L) <= min(m, R)) {
            if(left == nullptr) {
                Line em = *new Line();
                em.m = 0, em.c = 2e18;
                left = new node(em);
            }
            left -> add(cur, l, m, L, R);
        }
        if(max(m + 1, L) <= min(r, R)) {
            if(right == nullptr) {
                Line em = *new Line();
                em.m = 0, em.c = 2e18;
                right = new node(em);
            } 
            right -> add(cur, m + 1, l, L, R);
        }
    }
    ll get(ll x, int l, int r, int L, int R) {
        if(l > r) return 2e18;
        if(l > R || r < L) return 2e18;
        int m = (l + 1 == r ? l : (l + 1) >> 1);
        if(l >= L && r <= R) {
            ll res = line.get(x);
            if(l < r) {
                if(x <= m && left != nullptr) {
                    res = min(res, left -> get(x, l, m, L, R));
                } 
                if(x > m && right != nullptr) {
                    res = min(res, right -> get(x, m + 1, l, L, R));
                }
            }
            return res;
        }
        ll res = 2e18;
        if(max(l, L) <= min(m, R)) {
            if(left == nullptr) {
                Line em = *new Line();
                em.m = 0, em.c = 2e18;
                left = new node(em);
            }
            res = min(res, left -> get(x, l, m, L, R));
        }
        if(max(m + 1, L) <= min(r, R)) {
            if(right == nullptr) {
                Line em = *new Line();
                em.m = 0, em.c = 2e18;
                right = new node(em);
            } 
            res = min(res, right -> get(x, m + 1, r, L, R));
        }
        return res;
    }
};

struct LiChao {
    int L, R;
    node* root;
    LiChao(): L(numeric_limits<int>::min() / 2), R(numeric_limits<int>::max() / 2), root(nullptr) {}
    LiChao(int L, int R): L(L), R(R) {
        Line em = *new Line();
        em.m = 0, em.c = 2e18;
        root = new node(em);
    }
    void add_line(Line line) {
        root -> add(line, L, R, L, R);
    }
    void add(Line line, int l, int r) {
        root -> add(line, L, R, l, r);
    }
    ll get_ans(ll x) {
        return root -> get(x, L, R, L, R);
    }
    ll get_ans(ll x, int l, int r) {
        return root -> get(x, l, r, L, R);
    }
};
int main() {
    LiChao t = LiChao((int)-1e9, (int)1e9);
    
    return 0;
}