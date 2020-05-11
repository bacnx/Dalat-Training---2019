#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;

int n, m, k;
int a[maxn][maxn];

void init() {
    for (int i = 1; i <= m; i++) 
        for (int j = 1; j <= n; j++)
            a[i][j] = (i-1)*n + j;
}

void H(int y1, int x1, int y2, int x2) {
    int xn = x2 - x1 + 1, yn = y2 - y1 + 1;
    cout << xn << " " << yn << endl;
    // for (int y = 1; y <= yn; y++)
    //     for (int x = 1; x <= xn/2; x++)
    //         swap(a[x1+x][y1+y], a[x1+xn-x+1][y1+y]);
}

void V(int y1, int x1, int y2, int x2) {
    int xn = x2 - x1 + 1, yn = y2 - y1 + 1;
    
    // for (int x = 1; x <= xn; x++)
    //     for (int x = 1; x <= xn/2; x++)
    //         swap(a[x1+x][y1+y], a[x1+xn-x+1][y1+y]);
}

void Cout() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    freopen("carpet.inp", "r", stdin);
    freopen("carpet.out", "w", stdout);

    cin >> m >> n >> k;

    init();
    Cout();
    H(2, 2, 3, 4);
    Cout(); 

    return 0;
}



/*
        --- TẠO THEO ĐỐI XỨNG NGANG ---

* Tạo bảng b = (đối xứng a)
        * cắt vùng bên b đổi với a
        * Tạo viền xung Quanh bảng A, B

* Lưu thông tin của 1 ô trong bảng
        * Ô bên phải
        * ô bên dưới    

* In Bảng

* Tráo đổi 2 vùng
        * Tháo và Nối theo chu vi của vùng cần xóa

*/