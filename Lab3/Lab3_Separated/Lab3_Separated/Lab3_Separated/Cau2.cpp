#include <iostream>
#include <algorithm>
using namespace std;

int maxNonAdjacentSum(int* A, int N) {
    if (N == 0) return 0; 
    if (N == 1) return A[0]; 

    int* dp = new int[N]; 
    dp[0] = A[0];  
    dp[1] = max(A[0], A[1]); 

     for (int i = 2; i < N; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + A[i]); 
    }

    int result = dp[N - 1];  
    delete[] dp; 
    return result;  
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

    int result = maxNonAdjacentSum(A, N);
    cout << "Tong lon nhat cua day con khong co hai phan tu lien ke la: " << result << endl;

    delete[] A;  
    return 0;
}
