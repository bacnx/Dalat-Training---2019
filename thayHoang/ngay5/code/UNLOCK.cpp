#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 200005;

ll n, m, a[maxn];
ll s[maxn];

ll kc(ll l, ll r) {
    ll mid = (l + r) / 2;
    ll res = (s[r] - s[mid]) - a[mid] * (r - mid) + a[mid] * (mid - l) - (s[mid-1] - s[l-1]);
    return res;
}

int main() 
{
    freopen("unlock.inp", "r", stdin);
    freopen("unlock.out", "w", stdout);

    cin >> n >> m;
    for (ll i = 1; i <= n; i++) cin >> a[i];

    sort(a+1, a+n+1);
    for (ll i = 1; i <= n; i++) a[n+i] = a[i] + m;

    s[0] = 0;
    for (ll i = 1; i <= 2*n; i++) s[i] = s[i-1] + a[i];
    
    ll res = LLONG_MAX;
    for (ll i = 1; i <= n; i++) res = min(res, kc(i, i+n-1));

    cout << res;

    return 0;
}