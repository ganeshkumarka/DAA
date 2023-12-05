#include <iostream>
using namespace std;

int minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];
    fill(dp, dp + amount + 1, 1e9);
    dp[0] = 0;
    bool solutionFound = false;
    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= amount; ++j) {
            if (dp[j - coins[i]] != 1e9) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                solutionFound = true;
            }
        }
    }

    if (solutionFound)
        return dp[amount];
}
    

int main() {

    int size;
    cout << "Enter coin array size:";
    cin >> size;

    int coins[size];
    cout << "Enter coins:";
    for (int i = 0; i < size; i++)
    {
        cin >> coins[i];
    }

    int amount;

    cout << "Enter the amount: ";
    cin >> amount;

    int result = minCoins(coins, size, amount);

    if (result == -1) {
        cout << "It's not possible to make the exact amount with the given denominations." << endl;
    } else {
        cout << "Minimum number of coins needed: " << result << endl;
    }

    return 0;
}
