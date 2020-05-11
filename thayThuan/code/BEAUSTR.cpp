#include <bits/stdc++.h>
using namespace std;

const int maxn = 500050;

int n;
int s[maxn];
vector<int> vt1, dd0;

int f(int k) {
    int result = 0;
    int l, r, mid, x = 0, rt;
    for (int i = 1; i < vt1.size();) {
        l = i, r = vt1.size()-1, rt = -1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (s[vt1[mid]] - s[vt1[x]] >= k) {
                rt = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        if (rt == -1) break;
        result++;
        x = rt;
        i = rt + 1;
    }
    return result-1;
}

int main()
{
    freopen("beaustr.inp", "r", stdin);
    freopen("beaustr.out", "w", stdout);

    string str;
    cin >> n >> str;
    str = " " + str;

    s[0] = 0, vt1.push_back(0);
    for (int i = 1; i < str.size(); i++)
        if (str[i] == '0') s[i] = s[i-1] + 1;
        else { s[i] = s[i-1]; vt1.push_back(i); }
    vt1.push_back(n+1); s[n+1] = s[n];

    int res = vt1.size()-2;
    for (int i = 1; i <= n; i++) {
        int k = f(i);
        if (k > 0) res = max(res, (k+1)*(i+1)-1);
    }

    cout << res;


    return 0;
}