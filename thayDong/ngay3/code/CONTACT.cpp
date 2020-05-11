#include <bits/stdc++.h>
using namespace std;

#define vt vector<int>
const long long MOD = 1e9+7;
const int maxn = 100005;

int n, m;
set<int> v[maxn][20];
int pw[20];
bool cx[maxn];

void init_pw() {
	pw[0] = 1;
	for (int i = 1; i < 20; i++)
		pw[i] = pw[i-1]<<1;
}

vt bit(int l) {
 	string s;
 	while (l != 0) {
 		s = s + (char)(l % 2);
 		l = l>>1;
 	}

 	vt res;
 	for (int i = 0; i < (int)s.size(); i++) 
 		if ((int)s[i] == 1) res.push_back(i);

 	return res;
}

void link(int i, int j, int q) {
		v[i][q].insert(j);
		v[j][q].insert(i);
}

void init_cx() {
	for (int i = 1; i <= n; i++)
		cx[i] = true;
}

void bfs(int u0) {
	queue<int> q;
	q.push(u0); cx[u0] = false;

	int a, b;
	while (!q.empty()) {
		a = q.front(); q.pop();
		set<int>::iterator i;
		for (i = v[a][0].begin(); i != v[a][0].end(); i++) {
			b = *i; // = v[a][0][i];
			if (cx[b]) {
				q.push(b);
				cx[b] = false;
			}
		}
	}
}


int main()
{
	// ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("contact.inp", "r", stdin);
	freopen("contact.out", "w", stdout);

	init_pw();

	cin >> n >> m;

	int p, q, l;
	vt t;
	while (m--) {
		cin >> p >> q >> l;
		vt t = bit(l);
		link(p, q, t[0]);
		for (int i = 1; i < (int)t.size(); i++) {
			p += pw[t[i-1]];
			q += pw[t[i-1]];
			link(p, q, t[i]);
		}
	}

	for (q = 19; q > 0; q--) {
		for (int i = 1; i <= n; i++) {
			set<int>::iterator k;
			for (k = v[i][q].begin(); k != v[i][q].end(); k++) {
				int j = *k;// v[i][q][k];
				link(i, j, q-1);
				link(i + pw[q-1], j + pw[q-1], q-1);
			}
		}
	}

	init_cx();
	int h = 0;
	for (int i = 1; i <= n; i++)
		if (cx[i]) { bfs(i); h++; }

	long long res = 1;
	while (h--) res = (res * 2) % MOD;

	cout << res;


	return 0;
}




// #include <bits/stdc++.h>
// using namespace std;

// const long long MOD = 1e9+7;
// const int maxn = 100005;

// int n, m;
// vector <vector<int> > group;
// int index_group[maxn];
// int h;


// void link_sub3(int u, int v) {
// 	int gu = index_group[u];
// 	int gv = index_group[v];

// 	if (gu == gv) return ;

// 	for (int i = 0; i < (int)group[gv].size(); i++) {
// 		group[gu].push_back(group[gv][i]);
// 		index_group[group[gv][i]] = gu;
// 	}
// 	// group.erase(group.begin() + gv);
// 	h--;
// }

// void sub3() {
// 	cin >> n >> m;

// 	h = n;
// 	for (int i = 1; i <= n; i++) {
// 		vector<int> t;
// 		t.push_back(i);
// 		group.push_back(t);

// 		index_group[i] = i - 1;
// 	}

// 	int p, q, l;
// 	while (m--) {
// 		cin >> p >> q >> l;
// 		for (int i = 0; i < l; i++)
// 			link_sub3(p + i, q + i);
// 	}

// 	long long res = 1;
// 	// int h = (int)group.size();
// 	while (h--) res = (res * 2) % MOD;

// 	cout << res;
// }

// void sub4() {
// 	// ????
// }

// int main()
// {
// 	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     freopen("contact.inp", "r", stdin);
//     freopen("contact.out", "w", stdout);

//     sub3();

//     return 0;
// }