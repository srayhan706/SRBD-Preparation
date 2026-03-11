#include <iostream>
#include <vector>
#include <map>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

map<int,vector<int>> pipedir={
    {1,{0,1,2,3}},
    {2,{0,1}},
    {3,{2,3}},
    {4,{0,3}},
    {5,{1,3}},
    {6,{1,2}},
    {7,{0,2}}
};

bool canconn(int frpipe,int topipe){
    for(int dir:pipedir[topipe]){
        if(frpipe==0 && dir==1 || frpipe==1 && dir==0 || frpipe==2 && dir==3 || frpipe==3 && dir==2 ){
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
        vector<vector<int>> gr(N,vector<int> (M,0));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>gr[i][j];
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
            int pipetype=gr[x][y];

            for(int dir: pipedir[pipetype]){
                int nx=x+dx[dir];
                int ny=y+dy[dir];

                if(nx<0 && nx>=N && ny<0 && ny>=M){
                    continue;
                }

                if(vis[nx][ny]){
                    continue;
                }
                if(gr[nx][ny]==0){
                    continue;
                }

                if(canconn(dir,gr[nx][ny])){
                    vis[nx][ny]=1;
                    ans=+1;
                    q.push({nx,ny,dist+1});
                }
            }
        }
        cout<<ans<<endl;
    }
}