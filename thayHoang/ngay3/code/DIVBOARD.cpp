#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;

int m, n;
int a[maxn][maxn];
int p[maxn][maxn];
int mx, mn;

void init_a() {
	for (int i = 0; i <= m; i++) 
		p[i][0] = 0;
	for (int i = 0; i <= n; i++) 
		p[0][i] = 0;
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) 
			p[i][j] = p[i][j-1] + p[i-1][j] - p[i-1][j-1] + a[i][j];
}

int get_h(int x1, int y1, int x2, int y2) {
	return p[x2][y2] - p[x1][y2] - p[x2][y1] + p[x1][y1];
}

void update(int x) {
	mn = min(mn, x);
	mx = max(mx, x);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("divboard.inp", "r", stdin);
	freopen("divboard.out", "w", stdout);

	cin >> m >> n;
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++) 
			cin >> a[i][j];

	init_a();

	int res = INT_MAX, rest;
	int h1, h2;
	int h1t, h2t;

		int i = 2;
		mx = -1, mn = INT_MAX;

		rest = INT_MAX;
		for (int j = 1; j < n; j++) {
			h1t = get_h(0, 0, i, j);
			h2t = get_h(0, j, i, n);

			if (abs(h2t - h1t) < rest) {
				rest = abs(h2t - h1t);
				h1 = h1t; h2 = h2t;
			}
		}

	for (int i = 1; i < m; i++) {
		mx = -1, mn = INT_MAX;

		rest = INT_MAX;
		for (int j = 1; j < n; j++) {
			h1t = get_h(0, 0, i, j);
			h2t = get_h(0, j, i, n);

			if (abs(h2t - h1t) < rest) {
				rest = abs(h2t - h1t);
				h1 = h1t; h2 = h2t;
			}
		}
		update(h1); update(h2);

		rest = INT_MAX;
		for (int j = 1; j < n; j++) {
			h1t = get_h(i, 0, m, j);
			h2t = get_h(i, j, m, n);

			if (abs(h2t - h1t) < rest) {
				rest = abs(h2t - h1t);
				h1 = h1t; h2 = h2t;
			}
		}
		update(h1); update(h2);

		res = min(res, mx - mn);
	}

	cout << res;

	return 0;
}