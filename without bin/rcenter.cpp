#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int bfs(pair<int,int> start, vector<vector<int>>& grid, int n, vector<vector<int>>& dist) {
    queue<pair<int,int>> q;
    vector<vector<int>> localDist(n, vector<int>(n, -1));

    q.push(start);
    localDist[start.first][start.second] = 0;

    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();

        for(int d=0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==1 && localDist[nx][ny]==-1){
                localDist[nx][ny] = localDist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }

    // update the global dist array
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(localDist[i][j]==-1){
                dist[i][j]=-1;

            } 
            else if(dist[i][j]!=-1){
                dist[i][j] = max(dist[i][j], localDist[i][j]);

            } 
            else {
                dist[i][j] = localDist[i][j];
            }
        }
    }

    return 0;
}

int main(){
    int t; 
    cin >> t;
    while(t--){
        int n,r; 
        cin >> n >> r;
        vector<pair<int,int>> rare(r);
        for(int i=0;i<r;i++){
            cin >> rare[i].first >> rare[i].second;
            rare[i].first--; rare[i].second--;
        }

        vector<vector<int>> grid(n, vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> grid[i][j];

        vector<vector<int>> dist(n, vector<int>(n, -1));

        for(auto& rp: rare)
            bfs(rp, grid, n, dist);

        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && dist[i][j]!=-1)
                    ans = min(ans, dist[i][j]);
            }
        }

        cout << ans << endl;
    }
}