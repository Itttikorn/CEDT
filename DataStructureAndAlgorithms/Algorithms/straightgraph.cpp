#include<bits/stdc++.h>
using namespace std;

int nodes,d1,d2;
void dfs(int a, vector<vector<int>> &edges, vector<int> &visited){
    visited[a] = 1;
    nodes++;
    if(edges[a].size()==1){
        d1++;
    }
    if(edges[a].size()==2){
        d2++;
    }
    for(auto &b : edges[a]){
        if(visited[b]==0){
            dfs(b,edges,visited);
        }
    }
}

int main(){
    int v,e;
    cin >> v >> e;
    vector<vector<int>> edges(v,vector<int>());
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    int count=0;
    vector<int> visited(v,0);
    for(int i=0;i<v;i++){
        if(visited[i] == 0){
            nodes=0;
            d1=0;
            d2=0;
            dfs(i,edges,visited);
            if(nodes==1 || (d1==2 && nodes-2 == d2)){
                count++;
            }
        }
    }
    cout << count;
}