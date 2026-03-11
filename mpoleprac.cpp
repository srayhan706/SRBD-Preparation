#include <iostream>
#include <vector>
using namespace std;
int n;
int ans;
int a[20];
int vis[20];

void back(int p1,int p2){
    
    if(p1==p2){
        ans=max(ans,p1);
        
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=true;
            back(p1+a[i],p2);
            back(p1,p2+a[i]);
            vis[i]=false;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
            vis[i]=0;
        }

        ans =INT_MIN;

        back(0,0);
        cout<<ans<<endl;
    }
}
