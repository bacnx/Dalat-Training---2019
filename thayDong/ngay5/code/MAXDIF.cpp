// #include <bits/stdc++.h>
// using namespace std;

// const int maxn = 100005;

// int n, k, a[maxn];
// int a[maxn];
// queue<int> q;


// int main()
// {
//     ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
//     freopen("maxdif.inp", "r", stdin);
//     freopen("maxdif.out", "w", stdout);

//     cin >> n >> k;
//     for (int i = 1; i <= n; i++) scanf("%d", &a[i]); // cin >> a[i];
//     sort(a + 1, a + n + 1);

//     for (int i = 1; i <= n; i++) {

//     }

//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n, k, a[maxn];

bool check(int w) {
    a[n+1] = INT_MAX;
    int mx = 0, l = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i+1] - a[i] > w) {
            mx = max(mx, i - l);
            l = i;
        }
    }
    if (n-mx > k) return false;
    else return true;
}

void search() {
    int res;
    int l = 0, r = a[n] - a[1], mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            r = mid -1;
        }
        else l = mid + 1;
    }
    cout << res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("maxdif.inp", "r", stdin);
    freopen("maxdif.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)  cin >> a[i];

    sort(a + 1, a + n + 1);
    search();

    return 0;
}