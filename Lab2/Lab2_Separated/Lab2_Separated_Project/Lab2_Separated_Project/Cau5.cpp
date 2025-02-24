#include <iostream>
using namespace std;

// ===================== Bai 5: Tinh tong S(n) = a^n =====================
int power(int a, int n) {
    if (n == 0)
        return 1;
    int halfPower = power(a, n / 2);
    return (n % 2 == 0) ? halfPower * halfPower : halfPower * halfPower * a;
}

int main() {
    int a, n;
    cout << "Nhap a va n: ";
    cin >> a >> n;
    int result = power(a, n);
    cout << "Ket qua S(n) = " << a << "^" << n << " = " << result << endl;

    return 0;
}
