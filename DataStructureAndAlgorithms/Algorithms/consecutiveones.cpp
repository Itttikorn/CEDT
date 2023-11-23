#include <bits/stdc++.h>
using namespace std;

void gen(int &n, int &k, vector<bool> &path,int pos,int count, bool done){
    if(pos<n){
        path[pos] = 0;
        gen(n,k,path,pos+1,0,done);
        path[pos] = 1;
        gen(n,k,path,pos+1,count+1,done||(count+1)>=k);
    }else if(done){
        for(auto x : path){
            cout << x;
        }
        cout << "\n";
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<bool> path(n);
    gen(n,k,path,0,0,0||k==0);
}