#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

typedef pair<int, int> ii;
#define fr first
#define sc second

bool cmp(const ii &a, const ii &b) {
    int laia = a.second - a.first;
    int laib = b.second - b.first;
    
    if (laia * laib < 1) return laia > laib;
    if (laia > 0) return a.first < b.first;
    if (laia < 0) return a.second > b.second;
}

int n;
ii a[maxn];

int main() 
{
    freopen("prjchain.inp", "r", stdin);
    freopen("prjchain.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first;
    for (int i = 1; i <= n; i++) cin >> a[i].second;
    
    sort(a + 1, a + n + 1, cmp);

    int res = 0, money = 0;
    for (int i = 1; i <= n; i++) {
        money -= a[i].first;
        res = min(res, money);
        money += a[i].second;
    }

    cout << -res;


    return 0;
}