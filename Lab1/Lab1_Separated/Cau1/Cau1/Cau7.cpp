#include <iostream>
#include <algorithm>
using namespace std;

// Bai 7: In ra tat ca cac hoan vi cua N phan tu
void Permute(string str7, int l, int r) {
    if (l == r) cout << str7 << endl;
    else {
        for (int i = l; i <= r; i++) {
            swap(str7[l], str7[i]);
            Permute(str7, l + 1, r);
            swap(str7[l], str7[i]);
        }
    }
}

int main() {
    string str7;
    cout << "Bai 7: Nhap chuoi de in ra hoan vi: ";
    cin >> str7;
    Permute(str7, 0, str7.size() - 1);
    return 0;
}
