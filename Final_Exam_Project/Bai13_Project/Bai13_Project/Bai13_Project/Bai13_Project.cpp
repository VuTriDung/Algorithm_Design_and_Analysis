#include <iostream>
using namespace std;

// Bien toan cuc de luu ket qua tot nhat
int maxOliveTrees = 0;

// Ham quay lui
void backtrack(int index, int currentCypress, int oliveTrees, int Q, int A[], int B[], int N, int M) {
    // Neu da vuot qua gioi han cay bach, quay lui
    if (currentCypress > Q) return;
    // Cap nhat ket qua tot nhat
    maxOliveTrees = max(maxOliveTrees, oliveTrees);
    // Duyet qua cac dai dat (index < N)
    for (int i = index; i < N + M; ++i) {
        if (i < N) {  // Dai dat
            backtrack(i + 1, currentCypress + A[i], oliveTrees + (A[i] - 1), Q, A, B, N, M);
        }
        else {  // Manh dat
            int j = i - N;
            backtrack(i + 1, currentCypress + B[j], oliveTrees + (B[j] - 1), Q, A, B, N, M);
        }
    }
}

int main() {
    int N, M, Q;
    cout << "Nhap so luong dai dat (N), manh dat (M), va gioi han Q: ";
    cin >> N >> M >> Q;
    int A[100], B[100]; // Gia dinh toi da la 100 dai dat va manh dat
    cout << "Nhap so cay bach tren moi dai dat: ";
    for (int i = 0; i < N; ++i) cin >> A[i];
    cout << "Nhap so cay bach tren moi manh dat: ";
    for (int j = 0; j < M; ++j) cin >> B[j];
    // Goi ham quay lui
    backtrack(0, 0, 0, Q, A, B, N, M);
    // In ra ket qua
    cout << "So luong cay o liu toi da: " << maxOliveTrees << endl;
    return 0;
}
