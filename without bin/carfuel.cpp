#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int ans;
int  c[20];

void back(int carnum,int dist,int robpos,int fueltype, int fuelamnt){

    if(dist>ans){
        return;
    }


    if(carnum==n){
        ans=min(dist,ans);
        return;
    }
    
    if(robpos==0){
        back(carnum,dist+1,robpos+1,1,2);
        return;

    }
    if(robpos==n+1){
        back(carnum,dist+1,robpos-1,2,2);
        return;
    }

    int nextpos,refilcost,refilloc;


    //fule type 1
    if(fueltype==1){
        nextpos=1;
        refilcost=robpos;
        refilloc=0;
    }

    //fuletype2
    else{
        nextpos=-1;
        refilcost=n-robpos+1;
        refilloc=n+1;
    }

    if(fueltype==c[robpos]){
        if(fuelamnt>0){
            int x=c[robpos];
            c[robpos]=0;
            back(carnum+1,dist+1,robpos+nextpos,fueltype,fuelamnt-1);
            back(carnum+1,dist+refilcost,refilloc,fueltype,fuelamnt);
            c[robpos]=x;
        }
        back(carnum,dist+1,robpos+nextpos,fueltype,fuelamnt);

    }
    else{
        back(carnum,dist+1,robpos+nextpos,fueltype,fuelamnt);
    }

}

int main(){

    int t;
    cin>>t;
    while(t--){
        cin >>n;
        for(int i=1;i<=n;i++){
            cin>>c[i];
        }
        ans=INT_MAX;
        back(0,0,0,0,0);

        cout<<ans-1<<endl;

        
    }

}