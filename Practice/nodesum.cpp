#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    int k;
    cin>>k;

    int level=-1;

    long long sum=0;

    string s;
    cin>>s;

    for(unsigned i=0;i<s.size();i++){
        if(s[i]=='('){
            level++;
            continue;
        }
        else if(s[i]==')'){
            level--;
            continue;
        }

        int num=0;
        int sign=1;

        if(s[i]=='-'){
            sign=-1;
            i++;
        }

        int hasdig = false;

        while(isdigit(s[i])){
            num=num*10+(s[i]-'0');
            i++;
            hasdig=true;
        }
        i--;
        num=num*sign;

        if(level==k){
            sum+=num;
        }
    }
    cout<<sum <<endl;;
    return 0;
    

}
