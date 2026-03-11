#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> gr;

bool isbip(int node, vector<int> &col){
    bool flag = true;

    for(int j = 0; j < col.size(); j++){
        if(gr[node][j] == 1){

            if(col[j] == -1){
                col[j] = 1 - col[node];
                flag = flag && isbip(j, col);
            }
            else if(col[node] == col[j]){
                return false;
            }
        }
    }

    return flag;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        gr.assign(n, vector<int>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> gr[i][j];
            }
        }

        vector<int> col(n, -1);
        bool ok = true;

        for(int i = 0; i < n; i++){
            if(col[i] == -1){
                col[i] = 0;

                if(!isbip(i, col)){
                    ok = false;
                    break;
                }
            }
        }

        if(!ok){
            cout << -1 << endl;
        }
        else{
            for(int i = 0; i < n; i++){
                if(col[i] == 0){
                    cout << i << " ";
                }
            }
            cout << endl;
        }
    }
}