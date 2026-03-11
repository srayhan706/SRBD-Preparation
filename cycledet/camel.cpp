#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int solve(vector<int> &cam){
    sort(cam.begin(),cam.end());

    int n=cam.size();
    int cost=0;

    while(n>3){
        int a1=cam[0];
        int a2=cam[1];
        int an=cam[n-1];
        int an1=cam[n-2];

        int st1=a1+2*a2+an;
        int st2=2*a1+an+an1;

        cost+=min(st1,st2);
        n-=2;
    }

    if(n==3){
        cost+=cam[0]+cam[1]+cam[2];
    }

    else if(n==2){
        cost+=cam[1];
    }
    else if(n==1){
        cost+=cam[0];
    }
    return cost;




}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> cam(n);
        for(int i=0;i<n;i++){
            cin>>cam[i];
        }

        cout<<solve(cam)<<endl;
    }
}