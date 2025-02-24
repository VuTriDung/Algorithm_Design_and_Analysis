#include <iostream>
using namespace std;

int minimum_days_to_buy_rice(int A, int B, int C) {
    int total_rice_needed = B * C;  
    int days_needed = 0;        
    int current_day = 2;          

    while (total_rice_needed > 0) {
        if (current_day <= 7 && current_day != 1) {  
            int rice_to_buy = (A < total_rice_needed) ? A : total_rice_needed;
            total_rice_needed -= rice_to_buy;
            days_needed++;
        }

        current_day++;
        if (current_day > 7) current_day = 2;  
    }

    return days_needed;
}

int main() {
    int A, B, C;
    cout << "Nhap so luong gao toi da co the mua trong 1 ngay (A): ";
    cin >> A;
    cout << "Nhap so ngay can dung gao (B): ";
    cin >> B;
    cout << "Nhap so luong gao can cho moi ngay (C): ";
    cin >> C;

    int result = minimum_days_to_buy_rice(A, B, C);
    cout << "So ngay it nhat can di mua de dap ung nhu cau: " << result << " ngay\n";
    return 0;
}
