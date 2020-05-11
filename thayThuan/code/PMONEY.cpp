#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FALSE { f = false; return 0; }
typedef long long ll;
const int maxn = 10000060;

bool f = true;

int mx(string s) {
    int res, psum, cur;

    psum = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '-') psum--;
        else if (s[i] == '+' || s[i] == '_') psum++;
    }
    if (psum < 0) FALSE

    string t = s;
    for (int i = (int)s.size()-1; i >= 0; i--)
        if (s[i] == '_') {
            t[i] = '+';
            if (psum >= 2) { t[i] = '-'; psum -= 2; }
            else if (psum == 1) { t[i] = '0'; psum--; }
        }

    cur = 0, res = 0;
    for (int i = 0; i < (int)t.size(); i++) {
        if (t[i] == '+') cur++;
        else if (t[i] == '-') cur--;
        res += cur;
        if (cur < 0) FALSE
    }
    if (cur != 0) FALSE

    return res;
}

int ca[maxn];
int mn(string s) {
    s = " " + s;
    int n = (int)s.size() - 1;

    ca[0] = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == '_' || s[i] == '-') ca[i] = ca[i-1] - 1;
        else if (s[i] == '+') ca[i] = ca[i-1] + 1;
        else ca[i] = ca[i-1];

    string t = s;
    int cnt = 0;
    vector<int> q;

    for (int i = 1; i <= n; i++) {
        if (s[i] == '_') { t[i] = '-'; q.push_back(i); }

        while (ca[i] + cnt < 0 && !q.empty()) {
            int x = q.back(); q.pop_back();
            int y = 1; if (t[x] == '-') y++;

            if (ca[i] + cnt + y > 0) { q.push_back(x); t[x] = '0'; cnt++; }
            else { t[x] = '+'; cnt += y; }
        }
    }

    int cur = 0, res = 0;

    for (int i = 0; i < (int)t.size(); i++) {
        if (t[i] == '+') cur++;
        else if (t[i] == '-') cur--;
        res += cur;
        if (cur < 0) FALSE
    }
    if (cur != 0) FALSE


    return res;
}

int32_t main()
{
    freopen("pmoney.inp", "r", stdin);
    freopen("pmoney.out", "w", stdout);

    string s;
    cin >> s;

    int a = mn(s); 
    int b = mx(s);
    if (!f) { cout << "NIE"; return 0; }
    cout << a << " " << b;

    return 0;
}