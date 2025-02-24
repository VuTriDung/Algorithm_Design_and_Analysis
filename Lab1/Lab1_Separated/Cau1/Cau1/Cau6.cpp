#include <iostream>
using namespace std;

// Bai 6: Tim cac to hop cua N phan tu chon K phan tu
void CombinationUtil(int arr6[], int n6, int data[], int start, int index, int k6) {
    if (index == k6) {
        for (int j = 0; j < k6; j++) cout << data[j] << " ";
        cout << endl;
        return;
    }
    for (int i = start; i <= n6 - 1 && n6 - i >= k6 - index; i++) {
        data[index] = arr6[i];
        CombinationUtil(arr6, n6, data, i + 1, index + 1, k6);
    }
}

int main() {
    int n6, k6;
    cout << "Bai 6: Nhap so phan tu n va k: ";
    cin >> n6 >> k6;
    int data[100];
    int arr6[100];
    for (int i = 0; i < n6; i++) cin >> arr6[i];
    CombinationUtil(arr6, n6, data, 0, 0, k6);
    return 0;
}
