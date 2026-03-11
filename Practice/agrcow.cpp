#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pos;
vector<int> comb;
int n, c;
int ans = 0;

void brute(int idx){

    if(comb.size() == c){
        int mindiff = 1e9;

        for(int i=1;i<c;i++){
            mindiff = min(mindiff, comb[i] - comb[i-1]);
        }

        ans = max(ans, mindiff);
        return;
    }

    if(idx == n) return;

    // take this position
    comb.push_back(pos[idx]);
    brute(idx + 1);
    comb.pop_back();

    // skip this position
    brute(idx + 1);
}

int main(){

    pos = {1,3,5,8,10};
    n = pos.size();
    c = 3;

    brute(0);

    cout << ans << endl;
}