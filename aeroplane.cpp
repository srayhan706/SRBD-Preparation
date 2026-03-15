#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


// n denotes row number, j denotes column number, do we have bomb,  graph, n ki jani na apatoto


int dfs(int i,int j, bool bomb, vector<vector<int>> v,int n){


    // we have come to 1st row
    if(i<0){
        return 0;
    }

    //we faced enemy
    if(v[i][j]==2){
        return 0;
    }

    int ans=0;
    if(v[i][j]==1){
        ans+=1;
    }

    //we have bomb

    if(bomb){

        //bomb marbo

        vector<vector<int>> cpy=v;

        for(int p=max(i-5,0);p<i;p++){
            for(int q=0;q<5;q++){
                if (cpy[p][q]==2){
                    cpy[p][q]=0;
                }
            }
        }

        int op1=0,op2=0,op3=0;


        //move to right
        if(j+1<5){
            op1=dfs(i-1,j+1,false,cpy,n);
        }
        //move to left
        if(j-1>=0){
            op2=dfs(i-1,j-1,false,cpy,n);
        }
        //move to up
       
            op3=dfs(i-1,j,false,cpy,n);
        
        int finalans1=max({op1,op2,op3})+ans;




        //bomb marbo na

        op1=0,op2=0,op3=0;
        


        //move to right
        if(j+1<5){
            op1=dfs(i-1,j+1,bomb,v,n);
        }
        //move to left
        if(j-1>=0){
            op2=dfs(i-1,j-1,bomb,v,n);
        }
        //move to up
        
            op3=dfs(i-1,j,bomb,v,n);
        
        int finalans2=max({op1,op2,op3})+ans;


        return max(finalans1,finalans2);


    }

    //we don't have bomb

    else{

        int op1=0,op2=0,op3=0;


        //move to right
        if(j+1<5){
            op1=dfs(i-1,j+1,bomb,v,n);
        }
        //move to left
        if(j-1>=0){
            op2=dfs(i-1,j-1,bomb,v,n);
        }
        //move to up
        
            op3=dfs(i-1,j,bomb,v,n);
        
        int finalans2=max({op1,op2,op3})+ans;

        return finalans2;

    }


}

int main(){
    int t;
    cin>>t;
    for(int ts=1;ts<=t;ts++){
        int n;
        cin>>n;
        vector<vector<int>> gr(n+1,vector<int> (5));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>gr[i][j];
            }
        }

        for(int j=0;j<5;j++){
            gr[n][j]=0;
        }


        cout<<"#"<<ts<<" "<<dfs(n,2,true,gr,n)<<endl;


    }
}