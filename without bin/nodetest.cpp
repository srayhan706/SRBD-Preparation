#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        string s;
        cin>>s;
        
        int ans=0;
        int level=-1;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                level++;
            }
            else if(s[i]==')'){
                level--;
            }
            else{
                int sign=1;
                if(s[i]=='-'){
                    sign=-1;
                    i++;
                }
                int num=0;
                while(i<s.size() && isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;

                }
                num*=sign;

                if(level==k){
                    ans+=num;
                }
                i--;
            }
            
        }
        cout<<ans<<endl;
    }
}