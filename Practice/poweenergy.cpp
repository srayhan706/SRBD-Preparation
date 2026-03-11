#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int H, D;
vector<int> cost(5), tim(5);
int ans = INT_MAX;

void brute(int dist, int energy, int timeTaken){
    
    // if energy exceeded stop
    if(energy > H) return;

    // if distance completed
    if(dist == D){
        ans = min(ans, timeTaken);
        return;
    }

    // try all 5 speeds
    for(int i = 0; i < 5; i++){
        brute(dist + 1,
              energy + cost[i],
              timeTaken + tim[i]);
    }
}

int main(){

    cin >> H;
    cin >> D;

    for(int i = 0; i < 5; i++)
        cin >> cost[i];

    for(int i = 0; i < 5; i++)
        cin >> tim[i];

    brute(0, 0, 0);

    if(ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}