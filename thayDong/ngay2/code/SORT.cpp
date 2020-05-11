#include<bits/stdc++.h>
using namespace std;

const int maxn = 200050;

int n, a[maxn];
int mx[maxn], mn[maxn];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    freopen("sort.inp", "r", stdin);
    freopen("sort.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    mn[n] = a[n];
    for (int i = n-1; i > 0; i--)
        mn[i] = min(mn[i+1], a[i]);

    int res = 1;
    mx[1] = a[1];
    for (int i = 2; i <= n; i++) {
        mx[i] = max(mx[i-1], a[i]);
        if (mx[i-1] <= mn[i]) res++;
    }

    cout << res;
    
    return 0;
}