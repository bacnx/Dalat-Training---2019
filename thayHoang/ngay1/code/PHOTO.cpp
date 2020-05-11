#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000006;


int n, a[maxn];
int p[maxn][6];

bool cmp(const int &x, const int &y) {
    int cnt = 0;
    for (int i = 1; i <= 5; i++) 
        if (p[x][i] < p[y][i]) cnt++;
    return cnt >= 3;
}

int main() {
    freopen("photo.inp", "r", stdin);
    freopen("photo.out", "w", stdout);

    cin >> n;
    int t;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> t;
            p[t][i] = j;
        }
    }
    
    for (int i = 1; i <= n; i++) a[i] = i;

    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) cout << a[i] << " ";


    return 0;
}