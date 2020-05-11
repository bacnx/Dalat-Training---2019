#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 100005;

int n, delta, a[maxn], f[maxn];
vector<int> lis;

int32_t main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("right.inp", "r", stdin);
    freopen("right.out", "w", stdout);

    cin >> n >> delta;
    for (int i = 1; i <= n; i++) cin >> a[i];

    f[1] = 1; lis.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        if (lis.back() < a[i]) {lis.push_back(a[i]); f[i] = lis.size();}
        else {
            int k = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[k] = a[i];
            f[i] = k+1;
        }
        
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] + f[i] * delta << endl;

    return 0;
}