#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> gr;
vector<vector<int>> grAns;

int ans,n;

vector<pair<int, int>> vp = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n) return false;
    return (gr[i][j] == 0 || gr[i][j] == 2);
}


void dfs(int i,int j,int cnt){
    if(i==n-1 && j==n-1){
        if(cnt>ans) return;
        ans = cnt;
        for(int p=0;p<n;p++){
            for(int q=0;q<n;q++){
                grAns[p][q] = gr[p][q];
            }
        }
        return;
    }

    for(auto p : vp){
        int xi = i + p.first;
        int yi = j + p.second;
        if(valid(xi,yi)){
            int val = gr[xi][yi];

            gr[xi][yi] = 3;
            if(val==2){
                dfs(xi,yi,cnt+1);
            }else{
                dfs(xi,yi,cnt);
            }

            gr[xi][yi] = val;
        }
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n;
        ans = INT_MAX;
        grAns.assign(n, vector<int>(n));
        gr.assign(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> gr[i][j];
            }
        }
        int cnt = 0;
        if(gr[0][0]==2) cnt++;
        gr[0][0] = 3;
        dfs(0,0,cnt);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << grAns[i][j] <<" ";
            }
            cout << endl;
        }
        cout << ans << endl;
    }
}