#include <iostream>

using namespace std;

const int MAX_ROWS=10; 
const int MAX_COLS=10;
int maxCoinsCollected(int C[MAX_ROWS][MAX_COLS], int rows, int cols) {
   
    int F[MAX_ROWS][MAX_COLS];

    F[0][0] = C[0][0];

    
    for (int i = 1; i < rows; i++) {
        F[i][0] = F[i - 1][0] + C[i][0];
    }
    for (int j = 1; j < cols; j++) {
        F[0][j] = F[0][j - 1] + C[0][j];
    }

    
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            F[i][j] = C[i][j] + max(F[i - 1][j], F[i][j - 1]);
        }
    }

   
    return F[rows - 1][cols - 1];
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int C[MAX_ROWS][MAX_COLS];
    cout << "Enter the values in the Coin table:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> C[i][j];
        }
    }

    int maxCoins = maxCoinsCollected(C, rows, cols);
    cout << "Maximum coins collected: " << maxCoins << endl;

    return 0;
}
