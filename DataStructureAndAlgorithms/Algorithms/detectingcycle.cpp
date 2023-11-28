#include<bits/stdc++.h>
using namespace std;

bool dfs(int a, vector<vector<int>> &edges, vector<bool> &visited, int parent){
    visited[a] = true;
    for(auto &b : edges[a]){
        if(visited[b] == false){
            if(dfs(b,edges,visited,a)) return true;
        }else if(b!=parent) return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n,e;
        cin >> n >> e;
        vector<vector<int>> edges(n,vector<int>());
        vector<bool> visited(n,false);
        for(int i=0;i<e;i++){
            int a,b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        bool cycle = false;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(dfs(i,edges,visited,-1)){
                    cycle = true;
                    break;
                }
            }
        }
        if(cycle){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}