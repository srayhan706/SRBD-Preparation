#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    int d = n - 1;
    int j = 0;
    long long ans = 0;
    long long prev = 0;
    for(int i=n-1;i>=n-k;i--){
        ans+=((a[i]-prev)*(i+1));
        prev+=a[i];
    }
    cout << ans << endl;
    return 0;
}