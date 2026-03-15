#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <cmath>
using namespace std;

using pii = pair<int,int>;

int pairDist(pii a, pii b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        pii s,e;
        cin >> s.first >> s.second >> e.first >> e.second;

        vector<pii> nodes;
        nodes.push_back(s); //0 start
        nodes.push_back(e); //1 end

        vector<int> cost(n);

        for(int i=0;i<n;i++){
            cin >> s.first >> s.second >> e.first >> e.second >> cost[i];

            nodes.push_back(s); //2 + 2*i
            nodes.push_back(e); //3 + 2*i
        }

        int total = nodes.size();

        vector<vector<int>> dist(total, vector<int>(total, INT_MAX));

        // initialize distances
        for(int i=0;i<total;i++){
            for(int j=0;j<total;j++){
                if(i==j) dist[i][j]=0;
                else dist[i][j] = pairDist(nodes[i], nodes[j]);
            }
        }

        // add special edges
        for(int i=0;i<n;i++){
            int start = 2 + 2*i;
            int end   = 3 + 2*i;

            dist[start][end] = min(dist[start][end], cost[i]);
            dist[end][start] = min(dist[end][start], cost[i]);
        }

        // Floyd Warshall
        for(int k=0;k<total;k++){
            for(int i=0;i<total;i++){
                for(int j=0;j<total;j++){

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        cout << dist[0][1] << endl;
    }
}