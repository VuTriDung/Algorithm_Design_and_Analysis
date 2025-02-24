#include <iostream>
using namespace std;

// Bai 8: Chia tap hop thanh hai tap con sao cho tong cac phan tu bang nhau
bool CanPartition(int arr8[], int n8, int sum1, int sum2) {
    if (n8 == 0) return sum1 == sum2;
    return CanPartition(arr8, n8 - 1, sum1 + arr8[n8 - 1], sum2) ||
        CanPartition(arr8, n8 - 1, sum1, sum2 + arr8[n8 - 1]);
}

int main() {
    int n8;
    cout << "Bai 8: Nhap kich thuoc tap hop: ";
    cin >> n8;
    int arr8[100];
    for (int i = 0; i < n8; i++) cin >> arr8[i];
    if (CanPartition(arr8, n8, 0, 0)) cout << "Co the chia tap hop thanh hai tap con." << endl;
    else cout << "Khong the chia tap hop." << endl;
    return 0;
}
