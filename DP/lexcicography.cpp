#include <bits/stdc++.h>
using namespace std;

void f(int i, int n) {
    if (i > n) return;  // If the number exceeds n, stop recursion
    cout << i << " ";   // Print the current number
    
    for (int j = 0; j <= 9; j++) {
        f(10 * i + j, n);  // Recur with the next digit added
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= 9; i++) {
        f(i, n);  // Start the recursion with each digit from 1 to 9
    }
    
    return 0;
}
