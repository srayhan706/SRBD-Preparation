#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxnode = 1005; // adjust as needed
vector<int> adj[maxnode];
bool vis[maxnode];
vector<int> path;
vector<vector<int>> allCycles;

void dfs(int node, int start) {
    vis[node] = true;
    path.push_back(node);

    for (int neigh : adj[node]) {
        if (neigh == start) {
            // Found a cycle
            path.push_back(start);
            allCycles.push_back(path);
            path.pop_back();
        } else if (!vis[neigh]) {
            dfs(neigh, start);
        }
    }

    path.pop_back();
    vis[node] = false;
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        fill(vis, vis + maxnode, false);
        path.clear();
        dfs(i, i);
    }

    if (allCycles.empty()) {
        cout << "No cycles found\n";
    } else {
        cout << "Cycles found:\n";
        for (auto &cycle : allCycles) {
            for (int x : cycle) cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}