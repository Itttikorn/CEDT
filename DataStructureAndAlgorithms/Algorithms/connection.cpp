#include<bits/stdc++.h>
using namespace std;

int dfs(int a, vector<vector<int>> &edges, int v,int k){
    int count = 0;
    vector<int> dist(v,-1);
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    while(q.size()>0){
        int u = q.front();
        q.pop();
        for(auto &b : edges[u]){
            if(dist[b]==-1){
                dist[b] = dist[u]+1;
                if(dist[b] == k) count++;
                q.push(b);
            }
        }
    }
    for(auto &x : dist){
        cout << x <<" ";
    }
    cout << endl;
    return count;
}

int main(){
    int v,e,k;
    cin >> v >> e >> k;
    vector<vector<int>> edges(v,vector<int>());
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    int maxcount=0;
    for(int i=0;i<v;i++){
        vector<int> dist(v,v);
        vector<int> visited(v,0);
        queue<int> q;
        int count = 1;
        q.push(i);
        dist[i] = 0;
        visited[i] = 1;
        while(q.size()>0){
            int u = q.front();
            q.pop();
            if(dist[u] == k) continue;
            for(auto &b : edges[u]){
                if(visited[b]==0){
                    visited[b] = 1;
                    count++;
                    dist[b] = dist[u]+1;
                    q.push(b);
                }
            }
            if(count>maxcount) maxcount=count;
        }
    }
    cout << maxcount;
}