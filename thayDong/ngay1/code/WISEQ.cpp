#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int oo = INT_MAX;
const int maxn = 50040;

int n, w, a[maxn];
int f[501][501];
vector<int> b;

// int t[501][501];
void sub1() {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) 
            {f[i][j] = oo;}
    f[0][0] = 0;
    a[0] = -oo;

    for (int i = 1; i <= n; i++)
    for (int l = 1; l <= i; l++){
        // f[i][l] = f[i-1][l];
        // t[i][l] = i-1;
    for (int j = 0; j < i; j++){
        if (f[j][l-1] < oo && a[j] < a[i])
            // {
            //     if (f[i][l] > f[j][l-1] + a[i]) 
            //         // t[i][l] = j; 
            f[i][l] = min(f[i][l], f[j][l-1] + a[i]);
            // }
    }}

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         // cout << f[i][j] << " ";
    //         cout << t[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << f[i][j] << "\t";
    //         // cout << t[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
        // cout << f[i][j] << "\t";
        if (f[i][j] <= w) res = max(res, j);
        }
    // cout << endl;
    }
        
    cout << res;
}

void sub2() {
    b.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        if (a[i] > b.back()) b.push_back(a[i]);
        else b[lower_bound(b.begin(), b.end(), a[i]) - b.begin()] = a[i];
    }
    cout << b.size();
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    freopen("wiseq.inp", "r", stdin);
    freopen("wiseq.out", "w", stdout);

    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
        
    if (n <= 500) sub1();
    else sub2();

    return 0;
}