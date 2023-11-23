#include<bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>> &v, int a, int b, int top, int bottom, int left, int right){
    if(a==0){
        v[top][left] = b;
        return;
    }
    int m = pow(2,a-1);
    recur(v,a-1,b,top,top+m,left,left+m);
    recur(v,a-1,b-1,top,top+m,left+m,right);
    recur(v,a-1,b+1,top+m,bottom,left,left+m);
    recur(v,a-1,b,top+m,bottom,left+m,right);
}

int main(){
    int a,b;
    cin >> a >> b;
    int maxv = pow(2,a);
    vector<vector<int>> v(pow(2,a),vector<int>(pow(2,a)));
    recur(v,a,b,0,maxv,0,maxv);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}