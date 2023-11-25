#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(n));
    vector<vector<int>> v2(n,vector<int>(n));
    int maxv = -1000;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           int in;
           cin >> in;
           v[i][j] = in;
           if(i==0 || j==0){
                v2[i][j] = in;
                if(in > maxv) maxv=in;
           } 
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            v2[i][j] = max(v2[i-1][j-1],v[i-1][j-1]) + v[i][j];
            if(v2[i][j]>maxv) maxv=v2[i][j];
        }
    }
    cout << maxv;
}