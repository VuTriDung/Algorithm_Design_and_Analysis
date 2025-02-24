#include <iostream>
using namespace std;

// ===================== Bai 6: Dem so bang k va dem so nam giua khoang (x, y) =====================
int countEqual(int arr[], int left, int right, int k) {
    if (left == right)
        return (arr[left] == k) ? 1 : 0;

    int mid = left + (right - left) / 2;
    return countEqual(arr, left, mid, k) + countEqual(arr, mid + 1, right, k);
}

int countInRange(int arr[], int left, int right, int x, int y) {
    if (left > right)
        return 0;

    if (left == right) {
        return (arr[left] > x && arr[left] < y) ? 1 : 0;
    }

    int mid = left + (right - left) / 2;
    return countInRange(arr, left, mid, x, y) + countInRange(arr, mid + 1, right, x, y);
}

int main() {
    int arr6[] = { 12, 7, 5, 3, 7, 9, 13, 7, 15 };
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    int k, x, y;

    cout << "Nhap so k de dem: ";
    cin >> k;
    int countK = countEqual(arr6, 0, n6 - 1, k);
    cout << "So lan xuat hien cua " << k << " la: " << countK << endl;

    cout << "Nhap x va y de dem so nam giua khoang (x, y): ";
    cin >> x >> y;
    int countRange = countInRange(arr6, 0, n6 - 1, x, y);
    cout << "So phan tu trong khoang (" << x << ", " << y << ") la: " << countRange << endl;

    return 0;
}
