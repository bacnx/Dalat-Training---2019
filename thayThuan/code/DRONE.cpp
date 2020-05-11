#include <bits/stdc++.h>
using namespace std;

const int maxn = 3030;

int n, k, a[maxn], c[maxn];
int f[maxn][101];


int main() 
{
    freopen("drone.inp", "r", stdin);
    freopen("drone.out", "w", stdout);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            f[i][j] = -1;
    for (int i = 0; i <= k; i++)
        f[n][i] = c[n];
    
    for (int i = n-1; i > 0; i--) {
        for (int kk = 1; kk <= k; kk++) {
            for (int j = i + 1; j <= min(n, i + a[i]); j++) {
                if (f[j][kk-1] != -1) 
                    f[i][kk] = max(f[i][kk], f[j][kk-1] + c[i]);
            }
        }
    }
    
    cout << f[1][k];

    return 0;
}