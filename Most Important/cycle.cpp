#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<int> vis, par, cyc;

// DFS function to detect cycle
bool dfs(int u) {
    vis[u] = 1; // mark as visiting (in recursion stack)

    for(int v : g[u]) {
        if(!vis[v]) { // unvisited
            par[v] = u;
            if(dfs(v)) return true; // if cycle found deeper, return
        }
        else if(vis[v] == 1) { // back edge -> cycle detected
            // Reconstruct the cycle
            int currentNode = u;
            while(currentNode != v) {
                cyc.push_back(currentNode);
                currentNode = par[currentNode];
            }
            cyc.push_back(v); // add start of cycle
            return true;
        }
    }

    vis[u] = 2; // mark as fully processed
    return false;
}

int main() {
    int T; 
    cin >> T; // number of test cases

    for(int tc = 1; tc <= T; tc++) {
        int n, m;
        cin >> n >> m; // number of nodes and edges

        g.assign(n + 1, {});       // adjacency list
        vis.assign(n + 1, 0);      // visitation state
        par.assign(n + 1, -1);     // parent array
        cyc.clear();               // cycle nodes

        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);     // directed edge u -> v
        }

        for(int i = 1; i <= n && cyc.empty(); i++){
             if(!vis[i]){
                dfs(i);
             } 

        }
           

        cout << "#" << tc << " ";
        if(cyc.empty()) {
            cout << 0;
        } else {
            sort(cyc.begin(), cyc.end());
            //cyc.erase(unique(cyc.begin(), cyc.end()), cyc.end());
            for(int x : cyc) cout << x << " ";
        }
        cout << "\n";
    }
}