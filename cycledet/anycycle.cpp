#include <iostream>
#include <vector>

using namespace std;

const int maxnode = 1e5 + 5;
vector<int> adj[maxnode];
bool vis[maxnode];       // visited
bool recStack[maxnode];  // recursion stack
vector<int> cyclePath;   // to store the cycle

bool dfs(int node) {
    vis[node] = true;
    recStack[node] = true;
    cyclePath.push_back(node);

    for (int neigh : adj[node]) {
        if (!vis[neigh]) {
            if (dfs(neigh)) return true;
        } else if (recStack[neigh]) {
            // cycle detected
            cyclePath.push_back(neigh); // close the cycle
            return true;
        }
    }

    recStack[node] = false;
    cyclePath.pop_back();
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i)) {
                found = true;
                break;
            }
        }
    }

    if (found) {
        // print the cycle
        int start = cyclePath.back();
        vector<int> result;
        result.push_back(start);
        for (int i = cyclePath.size() - 2; i >= 0; i--) {
            result.push_back(cyclePath[i]);
            if (cyclePath[i] == start) break;
        }
        for (int x : result) cout << x << " ";
    } else {
        cout << "No cycle found";
    }

    return 0;
}