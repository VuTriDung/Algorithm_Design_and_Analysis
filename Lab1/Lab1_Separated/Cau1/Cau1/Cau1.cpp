#include <iostream>
using namespace std;
// Bai 1: Chuyen doi so tu he thap phan sang he nhi phan bang de quy
void DecimalToBinary(int n1) {
    int binary[8] = { 0 };
    int i = 7;
    while (n1 > 0 && i >= 0) {
        binary[i] = n1 % 2;
        n1 = n1 / 2;
        i--;
    }
    for (int j = 0; j < 8; j++) {
        cout << binary[j];
    }
    cout << endl;
}

int main() {
    int n1;
    cout << "Nhap so nguyen duong de chuyen sang he nhi phan (8 bit): ";
    cin >> n1;
    if (n1 >= 0 && n1 <= 255) {
        DecimalToBinary(n1);
    }
    else {
        cout << "So ngoai pham vi 8 bit!" << endl;
    }
    return 0;
}
