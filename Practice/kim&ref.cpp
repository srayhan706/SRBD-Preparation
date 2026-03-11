#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int INF =1e9;

int paridist(pair<int,int> a,pair<int,int> b ){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int main(){
    int n;
    int cs=0;
    
    while ((cin>>n)){

        pair<int,int> h,o;

        cin>>h.first>>h.second>>o.first>>o.second;

        vector< pair<int,int> > fr(n);
        
        for(int i=0;i<n;i++){
            cin>>fr[i].first>>fr[i].second;
        }


        int Mask=1<<n;
        
        vector<vector<int>> dp(Mask,vector<int> (n,INF));

        for(int i=0;i<n;i++){
            dp[1<<i][i]=paridist(o,fr[i]);
        }

        for(int mask=1;mask<Mask;mask++){
            for(int u=0;u<n;u++){
                if(!(mask & (1<<u))){
                    continue;

                }

                for(int v=0;v<n;v++){
                    if(mask & (1<<v)){
                        continue;
                    }
                    int nextmask=mask | 1<<v;
                    dp[nextmask][v]=min(dp[nextmask][v],dp[mask][u]+paridist(fr[u],fr[v]));
                }
            }
        }

        int ans = INF;
        int fullmask=(1<<n)-1;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[fullmask][i]+paridist(h,fr[i]));
        }

        cout<<"# "<<++cs<<" "<<ans<<endl;
        



    }
}