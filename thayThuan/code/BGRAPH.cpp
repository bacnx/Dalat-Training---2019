#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
const int maxn = 600050;

int n, m;
vector<int> a[maxn];

bool True = true;
queue<int> d;
bool cx[maxn];
int cl[maxn];
int c, l;

void DFS(int u0) {
    d.push(u0);
    cx[u0] = false;
    cl[u0] = 1;

    while (!d.empty()) {
        int u = d.front(); d.pop();
        if (cl[u] == 1) c++; else l++;
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i];
            if (cl[v] != 0) {if (cl[v] == cl[u]) { True = false; return ; }}
            else if (cx[v]) {
                cl[v] = cl[u] * -1;
                d.push(v);
                cx[v] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("bgraph.inp", "r", stdin);
    freopen("bgraph.out", "w", stdout);

    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; i++){
        cx[i] = true;
        cl[i] = 0;
    }

    ll res = 1;
    for (int i = 1; i <= n; i++) if (cx[i]) {
            c = l = 0;
            DFS(i);
            if (!True) { cout << "0"; return 0; }

            if (c + l == 1) {res *= 3; continue; }
            ll powC = 1; while (c--) powC = powC * 2 % MOD;
            ll powL = 1; while (l--) powL = powL * 2 % MOD;
            res = res * (powC + powL) % MOD;
        }

    cout << res;

    return 0;
}