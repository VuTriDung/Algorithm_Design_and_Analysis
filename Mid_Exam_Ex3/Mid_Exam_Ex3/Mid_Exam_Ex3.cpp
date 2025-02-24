#include <iostream>
#include <cmath>
using namespace std;

int thuaSo[100];
int dem = 0;

void PhanTichSo(int N, int k) {
    if (N == 1) {
        // In kết quả khi N = 1
        for (int i = 0; i < dem; i++) {
            if (i > 0) cout << "*";
            cout << thuaSo[i];
        }
        cout << endl;
        exit(0);
    }

    bool found = false; // Đánh dấu để kiểm tra xem có tìm được thừa số không
    for (int i = k; i <= sqrt(N); i++) {
        if (N % i == 0) {   
            thuaSo[dem++] = i;
            PhanTichSo(N / i, i);
            dem--;
            found = true; // Đánh dấu là tìm được thừa số
        }
    }

    // Nếu không tìm thấy thừa số nào từ 2 đến sqrt(N), thì N là số nguyên tố
    if (!found && N > 1) {
        thuaSo[dem++] = N;
        for (int i = 0; i < dem; i++) {
            if (i > 0) cout << "*";
            cout << thuaSo[i];
        }
        cout << endl;
        exit(0);
    }
}

int main() {
    int N;
    cout << "Nhap so N: ";
    cin >> N;

    cout << "Cac thua so nguyen to cua " << N << " la: ";
    PhanTichSo(N, 2);

    return 0;
}
