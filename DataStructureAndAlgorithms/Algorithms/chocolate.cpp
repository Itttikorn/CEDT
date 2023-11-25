#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> s(k);
    for(int i=0;i<k;i++){
        cin >> s[i];
    }
    vector<int> v(n+1);
    v[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            if(i-s[j]>=0){
                v[i] = (v[i]+v[i-s[j]])%1000003;
            }
        }
    }
    cout << v[n];
}