#include <iostream>
#include <cstring>
using namespace std;

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
    char str1[100], str2[100];
    cout << "Nhap chuoi thu nhat: ";
    cin >> str1;
    cout << "Nhap chuoi thu hai: ";
    cin >> str2;

    int n = strlen(str1);
    int m = strlen(str2);

    int result = longestCommonSubsequence(str1, str2, n, m);
    cout << "Do dai chuoi con chung dai nhat la: " << result << endl;

    return 0;
}
