#include <bits/stdc++.h>
using namespace std;

struct status { int x, y, direction; };

const int maxn = 302;

int n, m;
int a[maxn][maxn];

int psum_x[maxn][maxn], psum_y[maxn][maxn];
bool kill[maxn][maxn][2];
queue<status> q;

void enter() {
	cin >> n >> m;
	char t;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> t; 
			if (t == '.') a[i][j] = 0;
			else a[i][j] = 1;
		}
}

void init_psumxy() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			psum_y[i][j] = psum_y[i][j-1] + a[i][j];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			psum_x[j][i] = psum_x[j-1][i] + a[j][i];
}

void init_kill() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			kill[i][j][1] = kill[i][j][0] = false;
	while (!q.empty()) q.pop();
}

void _kill(status sta) { kill[sta.x][sta.y][sta.direction] = true; }

status edit_status(status u0, int x, int y, int d) {
	status res = u0;
	res.x += x;
	res.y += y;
	res.direction = d;
	return res;
}

bool check_status(status s, int k) {
	if ((s.x < 1 || s.y < 1 || s.x > n || s.y > m)
	 || (s.direction == 0 && s.y + k - 1 > m)
	 || (s.direction == 1 && s.x + k - 1 > n)
	 || (kill[s.x][s.y][s.direction]))
		return false;
	if (s.direction == 0 && psum_y[s.x][s.y+k-1] - psum_y[s.x][s.y-1] == 0) return true;
	if (s.direction == 1 && psum_x[s.x+k-1][s.y] - psum_x[s.x-1][s.y] == 0) return true;
	return false;
}

void loang(status s, int k) {
	int x = s.x, y = s.y, d = s.direction;
	status st;
	int kk = k-1;
	if (d == 1) {
		st = edit_status(s, -1, 0, 1);
		if (check_status(st, k)) { q.push(st); _kill(st); }
		st = edit_status(s, 1, 0, 1);
		if (check_status(st, k)) { q.push(st); _kill(st); }
		st = edit_status(s, 0, -kk, 0);
		if (check_status(st, k)) { q.push(st); _kill(st); }
		st = edit_status(s, 0, 0, 0);
		if (check_status(st, k)) { q.push(st); _kill(st); }
		st = edit_status(s, kk, -kk, 0);
		if (check_status(st, k)) { q.push(st); _kill(st); }
		st = edit_status(s, kk, 0, 0);
		if (check_status(st, k)) { q.push(st); _kill(st); }
	}
	else {
		st = edit_status(s, 0, -1, 0);
		if (check_status(st, k)) { q.push(st); _kill(st); }
		st = edit_status(s, 0, 1, 0);
		if (check_status(st, k)) { q.push(st); _kill(st); }
		st = edit_status(s, -kk, 0, 1);
		if (check_status(st, k)) { q.push(st); _kill(st); }
		st = edit_status(s, 0, 0, 1);
		if (check_status(st, k)) { q.push(st); _kill(st); }
		st = edit_status(s, -kk, kk, 1);
		if (check_status(st, k)) { q.push(st); _kill(st); }
		st = edit_status(s, 0, kk, 1);
		if (check_status(st, k)) { q.push(st); _kill(st); }
	}
}

bool bfs(int k) {
	status u;
	while (!q.empty()) {
		u = q.front(); q.pop();
		if (u.y == m) return true;
		loang(u, k);
	}
	return false;
}

bool check(int k) {
	status s;
	s.x = s.y = s.direction = 1;
	for (s.x <= n; s.x++)
		if (check_status(s, k)) {
			init_kill();
			q.push(s);
			_kill(s);
			if (bfs(k)) return true;
		}
	return false;
}

int sb() {
	int l = 1, r = 300, mid;
	int res;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return res;
}

int main()
{
	freopen("bamboo.inp", "r", stdin);
	freopen("bamboo.out", "w", stdout);

	enter();
	init_psumxy();
	cout << sb();

	return 0;
}