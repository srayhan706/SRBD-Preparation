#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int main() {
    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        int n,m;
        cin >> n >> m;

        vector<vector<int>> mat(n,vector<int> (m));
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin >> mat[j][k];
            }
        }

        int r,c;
        cin >> r >> c;
        r--; c--;  // 0-based index

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,-1));
        q.push({r,c});
        dist[r][c] = 0;

        int maxtime = 0;  // start from 0

        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();

            int x = cur.first;
            int y = cur.second;

            for(int d=0;d<4;d++){
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(mat[nx][ny]==1 && dist[nx][ny]==-1){
                        dist[nx][ny] = dist[x][y] + 1;
                        maxtime = max(maxtime, dist[nx][ny]);
                        q.push({nx,ny});
                    }
                }
            }
        }

        cout << "Case #" << (i+1) << "\n";
        cout << maxtime << "\n\n";
    }
}