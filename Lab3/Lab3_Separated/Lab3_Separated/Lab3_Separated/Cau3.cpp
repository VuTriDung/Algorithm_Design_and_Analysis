#include <iostream>
#include <algorithm>
using namespace std;

int maxSubArraySum(int* A, int N) {
    int maxEndingHere = A[0];  
    int maxSoFar = A[0];

     for (int i = 1; i < N; i++) {
        maxEndingHere = max(A[i], maxEndingHere + A[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int main() {
    int N;
    cout << "Nhap so phan tu cua mang: ";
    cin >> N;
    int* A = new int[N];

    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int result = maxSubArraySum(A, N);
    cout << "Tong lon nhat cua day con lien tiep la: " << result << endl;

    delete[] A;  
    return 0;
}
