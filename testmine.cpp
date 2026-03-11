#include <iostream>
#include <vector>
using namespace std;
int n,m;
int oilmine[20];
int vis[20];
int ans;

void back(int i,int oilsum,int companies,int mn,int mx){
    if(vis[i]){
        if(companies==n){
            int newmin=min(oilsum,mn);
            int newmax=max(oilsum,mx);
            ans=min(ans,newmax-newmin);   
        }
        return;
    }
    vis[i]=true;
    int j=(i+1)%m;

    back(j,oilsum+oilmine[i],companies,mn,mx);
    int newmin=min(oilsum,mn);
    int newmax=max(oilsum,mx);
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
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
}
