#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const int maxn = 1000060;

ll f[maxn], dx[maxn], gt[maxn];
int n = 0;
int a[maxn];

int main()
{
    freopen("brorder.inp", "r", stdin);
    freopen("brorder.out", "w", stdout);

    int q;
    cin >> q;

    string s;
    for (int i = 1; i <= q; i++) {
        cin >> s;
        a[i] = s.size()/2;
        n = max(n, a[i]);
    }

    for (int i = 1; i <= n; i++)
        gt[i] = (gt[i-1]*i) % MOD;

    f[1] = 1;
    dx[0] = 1; dx[1] = 1;
    for (int i = 2; i <= n; i++){
        f[i] = f[i-1];
        for (int j = 1; j <= i/2; j++) {
            
        }
        dx[i] = dx[i-2] + dx[i-1];
    }

    for (int i = 1; i <= q; i++)
        cout << f[a[i]] << endl;
    

    return 0;
}