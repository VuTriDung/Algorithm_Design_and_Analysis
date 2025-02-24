#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findMinSum(int arr[], int n) {
    sort(arr, arr + n);
    
    int num1 = 0, num2 = 0;
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            num1 = num1 * 10 + arr[i];
        } else {
            num2 = num2 * 10 + arr[i];
        }
    }
    
    return num1 + num2;
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

    int result = findMinSum(arr, n);
    cout << "Tong nho nhat cua hai so la: " << result << endl;

    return 0;
}
