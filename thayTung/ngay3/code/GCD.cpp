#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int maxn = 500005;

int n, k, a[maxn], st_gcd[2000006];

void init() {
    for (int i = 1; i <= n*4; i++) st_gcd[i] = 0;
}

void update(int id, int l, int r, int i, int v) {
    if (i < l || i > r) return ;
    if (l == r) { st_gcd[id] = v; return ; }
    
    int mid = (l + r) / 2;
    update(id*2, l, mid, i, v);
    update(id*2+1, mid+1, r, i, v);
    st_gcd[id] = __gcd(st_gcd[id*2], st_gcd[id*2+1]);
}

int get(int id, int l, int r, int i, int j) {
    if (i > r || j < l) return 0;
    if (l >= i && r <= j) return st_gcd[id];

    int mid = (l + r) / 2;
    return __gcd(get(id*2, l, mid, i, j), get(id*2+1, mid+1, r, i, j));
}

int32_t main() 
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("gcd.inp", "r", stdin);
    freopen("gcd.out", "w", stdout);

    cin >> n >> k;
    init();
    int t;
    for (int i = 1; i <= n; i++) { cin >> t; update(1, 1, n, i, t); }

    int res = 0;
    for (int i = 1; i <= n - k + 1; i++) res = max(res, get(1, 1, n, i, i+k-1));

    cout << res;

    return 0;
}