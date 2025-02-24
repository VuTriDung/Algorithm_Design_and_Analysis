#include <iostream>
using namespace std;

// Bai 2: De quy in nguoc mot chuoi ky tu
void ReverseString(string str2, int index) {
    if (index < 0) return;
    cout << str2[index];
    ReverseString(str2, index - 1);
}

int main() {
    string str2;
    cout << "Bai 2: Nhap chuoi: ";
    cin >> str2;
    ReverseString(str2, str2.length() - 1);
    cout << endl;
    return 0;
}
