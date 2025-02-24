#include <iostream>
using namespace std;

// ===================== Bai 2: Thuat toan Quick Sort voi pivot o giua =====================
int partition2(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;
    int pivot = arr[mid];
    swap(arr[mid], arr[right]); 

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]); 
    return i + 1;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partition2(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

int main() {
    int arr2[] = { 15, 10, 9, 5, 20, 00, 8, 6, 21, 1 }; 
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Mang ban dau: ";
    for (int i = 0; i < n2; i++)
        cout << arr2[i] << " ";
    cout << endl;

    quickSort(arr2, 0, n2 - 1);

    cout << "Mang sau khi sap xep (Quick Sort voi pivot o giua): ";
    for (int i = 0; i < n2; i++)
        cout << arr2[i] << " ";
    cout << endl;

    return 0;
}
