#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

// dp[n][k] -> minimum stones to overflow k pots among first n pots
int dp[101][101];

int minStones(vector<int>& O, int n, int k) {
    if (k == 0) return 0;       // no pots to overflow
    if (n == 0) return INF;     // impossible
    if (dp[n][k] != -1) return dp[n][k];

    int res = INF;

    // try overflowing each pot among first n pots
    for (int i = 0; i < n; i++) {
        int stones = O[i] + minStones(O, i, k - 1);
        res = min(res, stones);
    }

    return dp[n][k] = res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> O(n);
    for (int i = 0; i < n; i++) cin >> O[i];

    sort(O.begin(), O.end());  // sort ascending for proper worst-case simulation

    memset(dp, -1, sizeof(dp));

    int result = minStones(O, n, k);
    cout << result << endl;

    return 0;
}