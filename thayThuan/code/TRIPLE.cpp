#include <bits/stdc++.h>
using namespace std;

const int maxn = 10040;
const int MOD = 1000000007;

int n, m, a[maxn];

int main()
{
    freopen("triple.inp", "r", stdin);
    freopen("triple.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    
    sort(a + 1, a + n + 1);

    int res = 0;
    for (int i = 2; i < n; i++) {
        int l = 1, r = n;
        int k = m - a[i];
        while (l < i && r > i) {
            if (a[l] + a[r] == k) {
                int ld = 1, rd = 1;
                while (a[l] == a[l+1] && l < i-1) {ld++; l++;}
                while (a[r] == a[r-1] && r > i+1) {rd++; r--;}
                res += ld*rd;
                res %= MOD;
                l++, r--;
                continue;
            }
            if (a[l] + a[r] > k) r--;
            else l++; 
        }
    }

    cout << res;

    return 0;
}