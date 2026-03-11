#include <iostream>
#include <vector>
using namespace std;


bool isbip(int i,vector<int> &col, vector<vector<int>> &adjmat){
    for(int j=0;j<col.size();j++){
        if(adjmat[i][j]){
            if(col[j]==-1){
                col[j]=1-col[i];
                if(!isbip(j,col,adjmat)){
                    return true;
                }
            }
            else if(col[i]==col[j]){
                return false;
            }
        }
    }
    return true;
}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> adjmat(n,vector<int> (n));
    vector<int> col(n,-1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adjmat[i][j];
        }
    }

    for(int i=0;i<n;i++){
        if(col[i]==-1){
            col[i]=0;
            if(!isbip(i,col,adjmat)){
                cout<<-1<<endl;
                return 0;
            }
        }
    }

    cout<<1<<endl;


}