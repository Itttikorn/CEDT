#include<bits/stdc++.h>
using namespace std;

int currcolor=0;

void dfs(int a, vector<vector<int>> &edges, vector<int> &visited){
    visited[a] = currcolor;
    for(auto &b : edges[a]){
        if(visited[b]==0){
            dfs(b,edges,visited);
        }
    }
}

int main(){
    int v,e;
    cin >> v >> e;
    vector<vector<int>> edges(v+1,vector<int>());
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> visited(v+1,0);
    for(int i=1;i<=v;i++){
        if(visited[i] == 0){
            currcolor++;
            dfs(i,edges,visited);
        }
    }
    cout << currcolor;
    
}