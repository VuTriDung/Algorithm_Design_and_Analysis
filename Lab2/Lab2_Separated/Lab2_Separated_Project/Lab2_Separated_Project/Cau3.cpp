#include <iostream>
using namespace std;

// ===================== Bai 3: Tim gia tri nho nhat trong mang =====================
int findMin(int arr[], int left, int right) {
    if (left == right)
        return arr[left];

    int mid = left + (right - left) / 2;
    int minLeft = findMin(arr, left, mid);
    int minRight = findMin(arr, mid + 1, right);

    return min(minLeft, minRight);
}

int main() {
    int arr3[] = { 15, 22, 5, 10, 7, 3, 12, 6 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int minValue = findMin(arr3, 0, n3 - 1);
    cout << "Gia tri nho nhat trong mang la: " << minValue << endl;

    return 0;
}
