#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int weight;   
    int value;   
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double knapsack(Item arr[], int n, int W) {
    sort(arr, arr + n, cmp);

    int curWeight = 0;  
    double finalValue = 0.0;  

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int n, W;
    cout << "Nhap so luong mon do: ";
    cin >> n;
    cout << "Nhap trong luong gioi han cua ba lo: ";
    cin >> W;

    Item* arr = new Item[n];
    cout << "Nhap gia tri va trong luong cua tung mon do:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Mon do " << i + 1 << ": ";
        cin >> arr[i].value >> arr[i].weight;
    }

    double maxValue = knapsack(arr, n, W);
    cout << "Gia tri toi da co the lay duoc la: " << maxValue << endl;

    delete[] arr;

    return 0;
}
