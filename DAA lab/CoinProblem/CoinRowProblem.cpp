#include <iostream>
using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void printCoins(int *coins, int *sum, int n)
{
    cout << "We choose coins ";
    for (int i = n - 1; i > 0; i = i - 2)
    {
        if (sum[i] == sum[i - 1])
        {
            i--;
        }
        cout << coins[i] << ", ";
    }
    return;
}

void CRP(int *coins, int n)
{
    int sum[n];
    sum[0] = 0;
    sum[1] = coins[1];
    for (int i = 2; i < n; i++)
    {
        sum[i] = max(coins[i] + sum[i - 2], sum[i - 1]);
    }
    cout << "Largest value=" << sum[n - 1] << endl;
    printCoins(coins, sum, n);
    return;
}

int main()
{
    int n;
    cout << "Enter number of coins: ";
    cin >> n;
    n = n + 1;
    int coins[n];
    cout << "Enter value of coins" << endl;
    for (int i = 1; i < n; i++)
    {
        cin >> coins[i];
    }
    CRP(coins, n);
    return 0;
}