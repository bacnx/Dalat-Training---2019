#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int maxn = 10040;

int n, T;
ii a[maxn];
vector<int> h;

bool cmp(const ii &a, const ii &b) { return a.first > b.first; }

int main()
{
    freopen("bank.inp", "r", stdin);
    freopen("bank.out", "w", stdout);

    cin >> n >> T;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a +1, a+n+1, cmp);

    int res = 0;
    int t = 0, i = 1;
    while (--T >= 0 && i <= n) {
        while (a[i].first >= T && i <= n) {
            h.push_back(a[i].second); push_heap(h.begin(), h.end());
            i++;
        }
        if (!h.empty()) {res += h.front(); pop_heap(h.begin(), h.end()); h.pop_back();}
    }
    cout << res;
    
    return 0;
}