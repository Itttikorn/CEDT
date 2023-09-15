#include<bits/stdc++.h>
using namespace std;

int powermod(int a, int k, int m){
    if(a==0){
        return 0;
    }
    if(k==0){
        return 1;
    }
    if(k%2==0){
        int result = powermod(a,floor(k/2),m);
        return (result*result)%m;
    }
    if(k%2==1){
        int result = pow(powermod(a,floor(k/2),m),2);
        return (a*result)%m;
    }
}

int main(){
    int a,k,m;
    cin >> a >> k >> m;
    cout << powermod(a,k,m);
}