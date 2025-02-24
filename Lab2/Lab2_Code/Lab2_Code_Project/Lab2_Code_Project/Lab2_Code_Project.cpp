#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ===================== Bai 1: Thuat toan Merge Sort =====================
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    // Sao chep du lieu vao mang tam L[] va R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Tron hai mang tam lai vao mang arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chep cac phan tu con lai cua L[], neu co
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chep cac phan tu con lai cua R[], neu co
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


// ===================== Bai 2: Thuat toan Quick Sort =====================
int partition2(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;
    int pivot = arr[mid];
    swap(arr[mid], arr[right]); // Đưa pivot về cuối để dễ xử lý

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]); // Đưa pivot về đúng vị trí
    return i + 1;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partition2(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

// ===================== Bai 3: Tim gia tri nho nhat trong mang =====================
int findMin(int arr[], int left, int right) {
    if (left == right)
        return arr[left];

    int mid = left + (right - left) / 2;
    int minLeft = findMin(arr, left, mid);
    int minRight = findMin(arr, mid + 1, right);

    return min(minLeft, minRight);
}

// ===================== Bai 4: Tim so duong dau tien va so nguyen to cuoi cung =====================
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int findFirstPositive(int arr[], int left, int right) {
    if (left == right)
        return (arr[left] > 0) ? left : -1;

    int mid = left + (right - left) / 2;
    int leftResult = findFirstPositive(arr, left, mid);
    int rightResult = findFirstPositive(arr, mid + 1, right);

    return (leftResult != -1) ? leftResult : rightResult;
}

int findLastPrime(int arr[], int left, int right) {
    if (left == right)
        return isPrime(arr[left]) ? left : -1;

    int mid = left + (right - left) / 2;
    int rightResult = findLastPrime(arr, mid + 1, right);
    int leftResult = findLastPrime(arr, left, mid);

    return (rightResult != -1) ? rightResult : leftResult;
}

// ===================== Bai 5: Tinh tong S(n) = a^n =====================
int power(int a, int n) {
    if (n == 0)
        return 1;
    int halfPower = power(a, n / 2);
    return (n % 2 == 0) ? halfPower * halfPower : halfPower * halfPower * a;
}

// ===================== Bai 6: Dem so bang k va dem so nam giua khoang (x, y) =====================
int countEqual(int arr[], int left, int right, int k) {
    if (left == right)
        return (arr[left] == k) ? 1 : 0;

    int mid = left + (right - left) / 2;
    return countEqual(arr, left, mid, k) + countEqual(arr, mid + 1, right, k);
}

int countInRange(int arr[], int left, int right, int x, int y) {
    if (left == right)
        return (arr[left] > x && arr[left] < y) ? 1 : 0;

    int mid = left + (right - left) / 2;
    return countInRange(arr, left, mid, x, y) + countInRange(arr, mid + 1, right, x, y);
}

// ===================== Bai 7: Tim phan tu lon thu k =====================
int partition7(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;
    int pivot = arr[mid];
    swap(arr[mid], arr[right]);

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int quickSelect(int arr[], int left, int right, int k) {
    if (left <= right) {
        int pi = partition7(arr, left, right);


        if (pi == k - 1)
            return arr[pi];
        else if (pi < k - 1)
            return quickSelect(arr, pi + 1, right, k);
        else
            return quickSelect(arr, left, pi - 1, k);
    }
    return -1;
}

int main() {
    int choice;

    cout << "Chon bai (1-7): ";
    cin >> choice;

    switch (choice) {
    case 1: { // Bai 1: Merge Sort
        int arr1[] = { 11, 10, 19, 6, 20, 25, 00, 8, 7, 21, 1, 2 }; 
        int n1 = sizeof(arr1) / sizeof(arr1[0]);
        cout << "Mang ban dau: ";
        for (int i = 0; i < n1; i++)
            cout << arr1[i] << " ";
        cout << endl;

        mergeSort(arr1, 0, n1 - 1);

        cout << "Mang sau khi sap xep (Merge Sort): ";
        for (int i = 0; i < n1; i++)
            cout << arr1[i] << " ";
        cout << endl;
        break;
    }
    case 2: { // Bai 2: Quick Sort
        int arr2[] = { 15, 10, 9, 5, 20, 00, 8, 6, 21, 1 }; 
        int n2 = sizeof(arr2) / sizeof(arr2[0]);
        cout << "Mang ban dau: ";
        for (int i = 0; i < n2; i++)
            cout << arr2[i] << " ";
        cout << endl;

        quickSort(arr2, 0, n2 - 1);

        cout << "Mang sau khi sap xep (Quick Sort): ";
        for (int i = 0; i < n2; i++)
            cout << arr2[i] << " ";
        cout << endl;
        break;
    }
    case 3: { // Bai 3: Tim gia tri nho nhat
        int arr3[] = { 15, 22, 5, 10, 7, 3, 12, 6 };
        int n3 = sizeof(arr3) / sizeof(arr3[0]);
        int minValue = findMin(arr3, 0, n3 - 1);
        cout << "Mang ban dau: ";
        for (int i = 0; i < n3; i++)
            cout << arr3[i] << " ";
        cout << endl;
        cout << "Gia tri nho nhat trong mang la: " << minValue << endl;
        break;
    }
    case 4: { // Bai 4: Tim so duong dau tien va so nguyen to cuoi cung
        srand(time(0));
        const int N = 20;
        int arr4[N];

        for (int i = 0; i < N; i++) {
            arr4[i] = (rand() % 41) - 20;
            cout << arr4[i] << " ";
        }
        cout << endl;

        int firstPositiveIndex = findFirstPositive(arr4, 0, N - 1);
        int lastPrimeIndex = findLastPrime(arr4, 0, N - 1);

        if (firstPositiveIndex != -1) {
            cout << "So duong dau tien: " << arr4[firstPositiveIndex]
                << " tai vi tri " << firstPositiveIndex << endl;
        }
        else {
            cout << "Khong co so duong nao trong mang." << endl;
        }

        if (lastPrimeIndex != -1) {
            cout << "So nguyen to cuoi cung: " << arr4[lastPrimeIndex]
                << " tai vi tri " << lastPrimeIndex << endl;
        }
        else {
            cout << "Khong co so nguyen to nao trong mang." << endl;
        }
        break;
    }
    case 5: { // Bai 5: Tinh S(n) = a^n
        int a, n;
        cout << "Nhap a va n: ";
        cin >> a >> n;
        int result = power(a, n);
        cout << "Ket qua S(n) = " << a << "^" << n << " = " << result << endl;
        break;
    }
    case 6: { // Bai 6: Dem so bang k va dem so nam giua khoang (x, y)
        int arr6[] = { 12, 7, 5, 3, 7, 9, 13, 7, 15 };
        int n6 = sizeof(arr6) / sizeof(arr6[0]);
        int k, x, y;
        cout << "Mang ban dau: ";
        for (int i = 0; i < n6; i++)
            cout << arr6[i] << " ";
        cout << endl;

        cout << "Nhap so k de dem: ";
        cin >> k;
        int countK = countEqual(arr6, 0, n6 - 1, k);
        cout << "So lan xuat hien cua " << k << " la: " << countK << endl;

        cout << "Nhap x va y de dem so nam giua khoang (x, y): ";
        cin >> x >> y;
        int countRange = countInRange(arr6, 0, n6 - 1, x, y);
        cout << "So phan tu trong khoang (" << x << ", " << y << ") la: " << countRange << endl;
        break;
    }
    case 7: { // Bai 7: Tim phan tu lon thu k
        int arr7[] = { 15, 3, 2, 1, 9, 5, 7, 8, 6 };
        int n7 = sizeof(arr7) / sizeof(arr7[0]);
        int k;
        cout << "Mang ban dau: ";
        for (int i = 0; i < n7; i++)
            cout << arr7[i] << " ";
        cout << endl;

        cout << "Nhap k (de tim phan tu lon thu k): ";
        cin >> k;

        int result = quickSelect(arr7, 0, n7 - 1, k);
        cout << "Phan tu lon thu " << k << " la: " << result << endl;
        break;
    }
    default:
        cout << "Lua chon khong hop le!" << endl;
    }

    return 0;
}
