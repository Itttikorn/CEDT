#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &v, int row, int col, int n){
    //horizontal
    for(int i=0;i<col;i++){
        if(v[row][i]) return false;
    }
    //diagonal top left
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(v[i][j]) return false;
    }
    //diagonal lower left
    for(int i=row,j=col;i<n && j>=0;i++,j--){
        if(v[i][j]) return false;
    }
    return true;
}

void solve(vector<vector<int>> &v,int col,int n, int &count){
    if(col==n){
        count++;
        return;
    }
    for(int i=0;i<n;i++){
        if(check(v,i,col,n)){
            v[i][col] = 1;
            solve(v,col+1,n,count);
            v[i][col] = 0;
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    int count=0;
    vector<vector<int>> v(n,vector<int>(n,0));
    solve(v,0,n,count);
    cout << count;
}