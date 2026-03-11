#include <iostream>
#include <vector>
using namespace std;
int n,m,k,ans;

void flipcol(int i,vector<vector<int>> &cpy){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cpy[i][j]=!cpy[i][j];
        }
    }

}

void back(int i,int k,vector<vector<int>> gr){
    if(k==0){
        int cntfullrow=0;
        for(int i=0;i<n;i++){
            int rowcnt=0;
            for(int j=0;j<m;j++){
                if(gr[i][j]==1){
                    rowcnt+=1;
                }

            }
            if(rowcnt==m){
                cntfullrow+=1;
            }
        }
        ans=max(ans,cntfullrow);
        return;

    }


    if(i>=m){
        return;
    }

    back(i+1,k,gr);

    vector<vector<int>> cpy=gr;
    for(int p=1;p<=k;p++){
        flipcol(i,cpy);
        back(i+1,k-p,cpy);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        vector<vector<int>> gr(n,vector<int> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>gr[i][j];
            }
        }
        ans=INT_MIN;
        back(0,k,gr);

        cout<<ans<<endl;

    }
}