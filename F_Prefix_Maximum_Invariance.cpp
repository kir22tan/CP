#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
 #include "C:/Users/siddh/Desktop/cpp/currTemplate/debug_temp.h"
#else
 #define debug(...) void(1)
#endif
using namespace std;

#define kirTxn ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define all(a) a.begin(), a.end()

// ---------------- SEGMENT TREE ----------------

vector<int> seg;
int n;

void build(int idx, int l, int r, vector<int>& a){
    if(l == r){
        seg[idx] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(idx<<1, l, mid, a);
    build(idx<<1|1, mid+1, r, a);
    seg[idx] = max(seg[idx<<1], seg[idx<<1|1]);
}

// first position in [ql, qr] with value >= mx
int query(int idx, int l, int r, int ql, int qr, int mx){
    if(r < ql || l > qr) return -1;
    if(seg[idx] < mx) return -1;
    if(l == r) return l;

    int mid = (l + r) >> 1;

    int left = query(idx<<1, l, mid, ql, qr, mx);
    if(left != -1) return left;

    return query(idx<<1|1, mid+1, r, ql, qr, mx);
}

// ---------------- SOLUTION ----------------

void solution(int test_num){
    cin >> n;

    vector<int> x(n), y(n), rev;
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> y[i];

    rev = x;
    reverse(all(rev));

    seg.assign(4*n, 0);
    build(1, 0, n-1, rev);

    int ans = 0;

    for(int i = n-1; i >= 0; i--){
        if(x[i] == y[i]){
            ans += (n - i) * (i + 1);
        } else {
            int mx = max(x[i], y[i]);
            int L = n - i, R = n - 1;
            if(L <= R){
                int p = query(1, 0, n-1, L, R, mx);
                debug(i, L, R, mx, p);
                if(p != -1){
                    ans += (n - p) * (n - i);
                }
            }
        }
    }

    cout << ans << '\n';
}

// ---------------- MAIN ----------------

signed main(){
    kirTxn;
    clock_t myclock = clock();

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solution(i);
    }

    cerr << "Run time: "
         << ((double)(clock() - myclock) / CLOCKS_PER_SEC) * 1000
         << " ms" << endl;

    return 0;
}
