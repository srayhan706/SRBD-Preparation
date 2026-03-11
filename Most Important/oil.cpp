#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//n=number of companies m=number of oil mines
int n,m,ans;
int oilmine[20];
int vis[20];


void back(int i,int sum,int companies,int mn,int mx ){
    if(vis[i]){
        if(companies==n){
            int newmin=min(sum,mn);
            int newmax=max(sum,mx);
            ans=min(ans,newmax-newmin);
        }
        return;
    }

    int j=(i+1) % m;
    vis[i]=true;

    back(j,sum+oilmine[i],companies,mn,mx);
    int newmin=min(sum,mn);
    int newmax=max(sum,mx);

    back(j,oilmine[i],companies+1,newmin,newmax);
    vis[i]=false;

}

int main(){

    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        

        for(int i=0;i<m;i++){
            cin>>oilmine[i];
            vis[i]=false;
        }

        ans=INT_MAX;

        for(int i=0;i<m;i++){
            back(i,0,1,INT_MAX,INT_MIN);
        }
        if(n>m){
            ans=-1;
        }
        else{
            cout<<ans<<endl;
        }

    }
    


}