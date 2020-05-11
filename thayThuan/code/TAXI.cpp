#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 30;

int n;
int a[maxn][maxn];
int x[maxn];

ll res = LLONG_MAX;
// bool cx[maxn], dx[maxn];

void Cout() {
    for (int i = 1; i <= n; i++) cout << x[i] << " ";
    cout << endl;
}

// ll kc() {
//     ll result = 0;
//     for (int i = 0; i < n; i++) 
//         result += (ll)a[x[i]][x[i+1]];
//     result += (ll)a[x[n]][0];
    
//     res = min(res, result);
// }

void hanhtrinh(int u, int d, vector<int> dx, ll kc) {
    x[d] = u;
    if (u != 0) kc += a[x[d-1]][x[d]];
    if (d == n) { res = min(res, kc + a[u][0]); return ; }
    if (kc >= res) return ;

    for (int i = dx.size()-1; i >= 0; i--){
        int v = dx[i];
        dx.erase(dx.begin() + i);
        if (v <= n/2 && v != 0) dx.push_back(v+n/2);
        hanhtrinh(v, d+1, dx, kc);
        if (v <= n/2 && v != 0) dx.pop_back();
        dx.push_back(v);
    }
}

vector<int> dx;
int main()
{
    freopen("input.txt", "r", stdin);
    
    cin >> n;
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];
    
    for (int i = 1; i <= n/2; i++) 
        dx.push_back(i);
    
    hanhtrinh(0, 0, dx, 0);

    cout << res;


    return 0;
}