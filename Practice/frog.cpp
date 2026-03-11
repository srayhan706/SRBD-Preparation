#include<bits/stdc++.h>
using namespace std;

using pii = pair<pair<int,int>,int>;

int n;
vector<vector<int>> g;
vector<vector<bool>> vis;
int sx,sy,dx,dy;

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void solve(){
    queue<pii> q;

    q.push({{sx,sy},0});
    vis[sx][sy] = true;
    
    while(!(q.empty())){
        pii p = q.front(); q.pop();

        int i = p.first.first;
        int j = p.first.second;
        int c = p.second;
        if(i==dx && j == dy){
            cout << c << endl;
            return;
        }

        if(g[i][j]==1){
            if(valid(i,j+1) && !vis[i][j+1] && g[i][j+1]==1){
                q.push({{i,j+1},c});
                vis[i][j+1] = true;
            }
            if(valid(i,j-1) && !vis[i][j-1] && g[i][j-1]==1){
                q.push({{i,j-1},c});
                vis[i][j-1] = true;
            }
            if (valid(i - 1, j) && !vis[i - 1][j])
            {
                q.push({{i - 1, j}, c + 1});
                vis[i - 1][j] = true;
            }
            if (valid(i + 1, j) && !vis[i + 1][j])
            {
                q.push({{i + 1, j}, c + 1});
                vis[i + 1][j] = true;
            }
        }
        else
        {
            if (valid(i - 1, j) && !vis[i - 1][j])
            {
                q.push({{i - 1, j}, c+1});
                vis[i - 1][j] = true;
            }
            if (valid(i + 1, j) && !vis[i + 1][j])
            {
                q.push({{i + 1, j}, c+1});
                vis[i + 1][j] = true;
            }
        }
    }

}

int main(){
    cin >> n;
    g.resize(n,vector<int>(n,0));
    vis.resize(n,vector<bool>(n,false));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> g[i][j];
        }
    }
    cin >> sx >> sy >> dx >> dy;
    solve();
}