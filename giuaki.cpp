#include <iostream>
#include <cmath>
using namespace std;

// 1. Dùng hàm đệ quy
int tinhSoHangDeQuy(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 2;
    }
    return 5 * tinhSoHangDeQuy(n - 1) - 6 * tinhSoHangDeQuy(n - 2);
}

// 2. Dùng vòng lặp
int tinhSoHangVongLap(int n) {
    int a0 = 0;
    int a1 = 2;
    int an;

    for (int i = 2; i <= n; ++i) {
        an = 5 * a1 - 6 * a0;
        a0 = a1;
        a1 = an;
    }

    return an;
}

// 3. Dùng mảng 1 chiều
int tinhSoHangMang1D(int n) {
    int a[n + 1];
    a[0] = 0;
    a[1] = 2;

    for (int i = 2; i <= n; ++i) {
        a[i] = 5 * a[i - 1] - 6 * a[i - 2];
    }

    return a[n];
}

// 4. Dùng mảng 2 chiều
int tinhSoHangMang2D(int n) {
    int a[n + 1][2];
    a[0][0] = 0;
    a[1][0] = 2;

    for (int i = 2; i <= n; ++i) {
        a[i][0] = 5 * a[i - 1][0] - 6 * a[i - 2][0];
    }

    return a[n][0];
}

// 5. Tìm nghiệm của hệ thức truy hồi rồi cài đặt
int tinhSoHangNghiem(int n) {
    double r1 = (5 + sqrt(61)) / 2;
    double r2 = (5 - sqrt(61)) / 2;

    double c1 = (2 - r2) / (r1 - r2);
    double c2 = (2 - r1) / (r2 - r1);

    return c1 * pow(r1, n) + c2 * pow(r2, n);
}

int main() {
    int n;
    int choice;

    cout << "Nhap so hang thu n: ";
    cin >> n;

    while (true) {
        cout << "Chon cach tinh so hang thu n: \n";
        cout << "1. Dung ham de quy\n";
        cout << "2. Dung vong lap\n";
        cout << "3. Dung mang 1 chieu\n";
        cout << "4. Dung mang 2 chieu\n";
        cout << "5. Tim nghiem cua he thuc truy hoi roi cai dat\n";
        cout << "Lua chon: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            break;
        } else {
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    }

    int result;

    switch (choice) {
        case 1:
            result = tinhSoHangDeQuy(n);
            break;
        case 2:
            result = tinhSoHangVongLap(n);
            break;
        case 3:
            result = tinhSoHangMang1D(n);
            break;
        case 4:
            result = tinhSoHangMang2D(n);
            break;
        case 5:
            result = tinhSoHangNghiem(n);
            break;
        default:
            cout << "Lua chon khong hop le.\n";
            return 0;
}

cout << "So hang thu " << n << " cua day so la: " << result << endl;

return 0;
}
