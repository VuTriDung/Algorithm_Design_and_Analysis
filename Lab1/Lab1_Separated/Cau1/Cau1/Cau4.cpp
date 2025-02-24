#include <iostream>
using namespace std;

// Bai 4: Kiem tra mang co doi xung hay khong
bool IsPalindrome(int arr4[], int start, int end) {
    if (start >= end) return true;
    if (arr4[start] != arr4[end]) return false;
    return IsPalindrome(arr4, start + 1, end - 1);
}

int main() {
    int arr4[100], size4;
    cout << "Bai 4: Nhap kich thuoc mang: ";
    cin >> size4;
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < size4; i++) cin >> arr4[i];
    if (IsPalindrome(arr4, 0, size4 - 1)) cout << "Mang doi xung." << endl;
    else cout << "Mang khong doi xung." << endl;
    return 0;
}
