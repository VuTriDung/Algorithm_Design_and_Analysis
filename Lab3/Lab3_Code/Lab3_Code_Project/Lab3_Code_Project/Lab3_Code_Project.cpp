#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// Bai 1: Tim day con tang dai nhat (LIS)
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

// Bai 2: Tong lon nhat cua day con khong co hai phan tu lien ke
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

// Bai 3: Day con lien tiep co tong lon nhat (Kadane's Algorithm)
int maxSubArraySum(int* A, int N) {
    int maxEndingHere = A[0];
    int maxSoFar = A[0];

    for (int i = 1; i < N; i++) {
        maxEndingHere = max(A[i], maxEndingHere + A[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

// Bai 4: Chuoi con chung dai nhat cua hai chuoi
int longestCommonSubsequence(char str1[], char str2[], int n, int m) {
    int** dp = new int* [n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[m + 1];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int result = dp[n][m];

    for (int i = 0; i <= n; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}

int main() {
    int choice;
    cout << "Chon bai tap de chay (1-4): ";
    cin >> choice;

    if (choice == 1) {
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
    }
    else if (choice == 2) {
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
    }
    else if (choice == 3) {
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
    }
    else if (choice == 4) {
        char str1[100], str2[100];
        cout << "Nhap chuoi thu nhat: ";
        cin >> str1;
        cout << "Nhap chuoi thu hai: ";
        cin >> str2;

        int n = strlen(str1);
        int m = strlen(str2);

        int result = longestCommonSubsequence(str1, str2, n, m);
        cout << "Do dai chuoi con chung dai nhat la: " << result << endl;
    }
    else {
        cout << "Lua chon khong hop le!" << endl;
    }

    return 0;
}
