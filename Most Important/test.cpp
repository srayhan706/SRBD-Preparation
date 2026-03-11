#include <iostream>
using namespace std;

int solve(int mask, vector<int> &dp,vector<int> &b){
    if(mask==0){
        return 0;
    }

    int &res=dp[mask];
    if(res !=-1 ){
        return res;
    }

    for(int i=0;i<b.size();i++){
        if(!(mask & (1<<i))){
            continue;
        }

        int lb=-1,rb=-1;

        for(int j=i-1;j>=0;j--){
            if(mask & (1<<j)){
                lb=b[j];
                break;
            }
        }
        for(int j=i+1;j<b.size();j++){
            if(mask & (1<<j)){
                rb=b[j];
                break;
            }
        }

        int gain=0;

        if(lb != -1 && rb != -1){
            gain=rb*b[i]*lb;
        }
        else if(lb !=-1) {
            gain=lb*b[i];
        }
        else if(rb !=-1){
            gain=rb*b[i];
        }
        else{
            gain=b[i];
        }
        int nextmask=mask ^ (1<<i);
        res=max(res,gain+solve(nextmask,dp,b));
    }
    return res;
}


int main(){
    int n;
    cin>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int Mask=1<<n;
    vector<int> dp(Mask,-1);

    cout<<solve(Mask-1,dp,b);

}