#include <bits/stdc++.h>
using namespace std;

int recur(int n,int sum,int m){
    //cout << n << " " << sum << " " << m << endl;
    if(sum>n) return 0;
    if(sum==n) return 1;
    int ret = 0;
    for(int i=m;i<=n;i++){
        //cout << i << endl;
        ret+=recur(n,sum+i,i);
    }
    return ret;
}

int main(){
    int count=0;
    int n;
    cin >> n;
    count = recur(n,0,1);
    cout << count;
}