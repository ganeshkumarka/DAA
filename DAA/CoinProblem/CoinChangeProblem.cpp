#include <iostream>
using namespace std;

int maxCoinRowValue(int coins[], int n) {
    if (n == 0) return 0;
    if (n == 1) return coins[0];

    int F[n];
    F[0] = coins[0];
    F[1] = max(coins[0], coins[1]);

    
    for (int i = 2; i < n; i++) {
        F[i] = max(F[i - 1], F[i - 2] + coins[i]);
    }

    return F[n - 1];
}

int main() {
    int coins[] = {2, 4, 3, 5, 6};
    int n =5;
    
    int result = maxCoinRowValue(coins, n);
    cout << "Maximum value: " << result << endl;
    

    return 0;
}
