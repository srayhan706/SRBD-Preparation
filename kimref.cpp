#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF=1e9;

int pairdist(pair<int,int> a,pair<int,int> b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}


int main(){
    int n;
    int c=1;

    while((cin>>n)){

        pair<int,int> h,o;

        cin>>h.first>>h.second>>o.first>>o.second;

        vector<pair<int,int>> rf(n);
        for(int i=0;i<n;i++){
            cin>>rf[i].first>>rf[i].second;
        }

        int Mask=1<<n;
        vector<vector<int>> dp(Mask,vector<int> (n,INF));

        for(int i=0;i<n;i++){
            dp[1<<i][i]=pairdist(o,rf[i]);
        }

        for(int mask=1;mask<Mask;mask++){
            for(int u=0;u<n;u++){
                if(!(mask & (1<<u))){
                    continue;
                }

                for(int v=0;v<n;v++){
                    if((mask) & (1<<v)){
                        continue;
                    }

                    int newmask=mask |(1<<v);

                    dp[newmask][v]=min(dp[newmask][v],dp[mask][u]+pairdist(rf[u],rf[v]));
                }
            }
        }

        int ans=INF;
        int fullmask=(1<<n)-1;

        for(int i=0;i<n;i++){
            ans=min(ans,dp[fullmask][i]+pairdist(h,rf[i]));
        }

        cout<<"# "<<c++<<" "<<ans<<endl;



        


    }
}