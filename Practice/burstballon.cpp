#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
vector<int> dp;
vector<int> b;


int solve(int mask){
    if(mask==0){
        return 0;
    }

    int &res =dp[mask];

    if(res !=-1){
        return res;
    }

    for(int i=0;i<n;i++){
        if(!(mask & (1<<i))){
            continue;
        }

        int l=-1,r=-1;

        //find a ballon at left

        for(int j=i-1;j>=0;j--){
            if(mask&(1<<j)){
                l=b[j];
                break;
            }
        }

        //find a ballon at right

        for(int j=i+1;j<n;j++){
            if(mask & (1<<j)){
                r=b[j];
                break;
            }
        }

        int gain = 0;

        if (l != -1 && r !=-1){
            gain = l*r;
        }
        else if(l !=-1){
            gain = l;
        }
        else if(r != -1){
            gain =r;
        }
        else{
            gain = b[i];
        }

        int newmask= mask ^ (1<<i);

        res = max(res,gain+solve(newmask));


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

    cout<<solve(Mask-1)<<"\n";


}