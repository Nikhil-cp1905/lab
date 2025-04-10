#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    // DP table
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    // Build the table bottom-up
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int length = lcs(X, Y);
    cout << "Length of LCS = " << length << endl;

    return 0;
}

