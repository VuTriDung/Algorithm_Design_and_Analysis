#include <iostream>
using namespace std;

// Bai 5: Tinh UCLN cua hai so nguyen duong (de quy)
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

int main() {
    int p5, q5;
    cout << "Bai 5: Nhap hai so nguyen p va q: ";
    cin >> p5 >> q5;
    cout << "UCLN (de quy): " << UCLN_Recursion(p5, q5) << endl;
    cout << "UCLN (lap): " << UCLN_Iteration(p5, q5) << endl;
    return 0; 
}
