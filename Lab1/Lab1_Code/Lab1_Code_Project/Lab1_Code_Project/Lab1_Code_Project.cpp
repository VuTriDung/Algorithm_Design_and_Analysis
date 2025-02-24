#include <iostream>
using namespace std;

// Bai 1: Chuyen doi so tu he thap phan sang he nhi phan bang de quy
void DecimalToBinary(int n1) {
    if (n1 == 0) {
        return;
    }
    DecimalToBinary(n1 / 2);
    cout << n1 % 2;
}

// Bai 2: De quy in nguoc mot chuoi ky tu
void ReverseString(string str2, int index) {
    if (index < 0) return;
    cout << str2[index];
    ReverseString(str2, index - 1);
}

// Bai 3: Tinh tong cac chu so cua mot so nguyen duong N
int SumOfDigits(int n3) {
    if (n3 == 0) return 0;
    return (n3 % 10) + SumOfDigits(n3 / 10);
}

// Bai 4: Kiem tra mang co doi xung hay khong
bool IsPalindrome(int arr4[], int start, int end) {
    if (start >= end) return true;
    if (arr4[start] != arr4[end]) return false;
    return IsPalindrome(arr4, start + 1, end - 1);
}

// Bai 5: Tinh UCLN cua hai so nguyen duong
int UCLN_Recursion(int p5, int q5) {
    if (q5 == 0) return p5;
    return UCLN_Recursion(q5, p5 % q5);
}

// Bai 5: Tinh UCLN cua hai so nguyen duong (lap)
int UCLN_Iteration(int p5, int q5) {
    while (q5 != 0) {
        int r = p5 % q5;
        p5 = q5;
        q5 = r;
    }
    return p5;
}

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

// Bai 7: In ra tat ca cac hoan vi cua N phan tu
void Permute(string str7, int l, int r) {
    if (l == r) cout << str7 << endl;
    else {
        for (int i = l; i <= r; i++) {
            swap(str7[l], str7[i]);
            Permute(str7, l + 1, r);
            swap(str7[l], str7[i]);
        }
    }
}

// Bai 8: Chia tap hop thanh hai tap con sao cho tong cac phan tu bang nhau
bool CanPartition(int arr8[], int n8, int sum1, int sum2) {
    if (n8 == 0) return sum1 == sum2;
    return CanPartition(arr8, n8 - 1, sum1 + arr8[n8 - 1], sum2) ||
        CanPartition(arr8, n8 - 1, sum1, sum2 + arr8[n8 - 1]);
}

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

void runMenu() {
    int choice;
    do {
        cout << "Chon bai (1-9) hoac 0 de thoat: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int n1;
            cout << "Nhap so nguyen duong de chuyen sang he nhi phan (8 bit): ";
            cin >> n1;
            if (n1 == 0) {
                cout << "0";
            }
            else {
                cout << "So nhi phan cua " << n1 << " la: ";
                DecimalToBinary(n1);
            }
            cout << endl;
            break;
        }
        case 2: {
            string str2;
            cout << "Nhap chuoi: ";
            cin >> str2;
            ReverseString(str2, str2.length() - 1);
            cout << endl;
            break;
        }
        case 3: {
            int n3;
            cout << "Nhap so nguyen duong: ";
            cin >> n3;
            cout << "Tong cac chu so: " << SumOfDigits(n3) << endl;
            break;
        }
        case 4: {
            int arr4[100], size4;
            cout << "Nhap kich thuoc mang: ";
            cin >> size4;
            cout << "Nhap cac phan tu: ";
            for (int i = 0; i < size4; i++) cin >> arr4[i];
            if (IsPalindrome(arr4, 0, size4 - 1)) cout << "Mang doi xung." << endl;
            else cout << "Mang khong doi xung." << endl;
            break;
        }
        case 5: {
            int p5, q5;
            cout << "Nhap hai so nguyen p va q: ";
            cin >> p5 >> q5;
            cout << "UCLN (de quy): " << UCLN_Recursion(p5, q5) << endl;
            cout << "UCLN (nap): " << UCLN_Iteration(p5, q5) << endl;
            break;
        }
        case 6: {
            int n6, k6;
            cout << "Nhap so phan tu n va k: ";
            cin >> n6 >> k6;
            int data[100]; // Mang tam cho to hop
            int arr6[100]; // Mang cho to hop
            for (int i = 0; i < n6; i++) cin >> arr6[i];
            CombinationUtil(arr6, n6, data, 0, 0, k6);
            break;
        }
        case 7: {
            string str7;
            cout << "Nhap chuoi de in ra hoan vi: ";
            cin >> str7;
            Permute(str7, 0, str7.size() - 1);
            break;
        }
        case 8: {
            int n8;
            cout << "Nhap kich thuoc tap hop: ";
            cin >> n8;
            int arr8[100];
            for (int i = 0; i < n8; i++) cin >> arr8[i];
            if (CanPartition(arr8, n8, 0, 0)) cout << "Co the chia tap hop thanh hai tap con." << endl;
            else cout << "Khong the chia tap hop." << endl;
            break;
        }
        case 9: {
            int n9, B9;
            cout << "Nhap so phan tu: ";
            cin >> n9;
            int arr9[100];
            cout << "Nhap cac phan tu: ";
            for (int i = 0; i < n9; i++) cin >> arr9[i];
            cout << "Nhap gia tri B: ";
            cin >> B9;
            int current_combination[100];
            FindCombinations(arr9, n9, B9, current_combination, 0);
            break;
        }
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon tu 1 den 9 hoac 0." << endl;
            break;
        }
    } while (choice != 0);
}

int main() {
    runMenu(); // Chạy hàm menu
    return 0;
}
