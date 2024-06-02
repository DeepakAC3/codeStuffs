#include <iostream>
#include <string>
#include <vector>
using namespace std;

int stringMatching(string& text, string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text[i - 1] == pattern[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] == m) {
                return i - m;
            }
        }
    }
    return -1;
}

int main() {
    string text = "Hello, world!";
    string pattern = "world";
    int index = stringMatching(text, pattern);
    if (index != -1)
        cout << "Pattern found at index " << index << endl;
    else
        cout << "Pattern not found" << endl;
    return 0;
}