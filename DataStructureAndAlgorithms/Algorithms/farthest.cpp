#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> edges(n,vector<int>(n));
    vector<int> dist(n,INT_MAX);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int in;
            cin >> in;
            if(in!=0 && in!=-1){
                edges[i][j]=in;
            }
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    dist[0] = 0;
    while(!pq.empty()){
        int t = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for(int i=0;i<edges[u].size();i++){
            if(edges[u][i] != 0 && dist[i] > t+edges[u][i]){
                dist[i] = t + edges[u][i];
                pq.push({dist[i],i});
            }
        }
    }
    if(find(dist.begin(),dist.end(),INT_MAX)!=dist.end()) cout << -1;
    else cout << *max_element(dist.begin(),dist.end());
}