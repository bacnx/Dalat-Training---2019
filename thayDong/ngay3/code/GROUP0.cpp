#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 51;

int n, k, a[maxn];

bool check(int g) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > g) sum += g;
        else sum += a[i];
    }
    if (sum >= g*k) return true;
    else return false;
}

int search(int l, int r) {
    int mid, res;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    freopen("group0.inp", "r", stdin);
    freopen("group0.out", "w", stdout);

    cin >> n >> k;
    int mx = 0;
    for (int i = 1; i <= n; i++) 
    {cin >> a[i]; mx = max(mx, a[i]);}

    cout << search(0, mx*n);
    
    return 0;
}