#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

bool canRearrangeString(string S) {
    unordered_map<char, int> freq;   

    for (char ch : S) {
        freq[ch]++;
    }

    priority_queue<pair<int, char>> maxHeap;
    for (auto it : freq) {
        maxHeap.push({ it.second, it.first });
    }

    pair<int, char> prev = { -1, '#' };  
    string result = "";

    while (!maxHeap.empty()) {
        auto current = maxHeap.top();
        maxHeap.pop();
        result += current.second;  
       
        if (prev.first > 0) {
            maxHeap.push(prev);
        }
        current.first--;
        prev = current;
    }

    return result.length() == S.length();
}

int main() {
    string S;
    cout << "Nhap chuoi S: ";
    cin >> S;

    if (canRearrangeString(S)) {
        cout << "Co the sap xep lai chuoi de khong co hai ky tu lien ke giong nhau.\n";
    }
    else {
        cout << "Khong the sap xep lai chuoi de khong co hai ky tu lien ke giong nhau.\n";
    }

    return 0;
}
