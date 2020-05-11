#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 110;

int n, k;
string a[maxn][maxn];
set<string> d;


int main()
{
    freopen("word.inp", "r", stdin);
    freopen("word.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) 
            cin >> a[i][j];
    
    cin >> k;
    string s;
    for (int i = 1; i <= k; i++) {
        cin >> s;
        d.insert(s);
    }

    ll result = 0;
    string str;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            str = "";
            for (int l = j; l <= n; l++) {
                str += a[i][l];
                result += d.count(str);
            }
        }
    }

    cout << result;

    return 0;
}