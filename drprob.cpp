#include<iostream>
#include <vector>
using namespace std;

using pii = pair<int,double>;

void dfs(int i,int t,double p,vector<vector<pii>> &gr,vector<double> &ans){
    if(t<=0){
        ans[i] += p;
        return;
    }

    for(pii c : gr[i]){
        int nxt = c.first;
        double prob = c.second;

        if(prob!=0.0){
            // p*=prob;
            dfs(nxt,t-10,p*prob,gr,ans);
            // p/=prob;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,T;
        cin >> n >> m >> T;
        vector<double> ans(n+1,0.0);
        vector<vector<pii>> gr(n+1);
        int x,y;
        double w;
        for(int i=0;i<m;i++){
            cin >> x >> y >> w;
            gr[x].push_back({y,w});
        }

        dfs(1, T, 1.0, gr, ans);
        int mxProb = max_element(ans.begin(),ans.end()) - ans.begin();

        printf("%d %.6lf\n", mxProb, ans[mxProb]);
    }
    
}

