#include <iostream>
#include <climits>
using namespace std;
//Recursive Approach
//memoization
int matrixChainMultiplication(int dims[], int i, int j, int** dp) {
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = matrixChainMultiplication(dims, i, k, dp) +
                   matrixChainMultiplication(dims, k + 1, j, dp) +
                   dims[i - 1] * dims[k] * dims[j];
        dp[i][j] = min(dp[i][j], cost);
    }
    return dp[i][j];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    int dims[n + 1];
    cout << "Enter the dimensions of the matrices: "; // 10 30 5 60
    for (int i = 0; i <= n; i++)
        cin >> dims[i];
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = new int[n + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;
    int minCost = matrixChainMultiplication(dims, 1, n, dp);
    cout << "Minimum cost of matrix chain multiplication: " << minCost << endl;
    for (int i = 0; i <= n; i++)
        delete[] dp[i];
    delete[] dp;
    return 0;
}