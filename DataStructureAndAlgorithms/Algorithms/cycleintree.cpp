#include<bits/stdc++.h>
using namespace std;

int cycledepth=0;
int begindepth=0;

bool dfs(int a, vector<vector<int>> &edges, vector<int> &visited, int parent, int depth){
    visited[a] = depth;
    for(auto &b : edges[a]){
        if(visited[b] == 0){
            if(dfs(b,edges,visited,a,depth+1)) return true;
        }else if(b!=parent){
            cycledepth = depth-visited[b]+1;
            return true;
        }
    }
    return false;
}

int main(){
    int n,e;
    cin >> n;
    e=n;
    vector<vector<int>> edges(n,vector<int>());
    vector<int> visited(n,0);
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    bool cycle = false;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            if(dfs(i,edges,visited,-1,1)){
                cycle = true;
                break;
            }
        }
    }
    cout << cycledepth;
    
}