
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
//     vector<vector<int>> K(n+1, vector<int>(W+1));

//     for (int i = 0; i <= n; i++) {
//         for (int w = 0; w <= W; w++) {
//             if (i == 0 || w == 0) {
//                 K[i][w] = 0;
//             } else if (wt[i-1] <= w) {
//                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
//             } else {
//                 K[i][w] = K[i-1][w];
//             }
//         }
//     }

//     return K[n][W];
// }

// int main() {
//     vector<int> val = {10,40,30,50};
//     vector<int> wt = {5,4,6,3};
//     int W = 10;
//     int n = val.size();

//     cout << "Maximum value that can be obtained is " << knapsack(W, wt, val, n) << endl;

//     return 0;
// }

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
    int val[] = {10, 40, 30, 50};
    int wt[] = {5, 4, 6, 3};
    int W = 10;
    int n = sizeof(val) / sizeof(val[0]);

    cout << "Maximum value that can be obtained is " << knapsack(W, wt, val, n) << endl;

    return 0;
}
