#include<bits/stdc++.h>
using namespace std;

bool travel(vector<vector<int>> &adjmtx, int ki, vector<int> &path, int &weight, int currpos){
    //cout << weight << endl;
    for(auto &x : path){
        cout << x << " ";
    }
    cout << endl;
    if(weight==ki) return true;
    if(weight>ki) return false;
    for(int i=0;i<adjmtx.size();i++){
        if(i==currpos) continue;
        if(adjmtx[currpos][i]==0) continue;
        if (find(path.begin(),path.end(),i)!=path.end()) continue;
        if(adjmtx[currpos][i]>0){
            path.push_back(i);
            weight+=adjmtx[currpos][i];
            if(weight==ki) return true;
            if(weight>ki) continue;
            // if(weight>ki){
            //     path.pop_back();
            //     weight-=adjmtx[currpos][i];
            //     continue;
            // }
            if(travel(adjmtx,ki,path,weight,i)) return true;
            path.pop_back();
            weight-=adjmtx[currpos][i];
        }
    }
    return false;
}

bool start(vector<vector<int>> &adjmtx, int ki){
    vector<int> path;
    int weight = 0;
    for(int i=0;i<adjmtx.size();i++){
        path.clear();
        path.push_back(i);
        if(travel(adjmtx,ki,path,weight,i)){
            return true;
        }
        // for(auto &x : path){
        //     cout << x << " ";
        // }
        // cout << endl;
    }
    return false;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adjmtx(n,vector<int>(n,0));
    vector<int> k;
    for(int i=0;i<8;i++){
        int in;
        cin >> in;
        k.push_back(in);
    }
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adjmtx[a][b] = w;
        adjmtx[b][a] = w;
    }
    for(int i=0;i<8;i++){
        if(start(adjmtx,k[i])){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}