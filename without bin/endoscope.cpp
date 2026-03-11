#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include <tuple>

using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]{0,0,-1,1};

map < int, vector<int> > pipedir={

    {1,{0,1,2,3}},
    {2,{0,1}},
    {3,{2,3}},
    {4,{0,3}},
    {5,{1,3}},
    {6,{1,2}},
    {7,{0,2}}
};

bool canconnect(int fromdir,int topipe){
    for(int d: pipedir[topipe]){
        if((fromdir==0 && d==1) || (fromdir==1 && d==0)|| (fromdir==2 && d==3)|| (fromdir==3 && d==2)){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,M,R,C,L;
        cin>>N>>M>>R>>C>>L;

        vector<vector<int>> grid(N,vector<int> (M));

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>grid[i][j];
            }
        }

        vector<vector<int>> vis(N,vector<int> (M,0));
        queue<tuple<int,int,int>> q;
        q.push({R,C,1});
        vis[R][C]=1;

        int ans=1;

        while(!q.empty()){
            auto [x,y,dist]=q.front();
            q.pop();

            if(dist==L){
                continue;
            }

            int type=grid[x][y];

            for(int dir: pipedir[type]){
                int nx=x+dx[dir];
                int ny=y+dy[dir];

                if(nx<0 || ny<0 || nx>=N || ny>=M){
                    continue;
                }

                if(vis[nx][ny]){
                    continue;
                }

                if(grid[nx][ny]==0){
                    continue;
                }

                if(canconnect(dir,grid[nx][ny])){
                    vis[nx][ny]=1;
                    ans++;
                    q.push({nx,ny,dist+1});
                }
            }
        }
        cout<<ans<<endl;
    }
}