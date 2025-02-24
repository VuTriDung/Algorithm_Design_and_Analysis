#include <iostream>
using namespace std;

// Bai 3: Tinh tong cac chu so cua mot so nguyen duong N
int SumOfDigits(int n3) {
    if (n3 == 0) return 0;
    return (n3 % 10) + SumOfDigits(n3 / 10);
}

int main() {
    int n3;
    cout << "Bai 3: Nhap so nguyen duong: ";
    cin >> n3;
    cout << "Tong cac chu so: " << SumOfDigits(n3) << endl;
    return 0;
}
