#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};



bool isvalid(int nx,int ny,int n){
    if(nx>=0 && nx<n && ny>=0 && ny<n){
        return true;
    
    }
    return false; 
}

void bfs(pair<int,int> start,vector<vector<int>> &gr,vector<vector<int>> &dist,int n) {
    queue<pair<int,int>> q;
    vector<vector<int>> localdist(n,vector<int> (n,-1));
    q.push(start);
    localdist[start.first][start.second]=0;

    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();

        for(int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];

            if(isvalid(nx,ny,n) && gr[nx][ny]==1 && localdist[nx][ny]==-1){
                localdist[nx][ny]=localdist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(localdist[i][j]==-1){
                dist[i][j]=-1;
            }
            else if(dist[i][j]!=-1){
                dist[i][j]=max(localdist[i][j],dist[i][j]);
            }
            else{
                dist[i][j]=localdist[i][j];
            }
        }
    }


}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,r;
        cin>>n>>r;

        vector<pair<int,int>> rare(r);
        for(int i=0;i<r;i++){
            cin>>rare[i].first>>rare[i].second;
            rare[i].first--;
            rare[i].second--;
        }

        vector<vector<int>> gr(n,vector<int> (n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>gr[i][j];
            }
        }

        
        vector<vector<int>> dist(n,vector<int> (n,-1));

        for(auto &rp: rare){
            bfs(rp,gr,dist,n);
        }
        int ans=INT_MAX;


        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(gr[i][j]==1 && dist[i][j] !=-1){
                    ans=min(ans,dist[i][j]);

                }
                
            }
        }
        cout<<ans<<endl;

        



    }

}