#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
int n;
int gate[3];
int fisher[3];
int used[20];
int ans=INT_MAX;
using namespace std;

void dfs(int indx, int order[],int distsum){
    if(indx==3){
        ans=min(ans,distsum);
        return;
    }

    int g=order[indx];
    int pos=gate[g];
    int f=fisher[g];

    function<void(int,int)> place = [&](int cnt,int sum){
        if (cnt==f){
            dfs(indx+1,order,distsum+sum);
        }

        int d=0;

        while(true){

            bool leftvalid=false,righvalid=false;
            int l=pos-d;
            int r=pos+d;

            if(l>=1 && !used[l]){
                leftvalid=true;
            }

            if(r<=n && !used[r] && d!=0){
                righvalid=true;
            }

            //possible on left

            if(leftvalid){
                used[l]=1;
                place(cnt+1,sum+d+1);
                used[l]=false;
            }

            //possible on right
            if(righvalid){
                used[r]=1;
                place(cnt+1,sum+d+1);
            }

            //notpossible in both side

            if(leftvalid || righvalid){
                break;
            }

            d++;
        }

    };



    place(0,0);
}

int main(){

    cin>>n;

    for(int i=0;i<3;i++){
        cin>>gate[i];
    }

    for(int i=0;i<3;i++){
        cin>>fisher[i];
    }

    int order[3]={0,1,2};
    do{
        memset(used,false,sizeof(false));
        dfs(0,order,0);
    }while(next_permutation(order,order+3));

    cout<<ans<<endl;
}