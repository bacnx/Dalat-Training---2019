#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 100005;

int n, m, k;
vector<int> dsF[maxn], dsT[maxn];
vector<vector<int> > ltF, ltT;
int T[maxn], F[maxn];
bool cx[maxn];
vector<int> tplt;

void loang_F(int u) {
    cx[u] = false;
    tplt.push_back(u);
    for (int i = 0; i < (int)dsF[u].size(); i++) {
        int v = dsF[u][i];
        if (cx[v]) {
            loang_F(v);
        }
    }
}

void init_F() {
    for (int i = 1; i <= n; i++) cx[i] = true;
    // loang_F(1);
    for (int i = 1; i <= n; i++) {
        if (cx[i]) {
            tplt.clear();
            loang_F(i);
            ltF.push_back(tplt);
            for (int i = 0; i < (int)tplt.size(); i++) F[tplt[i]] = (int)ltF.size()-1;
        }
    }
}

void loang_T(int u) {
    cx[u] = false;
    tplt.push_back(u);
    for (int i = 0; i < (int)dsT[u].size(); i++) {
        int v = dsT[u][i];
        if (cx[v]) {
            loang_T(v);
        }
    }
}

void init_T() {
    for (int i = 1; i <= n; i++) cx[i] = true;
    // loang_F(1);
    for (int i = 1; i <= n; i++) {
        if (cx[i]) {
            tplt.clear();
            loang_T(i);
            ltT.push_back(tplt);
            for (int i = 0; i < (int)tplt.size(); i++) T[tplt[i]] = (int)ltT.size()-1;
        }
    }
}

void link_F(int u, int v) {
    if (F[u] == F[v]) return ;

    int csltu = F[u], csltv = F[v];
    for (int i = 0; i < (int)ltF[csltv].size(); i++) {
        ltF[csltu].push_back(ltF[csltv][i]);
        F[ltF[csltv][i]] = csltu;
    }
}

void link_T(int u, int v) {
    if (T[u] == T[v]) return ;

    int csltu = T[u], csltv = T[v];
    for (int i = 0; i < (int)ltT[csltv].size(); i++) {
        ltT[csltu].push_back(ltT[csltv][i]);
        T[ltT[csltv][i]] = csltu;
    }
}

int truy_van(int u) {
    for (int i = 1; i <= n; i++) cx[i] = true;
    int res  = 0;

    for (int i = 0; i < (int)ltF[F[u]].size(); i++){
        cx[ltF[F[u]][i]] = false;
        // cout << ltF[F[u]][i] << " ";
    }
    // cout << endl;

    for (int i = 0; i < (int)ltT[T[u]].size(); i++){
        if (!cx[ltT[T[u]][i]]) res++;
        // cout << ltT[T[u]][i] << " ";
    }

    return res - 1;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("sum_camp.inp", "r", stdin);
    freopen("sum_camp.out", "w", stdout);

    cin >> n >> m >> k;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        dsF[u].push_back(v);
        dsF[v].push_back(u);
    }
    for (int i = 1; i <= k; i++) {
        cin >> u >> v;
        dsT[u].push_back(v);
        dsT[v].push_back(u);
    }
    
    init_F();
    init_T();

    int q, a, b; char t;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> t;
        if (t == '?') {
            cin >> a; 
            cout << truy_van(a) << endl; 
        }
        else if (t == 'F') {
            cin >> a >> b;
            link_F(a, b);
        }
        else {
            cin >> a >> b;
            link_T(a, b);
        }
    }

    // cout << truy_van(1) << endl;
    // link_F(4, 1);
    // cout << truy_van(1) << endl;
    // link_T(4, 3);
    // cout << truy_van(1) << endl;

    // for (int i = 1; i <= n; i++) cout << i << ": " << F[i] << endl;
    // link_F(1, 4);
    // for (int i = 1; i <= n; i++) cout << i << ": " << F[i] << endl;
    // for (int i = 1; i <= n; i++) cout << i << ": " << T[i] << endl;
    // link_T(4, 3);
    // for (int i = 1; i <= n; i++) cout << i << ": " << T[i] << endl;
    // for (int i = 0; i < (int)ltF.size(); i++) {
    //     for (int j = 0; j < (int)ltF[i].size(); j++)
    //         cout << ltT[i][j] << " ";
    //     cout << endl;
    // }
    // cout << ltF[1].size();
    // loang_F(1);
    // for (int i = 0; i < tplt.size(); i++) cout << tplt[i] << " ";

    return 0;
}