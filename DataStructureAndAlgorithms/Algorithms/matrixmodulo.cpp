#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>>multiply(vector<vector<long long>> &mtx1, vector<vector<long long>> &mtx2, int k){
    vector<vector<long long>> result(2,vector<long long>(2));
    result[0][0] = (mtx1[0][0]*mtx2[0][0] + mtx1[0][1]*mtx2[1][0])%k;
    result[0][1] = (mtx1[0][0]*mtx2[0][1] + mtx1[0][1]*mtx2[1][1])%k;
    result[1][0] = (mtx1[1][0]*mtx2[0][0] + mtx1[1][1]*mtx2[1][0])%k;
    result[1][1] = (mtx1[1][0]*mtx2[0][1] + mtx1[1][1]*mtx2[1][1])%k;
    return result;
}

vector<vector<long long>>modulo(map<int,vector<vector<long long>>> &mtxmap, int k, int n){
    if(n==1) return mtxmap[1];
    if(mtxmap.find(n)!=mtxmap.end()) return mtxmap[n];
    if(n%2==0){
        vector<vector<long long>> mtx1 = modulo(mtxmap,k,n/2);
        mtxmap[n] = multiply(mtx1,mtx1,k);
        return mtxmap[n];
    }else{
        vector<vector<long long>> mtx1 = modulo(mtxmap,k,n/2);
        vector<vector<long long>> mtx2 = modulo(mtxmap,k,n/2+1);
        mtxmap[n] = multiply(mtx1,mtx2,k);
        return mtxmap[n];
    }
}

int main(){
    long long n;
    int k;
    vector<vector<long long>> mtx(2,vector<long long>(2));
    map<int,vector<vector<long long>>> mtxmap;
    cin >> n >> k;
    cin >> mtx[0][0];
    cin >> mtx[0][1];
    cin >> mtx[1][0];
    cin >> mtx[1][1];
    mtxmap[1] = mtx;
    mtx = modulo(mtxmap,k,n);
    cout << mtx[0][0] << " " << mtx[0][1] << " " << mtx[1][0] << " " << mtx[1][1];
}