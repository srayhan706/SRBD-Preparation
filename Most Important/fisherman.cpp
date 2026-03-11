#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int gate[3];
int fisher[3];
int ans=INT_MAX;
bool used[11];

void dfs(int idx,int order[],int distsum){

    if(idx==3){
        ans=min(ans,distsum);
        return;
    }

    int g=order[idx];
    int pos=gate[g];
    int f=fisher[g];



    function<void(int,int)> place = [&](int cnt,int sum){
        if(cnt==f){
            dfs(idx+1,order,distsum+sum);
            return;
        }

        int d=0;

        while(true){
            bool leftvalid=false,rightvalid=false;
            int l=pos-d;
            int r=pos+d;

            if(l>=1 && !used[l]){
                leftvalid=true;
            }
            if(r<=N && !used[r] && d !=0){
                rightvalid=true;
            }

            if(leftvalid){
                used[l]=true;
                place(cnt+1,sum+d+1);
                used[l]=false;
            }
            if(rightvalid){
                used[r]=true;
                place(cnt+1,sum+d+1);
                used[r]=false;
            }

            if(leftvalid || rightvalid){
                break;
            }
            d++;
        }
    
    };
    place(0,0);

}

int main(){
    cin>>N;

    for(int i=0;i<3;i++){
        cin>>gate[i];
    }

    for(int i=0;i<3;i++){
        cin>>fisher[i];
    }

    int order[3]={0,1,2};
    do{
        memset(used,false,sizeof(used));
        dfs(0,order,0);
    }while(next_permutation(order,order+3));

    cout<<ans<<endl;
}