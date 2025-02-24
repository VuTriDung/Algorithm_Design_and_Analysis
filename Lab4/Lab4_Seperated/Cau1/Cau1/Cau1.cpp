#include <iostream>
#include <algorithm>

using namespace std;

void maximizeArrayProduct(int arr[], int n) {
    sort(arr, arr + n);

    long long maxSum = 0;
    for (int i = 0; i < n; ++i) {
        maxSum += arr[i] * i;
    }

    cout << "Tong lon nhat cua A[i] * i la: " << maxSum << endl;
}

int main() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    maximizeArrayProduct(arr, n);

    return 0;
}
