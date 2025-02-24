#include <iostream>
using namespace std;

// Bai 9: Tim cac to hop cac so co tong bang gia tri B
void FindCombinations(int arr9[], int n9, int B9, int current_combination[], int index) {
    if (B9 == 0) {
        for (int j = 0; j < index; j++) cout << current_combination[j] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n9; i++) {
        if (arr9[i] <= B9) {
            current_combination[index] = arr9[i];
            FindCombinations(arr9, n9, B9 - arr9[i], current_combination, index + 1);
        }
    }
}

int main() {
    int n9, B9;
    cout << "Bai 9: Nhap so phan tu: ";
    cin >> n9;
    int arr9[100];
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n9; i++) cin >> arr9[i];
    cout << "Nhap gia tri B: ";
    cin >> B9;
    int current_combination[100];
    FindCombinations(arr9, n9, B9, current_combination, 0);
    return 0;
}
