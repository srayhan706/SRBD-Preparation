#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
const ll INF=1e18;
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<vector<int>> adjmat(n,vector<int> (n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>adjmat[i][j];
            }
        }

        int Mask=1<<n;
        vector<vector<ll>> dp(Mask,vector<ll> (n,INF));
        dp[1][0]=0;

        for(int mask=1;mask<Mask;mask++){
            for(int u=0;u<n;u++){

                if(!(mask &(1<<u))){
                    continue;

                }

                for(int v=0;v<n;v++){
                    if(mask & (1<<v)){
                        continue;
                    }

                    int nextmask = mask | (1<<v);

                    dp[nextmask][v]=min(dp[nextmask][v],dp[mask][u]+adjmat[u][v]);
                }



            }
        }
         ll ans = INF;
        int fullmask=(1<<n)-1;

        for(int i=1;i<n;i++){
            ans=min(ans,dp[fullmask][i]+adjmat[i][0]);
        }

        cout<<ans<<endl;


    }
   


}
