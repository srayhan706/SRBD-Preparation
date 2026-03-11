#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> b;
vector<int> dp;


int solve(int mask){
    if(mask==0){
        return 0;
    
    }

    int &res=dp[mask];

    if(res != -1){
        return res;
    }

    for(int i=0;i<n;i++){
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

        for(int j=i+1;j<n;j++){
            if(mask & (1<<j)){
                rb=b[j];
                break;
            }
        }
        int gain=0;

        if(lb != -1 && rb != -1){
            gain=lb*rb;

        }
        else if(lb != -1){
            gain=lb;
        }
        else if(rb != -1){
            gain=rb;
        }
        else{
            gain=b[i];

        }
        

        int nextmask=mask ^ (1<<i);

        res=max(res,gain+solve(nextmask));

    }
    return res;

    
}

int main(){
    cin>>n;
    b.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int Mask=1<<n;
    dp.assign(1<<n,-1);

    cout<<solve(Mask-1)<<endl;

}