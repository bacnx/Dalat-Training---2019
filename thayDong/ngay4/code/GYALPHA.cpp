#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo = LLONG_MAX;
const int maxn = 1003;

int n, m;
vector<int> g[maxn];
vector<int> G, Y;
int GY[maxn];
ll f[maxn];
bool cx[maxn];  
int tt[maxn]; 


void link(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}
 
ll BFS(int u0) {
    queue<int> q; 
    for (int i = 1; i <= n; i++) {cx[i] = true; tt[i] = 0;}
    f[u0] = 0; q.push(u0); cx[u0] = false;

    int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop();
        // cout << u << endl;

        if (GY[u] != GY[u0] && tt[u] < 3) {
            q.push(u);
            f[u]++;
            tt[u]++;
        }
        else {
            for (int i = 0; i < (int)g[u].size(); i++) {
                v = g[u][i];
                if (cx[v]) {
                    cx[v] = false;
                    f[v] = f[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++)
        if (GY[i] == GY[u0]) res += f[i];

    return res;
} 

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("gyalpha.inp", "r", stdin);
    freopen("gyalpha.out", "w", stdout);

    cin >> n >> m;

    char t;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        if (t == 'G') GY[i] = 1;
        else GY[i] = -1;
    }

    int u, v;
    for (ll i = 1; i <= m; i++) {
        cin >> u >> v;
        link(u, v);
    }
    // cout << BFS(1);
    ll sG = 0, sY = 0;
    for (int i = 1; i <= n; i++)
        if (GY[i] == 1) sG += BFS(i);
        else sY += BFS(i);

    sG /= 2; sY /= 2;
    cout << sG << " " << sY;

    return 0;
}




// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int oo = INT_MAX;
// const int maxn = 1003;

// int n, m;
// vector<int> aG[maxn*4], aY[maxn*4];
// vector<int> G, Y;
// int nG, nY;
// int endG[maxn], endY[maxn];
// int GY[maxn];

// void link(vector<int> gra[], int u, int v) {
//     gra[u].push_back(v);
//     gra[v].push_back(u);
// }

// void input() {
//     cin >> n >> m;
//     nG = nY = n;

//     char t;
//     for (int i = 1; i <= n; i++) {
//         cin >> t;
//         if (t == 'G') {
//             G.push_back(i); GY[i] = 1;

//             link(aY, i, nY+1);
//             link(aY, nY+1, nY+2);
//             link(aY, nY+2, nY+3);
            
//             nY+= 3;
//             endY[i] = nY;
//         }
//         else {
//             Y.push_back(i); GY[i] = -1;

//             link(aG, i, nG+1);
//             link(aG, nG+1, nG+2);
//             link(aG, nG+2, nG+3);
            
//             nG+= 3;
//             endG[i] = nG;
//         }
//     }

//     int u, v;
//     for (int i = 1; i <= m; i++) {
//         cin >> u >> v;

//         if (GY[u] == 1) {
//             link(aG, u, v);
//             link(aY, endY[u], v);
//         }
//         else if (GY[u] == -1) {
//             link(aG, endG[u], v);
//             link(aY, u, v);
//         }
//     }
// }

// int f[maxn*4];
// bool cx[maxn*4];
// int BFS(vector<int> g[], int nd, vector<int> td, int type, int u0) {
//     queue<int> q;
//     for (int i = 1; i <= nd; i++) { f[i] = oo; cx[i] = true; }
//     f[u0] = 0; q.push(u0); cx[u0] = false;

//     int u, v;
//     while (!q.empty()) {
//         u = q.front(); q.pop();
//         for (int i = 0; i < (int)g[u].size(); i++) {
//             v = g[u][i];
//             if (cx[v]) {
//                 cx[v] = false;
//                 q.push(v);
//                 f[v] = f[u] + 1;
//             }
//         }
//     }

//     int res = 0;
//     for (int i = 0; i < (int)td.size(); i++)
//         res += f[td[i]];

//     return res;
// } 

// int main()
// {
//     ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     freopen("gyalpha.inp", "r", stdin);
//     freopen("gyalpha.out", "w", stdout);

//     input();

//     for (int i = 1; i <= nG; i++) {
//         cout << i << ": ";
//         for (int j = 0; j < aG[i].size(); j++) cout << aG[i][j] << " ";
//         cout << endl;
//     }

//     int sG = 0, sY = 0;
//     for (int i = 0; i < (int)G.size(); i++) 
//         sG += BFS(aG, nG, G, 1, G[i]);
//     for (int i = 0; i < (int)Y.size(); i++) 
//         sY += BFS(aY, nY, Y, -1, Y[i]);

//     sG /= 2; sY /= 2;
//     cout << sG << " " << sY;

//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// const int oo = INT_MAX;
// const int maxn = 1003;

// int n, m;
// vector<int> a[maxn];
// int td[maxn];

// void input() {
//     cin >> n >> m;

//     char t;
//     for (int i = 1; i <= n; i++) {
//         cin >> t;
//         if (t == 'G') td[i] = 1;
//         else td[i] = -1;
//     }

//     int u, v;
//     for (int i = 1; i <= m; i++) {
//         cin >> u >> v;
//         a[u].push_back(v);
//         a[v].push_back(u);
//     }
// }

// bool cx[maxn];
// int f[maxn];
// int dijkstra(int u0) {
//     for (int i = 1; i <= n; i++) {
//         cx[i] = true;
//         f[i] = oo;
//     }
//     f[u0] = 0;

//     int u, mn, cs, cnt = 0;
//     while (cnt <= n) {
//         mn = oo;
//         for (int i = 1; i <= n; i++)
//             if (cx[i] && f[i] < mn) { mn = f[i]; u = i; }
            
//         cx[u] = false;
//         for (int i = 0; i < a[u].size(); i++){
//             int v = a[u][i];
//             int cp = 1;
//             if (td[u0] * td[v] == -1) cp += 3;
//             if (cx[v] && f[v] > f[u] + cp) f[v] = f[u] + cp;
//         }
//         cnt++;
//     }

//     int res = 0;
//     for (int i = 1; i <= n; i++)
//         if (td[i] * td[u0] == 1) res += f[i];

//     return res;
// }

// int main()
// {
//     freopen("gyalpha.inp", "r", stdin);
//     freopen("gyalpha.out", "w", stdout);

//     input();
    
//     int cpG = 0, cpY = 0;
//     for (int i = 1; i <= n; i++)
//         if (td[i] == 1) cpG += dijkstra(i);
//         else cpY += dijkstra(i);
    
//     cout << cpG/2 << " " << cpY/2;

//     return 0;
// }