#include <iostream>
#include<algorithm>
using namespace std;

//const int MAX_N = 100;  

// int minCost(int costMatrix[i][j], int i, int j) {
//     int MinCost[i][j];
//     int n, m;

  
    // cout << "Enter the number of rows (n): ";
    // cin >> n;
    // cout << "Enter the number of columns (m): ";
    // cin >> m;


    // MinCost[0][0] = costMatrix[0][0];

    // for (int col = 1; col <= j; col++) {
    //     MinCost[0][col] = MinCost[0][col - 1] + costMatrix[0][col];
    // }

    
    // for (int row = 1; row <= i; row++) {
    //     MinCost[row][0] = MinCost[row - 1][0] + costMatrix[row][0];
    // }


    // for (int row = 1; row <= i; row++) {
    //     for (int col = 1; col <= j; col++) {
    //         MinCost[row][col] = costMatrix[row][col] + min(MinCost[row - 1][col], MinCost[row][col - 1]);
    //     }
    // }

//     return MinCost[i][j];
// }

int main() {
    

    cout << "Enter the cost matrix (n x m):" << endl;
    int n, m;

    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;
    int costMatrix[n][m] ;
    int MinCost[n][m];
    cout << "Enter the cost values:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> costMatrix[i][j];
        }
    }

    // int i, j;
    // cout << "Enter the destination cell coordinates (i j): ";
    // cin >> i >> j;
    
      MinCost[0][0] = costMatrix[0][0];

    for (int col = 1; col <= m; col++) {
        MinCost[0][col] = MinCost[0][col - 1] + costMatrix[0][col];
    }

    
    for (int row = 1; row <= n; row++) {
        MinCost[row][0] = MinCost[row - 1][0] + costMatrix[row][0];
    }


    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            MinCost[row][col] = min(MinCost[row - 1][col], MinCost[row][col - 1], MinCost[row-1][col-1])+costMatrix[row][col] ;
        }
    }
    // int result = minCost(costMatrix, n, m);
    cout << "Minimum cost to reach cell (" << n << ", " << m << ") is: " << MinCost[n-1][m-1]<< endl;

    return 0;
}
