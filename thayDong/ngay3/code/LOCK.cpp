#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll maxn = 100005;

ll n, k, s, a[maxn];

vector<vector<ll> > group;
bool cx[maxn];

void init_cx() {
    for (ll i = 0; i < n; i++) cx[i] = true;
}

void init_group() {
    for (ll i = 0; i < n; i++) {
        if (cx[i]) {
            vector<ll> t;
            ll j = i;

            while (cx[j]) {
                cx[j] = false;
                t.push_back(a[j]);
                j = (j + s) % n;
            }

            group.push_back(t);
        }
    }
}

ll tep(vector<ll> g) {
    ll result = 0;
    sort(g.begin(), g.end());

    ll mid = g[g.size()/2];
    for (ll i = 0; i < g.size(); i++)
        result += abs(g[i] - mid);
    
    return result;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    freopen("lock.inp", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n >> k >> s;
    for (ll i = 0; i < n; i++) scanf("%lld", &a[i]);

    ll res = 0;
    init_cx();
    init_group();
    for (ll i = 0; i < group.size(); i++)
        res += tep(group[i]);

    cout << res;

    return 0;
}