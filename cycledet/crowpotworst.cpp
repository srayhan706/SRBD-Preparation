#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> O(n);
    for (int i = 0; i < n; i++) cin >> O[i];

    sort(O.begin(), O.end()); // sort ascending

    int sum = 0;
    for (int i = 0; i < n - k + 1; i++) {
        sum += O[i];
    }

    cout << 2 * sum << endl; // worst-case stones
    return 0;
}