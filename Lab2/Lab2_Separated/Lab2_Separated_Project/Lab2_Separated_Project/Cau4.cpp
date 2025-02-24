#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ===================== Bai 4: Tim so duong dau tien va so nguyen to cuoi cung =====================
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int findFirstPositive(int arr[], int left, int right) {
    if (left == right)
        return (arr[left] > 0) ? left : -1;

    int mid = left + (right - left) / 2;
    int leftResult = findFirstPositive(arr, left, mid);
    int rightResult = findFirstPositive(arr, mid + 1, right);

    return (leftResult != -1) ? leftResult : rightResult;
}

int findLastPrime(int arr[], int left, int right) {
    if (left == right)
        return isPrime(arr[left]) ? left : -1;

    int mid = left + (right - left) / 2;
    int rightResult = findLastPrime(arr, mid + 1, right);
    int leftResult = findLastPrime(arr, left, mid);

    return (rightResult != -1) ? rightResult : leftResult;
}

int main() {
    srand(time(0));
    const int N = 20;
    int arr4[N];

    for (int i = 0; i < N; i++) {
        arr4[i] = (rand() % 41) - 20; // Sinh so nguyen tu -20 den 20
        cout << arr4[i] << " ";
    }
    cout << endl;

    int firstPositiveIndex = findFirstPositive(arr4, 0, N - 1);
    int lastPrimeIndex = findLastPrime(arr4, 0, N - 1);

    if (firstPositiveIndex != -1) {
        cout << "So duong dau tien: " << arr4[firstPositiveIndex]
            << " tai vi tri " << firstPositiveIndex << endl;
    }
    else {
        cout << "Khong co so duong nao trong mang." << endl;
    }

    if (lastPrimeIndex != -1) {
        cout << "So nguyen to cuoi cung: " << arr4[lastPrimeIndex]
            << " tai vi tri " << lastPrimeIndex << endl;
    }
    else {
        cout << "Khong co so nguyen to nao trong mang." << endl;
    }

    return 0;
}
