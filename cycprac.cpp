#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> adj;
vector<int> vis,par,cy;


bool dfs(int u){
    vis[u]=1;

    for(int neighb: adj[u]){
        if(!vis[neighb]){
            par[neighb]=u;
            if(dfs(neighb)){
                return true;
            }
        }
        else if(vis[neighb]==1){
            int currnode=u;
            while (currnode != neighb){
                cy.push_back(currnode);
                currnode=par[currnode];
            }
            cy.push_back(neighb);
            return true;


        }
    }
    vis[u]=2;

    return false;
}

int main(){
    int t;
    cin>>t;
    for(int ts=0;ts<t;ts++){
        int n,m;
        cin>>n>>m;
        
        adj.assign(n+1,{});
        vis.assign(n+1,0);
        par.assign(n+1,-1);
        cy.clear();

        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        for(int i=1;i<=n && cy.empty();i++){
            if(!vis[i]){
                dfs(i);
            }
        }

        if(cy.empty()){
            cout<<0<<endl;
        }
        else{
            sort(cy.begin(),cy.end());
            for(int x: cy){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
}