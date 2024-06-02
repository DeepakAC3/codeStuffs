#include<bits/stdc++.h>
#include<climits>
using namespace std;

const int N = 10; // Maximum number of cities

int tsp(int mask, int pos, int n, vector<vector<int>>& dist, vector<vector<int>>& dp) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Return to starting city
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos]; // Return memoized value
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) { // Check if city i is not visited
            int newMask = mask | (1 << i);
            int cost = dist[pos][i] + tsp(newMask, i, n, dist, dp);
            ans = min(ans, cost);
        }
    }
    return dp[mask][pos] = ans; // Memoize and return the answer
}

int main() {
    int n; // Number of cities
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));
    // Input the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    vector<vector<int>> dp(1 << N, vector<int>(N, -1)); // DP table
    int ans = tsp(1, 0, n, dist, dp); // Start from city 0
    cout << "Minimum cost: " << ans << endl;
    return 0;
}