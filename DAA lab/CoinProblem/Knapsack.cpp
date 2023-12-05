#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];
    bool isTaken[n][W + 1];  

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
                isTaken[i][w] = false;
            } else if (wt[i - 1] <= w) {
                int takeItem = val[i - 1] + K[i - 1][w - wt[i - 1]];
                int skipItem = K[i - 1][w];
                if (takeItem >= skipItem) {
                    K[i][w] = takeItem;
                    isTaken[i - 1][w] = true;  
                } else {
                    K[i][w] = skipItem;
                    isTaken[i - 1][w] = false;
                }
            } else {
                K[i][w] = K[i - 1][w];
                isTaken[i - 1][w] = false;
            }
        }
    }

    cout << "Weights taken: ";
    int i = n - 1, w = W;
    while (i >= 0 && w > 0) {
        if (isTaken[i][w]) {
            cout << wt[i] << " ";
            w -= wt[i];
        }
        i--;
    }
    cout << endl;

    return K[n][W];
}

int main() {
    // int val[] = {10, 40, 30, 50};
    // int wt[] = {5, 4, 6, 3};
    // int W = 10;
    // int n = sizeof(val) / sizeof(val[0]);

    int size;
    cout << "Enter number of items: ";
    cin >> size;

    int val[size];
    cout << "Enter the value of each item: ";
    for (int i = 0; i < size; i++)
    {
        cin >> val[i];
    }
    int wt[size];
    cout << "Enter the weight of each item: ";
    for (int i = 0; i < size; i++)
    {
        cin >> wt[i];
    }
    int W;
    cout<<"enter the weight limit: ";
    cin>>W;
    cout << "Maximum value that can be obtained is " << knapsack(W, wt, val, size) << endl;

    return 0;
}

