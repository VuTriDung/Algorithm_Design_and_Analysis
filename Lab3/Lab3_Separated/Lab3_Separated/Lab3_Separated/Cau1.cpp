#include <iostream>
#include <algorithm>
using namespace std;

int longestIncreasingSubsequence(int* A, int N) {
    int* dp = new int[N]; 
    fill(dp, dp + N, 1); 
    int maxLength = 1;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1); 
            }
        }
        maxLength = max(maxLength, dp[i]); 
    }

    delete[] dp; 
    return maxLength;
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

    int result = longestIncreasingSubsequence(A, N);
    cout << "Chieu dai day con tang dai nhat la: " << result << endl;

    delete[] A;
    return 0;
}
