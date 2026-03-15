#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long minTransportCost(vector<long long>& camels) {
    sort(camels.begin(), camels.end());
    long long total = 0;
    int n = camels.size();

    while (n > 3) {
        long long optionA = 2 * camels[1] + camels[0] + camels[n-1];
        long long optionB = 2 * camels[0] + camels[n-2] + camels[n-1];
        total += min(optionA, optionB);
        n -= 2; // two camels moved permanently
    }

    if (n == 3) {
        total += camels[0] + camels[1] + camels[2];
    } else if (n == 2) {
        total += max(camels[0], camels[1]);
    } else if (n == 1) {
        total += camels[0];
    }

    return total;

}


int main() {
   

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> camels(n);
        for (int i = 0; i < n; i++) cin >> camels[i];
        cout << minTransportCost(camels) << "\n";
    }
    return 0;
}

