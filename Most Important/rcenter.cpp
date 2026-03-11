#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<vector<int>> bfs(int sx, int sy, vector<vector<int>>& grid, int n) {
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int,int>> q;

    dist[sx][sy] = 0;
    q.push({sx, sy});

    while(!q.empty()) {
        auto p = q.front(); q.pop();
        int x = p.first;
        int y = p.second;

        for(int d=0; d<4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx>=0 && nx<n && ny>=0 && ny<n &&
               grid[nx][ny]==1 && dist[nx][ny]==-1) {

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }

    return dist;
}

int main() {

    int t;
    cin >> t;

    while(t--) {

        int n,r;
        cin >> n >> r;

        vector<pair<int,int>> rare(r);

        for(int i=0;i<r;i++){
            cin >> rare[i].first >> rare[i].second;
            rare[i].first--;
            rare[i].second--;
        }

        vector<vector<int>> grid(n, vector<int>(n));

        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> grid[i][j];

        vector<vector<vector<int>>> dist(r);

        for(int i=0;i<r;i++)
            dist[i] = bfs(rare[i].first, rare[i].second, grid, n);

        int answer = INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==0) continue;

                int maxDist = 0;
                bool ok = true;

                for(int k=0;k<r;k++){

                    int d = dist[k][i][j];

                    if(d==-1){
                        ok=false;
                        break;
                    }

                    maxDist = max(maxDist, d);
                }

                if(ok)
                    answer = min(answer, maxDist);
            }
        }

        cout << answer << endl;
    }

    return 0;
}