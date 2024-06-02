#include <iostream>
#include <climits>
using namespace std;
//Iterative Approach
//Dynamic Programming
int matrixChainMultiplication(int dimensions[], int n) {
    int dp[n][n];
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int dimensions[] = {10, 30, 5, 60};
    int n = sizeof(dimensions) / sizeof(dimensions[0]);
    int minCost = matrixChainMultiplication(dimensions, n);
    cout << "Minimum cost of matrix chain multiplication: " << minCost << endl;
    return 0;
}