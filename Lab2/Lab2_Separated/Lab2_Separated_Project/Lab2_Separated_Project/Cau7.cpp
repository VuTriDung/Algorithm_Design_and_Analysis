#include <iostream>
using namespace std;

// ===================== Bai 7: Tim phan tu lon thu k =====================
int partition7(int arr[], int left, int right) {
    int mid = left + (right - left) / 2; 
    int pivot = arr[mid];
    swap(arr[mid], arr[right]); 

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] >= pivot) { 
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int quickSelect(int arr[], int left, int right, int k) {
    if (left <= right) {
        int pi = partition7(arr, left, right);

        
        if (pi == k - 1)
            return arr[pi];
        else if (pi < k - 1)
            return quickSelect(arr, pi + 1, right, k);
        else
            return quickSelect(arr, left, pi - 1, k);
    }
    return -1; 
}

int main() {
    int arr7[] = { 15, 3, 2, 1, 9, 5, 7, 8, 6 };
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    int k;
    cout << "Mang ban dau: ";
    for (int i = 0; i < n7; i++)
        cout << arr7[i] << " ";
    cout << endl;

    cout << "Nhap k (de tim phan tu lon thu k): ";
    cin >> k;

    int result = quickSelect(arr7, 0, n7 - 1, k);  
    cout << "Phan tu lon thu " << k << " la: " << result << endl;

    return 0;
}
