#include<bits/stdc++.h>
using namespace std;
bool safe(vector<vector<bool>> &adjmtx,vector<int> &color,int c,int v){
    for(int i=0; i<adjmtx.size();i++){
        if(adjmtx[v][i] && c==color[i]) return false;
    }
    return true;
}

bool trycolor(vector<vector<bool>> &adjmtx,int colors, vector<int> &color, int v){
    if(v==adjmtx.size()) return true;
    for(int c=1;c<=colors;c++){
        if(safe(adjmtx,color,c,v)){
            color[v] = c;
            if(trycolor(adjmtx,colors,color,v+1)) return true;
            color[v] = 0;
        }
    }
    return false;
}

bool coloring(vector<vector<bool>> &adjmtx,int colors){
    vector<int> color(adjmtx.size(),0);
    if(!trycolor(adjmtx,colors,color,0)){
        return false;
    }
    //cout << *max_element(color.begin(),color.end());
    return true;
}

int main(){
    int n,e;
    cin >> n >> e;
    vector<vector<bool>> adjmtx(n,vector<bool>(n,0));
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        adjmtx[a][b] = 1;
        adjmtx[b][a] = 1;
    }
    for(int i=1;i<=n;i++){
        bool status = coloring(adjmtx,i);
        if(status){
            cout << i << endl;
            break;
        }
    }
}