#include <iostream>
#include <vector>
#include <cmath>
const int INF=1e9;

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<vector<int>> adjmat(n,vector<int> (n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>adjmat[i][j];
            }
        }

            int Mask= 1 <<n;

            vector<vector<int>> dp(Mask,vector<int> (n,INF));

            dp[1][0]=0;

            for(int mask = 1; mask <Mask;mask++){
                for(int u=0;u<n;u++ ){
                    if(!(mask & (1<<u))){
                        continue;
                    }

                    for(int v=0;v<n;v++){
                        if(mask & (1<<v)){
                            continue;
                        }

                        //remember this

                        if(adjmat[u][v]==0){
                            continue;
                        }

                        int newmask= mask | (1<<v);
                        dp[newmask][v]=min(dp[newmask][v],dp[mask][u]+adjmat[u][v]);
                    }
                }
            }

            int ans=INF;
            int fullmask=(1<<n)-1;
            for(int i=1;i<n;i++){
                //remember unreachable condition
                if(adjmat[i][0] != 0){
                     ans=min(ans,dp[fullmask][i]+adjmat[i][0]);

                }
               
            }

            cout<<ans<<endl;

        }
}