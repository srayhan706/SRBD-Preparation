#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int n,m,k;
int finalans;
using namespace std;


void flipcolumn(int col, vector<vector<int>> &cpgrid){
    for(int i=0;i<n;i++){
        cpgrid[i][col]=!cpgrid[i][col];
    }
}


void backtrack(int i, int k, vector<vector<int>> grid){
    if(k==0){

        int cntfullr=0;

        for(int i=0;i<n;i++){
            int cntrow1=0;
            for(int j=0;j<m;j++){
                if (grid[i][j]==1){
                        cntrow1+=1;
                }
            }

            if(cntrow1==m){
                cntfullr+=1;
            }

        }

        finalans=max(finalans,cntfullr);
        return;

    }

    if(i>=m){
        return;
    }

    backtrack(i+1,k,grid); //wont flip column


    //will flip column

    vector<vector<int>> cpygrid=grid;

    //flip p time

    for(int p=1;p<=k;p++){
        flipcolumn(i,cpygrid);
        backtrack(i+1,k-p,cpygrid);
    }
}

int main(){

    cin>>n>>m>>k;
    vector<vector<int>> grid(n,vector<int> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    finalans=0;

    backtrack(0,k,grid);


    cout<<finalans<<endl;
    return 0;
}