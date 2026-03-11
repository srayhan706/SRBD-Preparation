#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,k;
        cin>>a>>b>>c>>k;
        int ans=0;

        for(int i=1;i<=1000000;i++){
            if(k%i==0){
                int val=a+(b*log2(i))+(c*i*i);
                if(val==k/i){
                    ans=i;
                    break;
                }
            }
        }

    }
}