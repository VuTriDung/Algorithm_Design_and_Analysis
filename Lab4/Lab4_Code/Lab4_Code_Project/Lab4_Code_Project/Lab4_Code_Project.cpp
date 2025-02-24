#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int value;   
    int weight;   

    double value_per_weight() const {
        return (double)value / weight;
    }
};

bool compare(Item a, Item b) {
    return a.value_per_weight() > b.value_per_weight();
}

double fractionalKnapsack(int A, Item items[], int N) {
    sort(items, items + N, compare);

    double total_value = 0.0;   
    int remaining_weight = A;   

    for (int i = 0; i < N; i++) {
        if (items[i].weight <= remaining_weight) {
            total_value += items[i].value;         
            remaining_weight -= items[i].weight;  
        }
        else {
            total_value += items[i].value_per_weight() * remaining_weight;
            break; 
        }
    }

    return total_value;
}

int main() {
    int A = 50;  
    Item items[] = { {60, 10}, {100, 20}, {120, 30} }; 
    int N = sizeof(items) / sizeof(items[0]); 

    double max_value = fractionalKnapsack(A, items, N);
    cout << "Gia tri toi da co the dat duoc: " << max_value << endl;

    return 0;
}
