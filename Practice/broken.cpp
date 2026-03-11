#include<iostream>
#include<math.h>
#include<climits>
#include<algorithm>
using namespace std;

const int EMPTY = -10000000;

int *working,*operations;
int answer=INT_MAX;
int n,m,o;

int eval(int prev,int curr,int op){

    if(prev==EMPTY) return curr;

    if(op==1) return prev+curr;
    if(op==2) return prev-curr;
    if(op==3) return prev*curr;

    if(op==4){
        if(curr==0) return -1;
        return prev/curr;
    }

    return curr;
}

bool isDone(int prev,int curr,int Operation,int target){

    if(Operation==4 && curr==0) return false;

    if(eval(prev,curr,Operation)==target)
        return true;

    return false;
}

void findMinTouch(int prev,int curr,int ooperation,int tou,int t){

    if(tou>=o) return;

    if(ooperation!=-1 && curr!=EMPTY){

        bool k=isDone(prev,curr,ooperation,t);

        if(k && tou<o)
            answer=min(answer,tou+1);
    }

    if(prev==t && tou<o && ooperation!=-1 && curr==EMPTY)
        answer=min(answer,tou);

    if(ooperation==-1 && curr==t && tou<o)
        answer=min(answer,tou);

    for(int i=0;i<m;i++){

        if(curr==EMPTY) break;

        if(curr==0 && ooperation==4) continue;

        int val=eval(prev,curr,ooperation);

        findMinTouch(val,EMPTY,operations[i],tou+1,t);
    }

    for(int i=0;i<n;i++){

        if(curr==EMPTY)
            findMinTouch(prev,working[i],ooperation,tou+1,t);
        else{

            int val=abs(curr);
            val=val*10+working[i];

            if(curr<0) val*=-1;

            findMinTouch(prev,val,ooperation,tou+1,t);
        }
    }
}

int main(){

    int t;
    cin>>t;

    int count = 0;

    while(t--){

        answer=INT_MAX;

        cin>>n>>m>>o;

        working=new int[n];
        operations=new int[m];

        for(int i=0;i<n;i++)
            cin>>working[i];

        for(int i=0;i<m;i++)
            cin>>operations[i];

        int target;
        cin>>target;

        findMinTouch(EMPTY,EMPTY,-1,0,target);

        count++;

        if(answer==INT_MAX)
            cout<<"#"<<count<<": -1"<<endl;
        else
            cout<<"#"<<count<<": "<<answer<<endl;

        delete[] working;
        delete[] operations;
    }

    return 0;
}