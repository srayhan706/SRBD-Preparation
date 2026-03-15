#include <iostream>
#include <vector>
using namespace std;

int main(){
    int l,r,k;
    cin>>l>>r>>k;
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans=0;

    

    for(int i=l;i<=r;i++){
        int num=i;
        int freq[10]={0};

        while(num){
            int dig=num%10;
            num/=10;
            freq[dig]++;

        }

        int cnt=0;
        for(int j=0;j<n;j++){
            cnt+=freq[j];
        }

        if(cnt<k){
            ans++;
        }
        else{
            //cout<<i<<endl;

        }
    }
    cout<<ans<<endl;
}