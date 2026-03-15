#include <iostream>
#include <vector>
#include <cstring>
bool ans;
int n,m;

int mat[15][15];
int vis[15][15];
using namespace std;




void dfs(int r,int c,int l){


    if(r<0 || r>=n || c<0 || c>=m ){
        return;

    }

    if(vis[r][c]){
        return;
    }
    
    vis[r][c]=true;

    if(mat[r][c]==3){
        ans=true;
        return;
    }

    //horizontal left right move

    if(c+1<m && mat[r][c+1] !=0 && !vis[r][c+1]){
        dfs(r,c+1,l); //right
    }

    if(c-1>=0 && mat[r][c-1] !=0 && !vis[r][c-1]){
        dfs(r,c-1,l); //left
    }

     //vertical up down move

    

    for(int h=1;h<=l;h++){
        //up

        if(r-h>=0 && mat[r-h][c] != 0 && !vis[r-h][c]){
            dfs(r-h,c,l);
        }

        //down
        if(r+h<n && mat[r+h][c] != 0 && !vis[r+h][c]){
            dfs(r+h,c,l);
        }
    }




   

}

int main(){
    
    cin>>n>>m;

   
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }


    

    for(int l=0;l<=m;l++){
        ans=false;

       memset(vis,false,sizeof(vis));


        dfs(n-1,0,l);

        if(ans){
            cout<<l<<endl;
            break;
        }

    }
}