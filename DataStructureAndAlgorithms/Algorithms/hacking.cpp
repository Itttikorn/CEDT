#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin  >> n >> m >> k;
    vector<vector<int>> edges(n,vector<int>());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n,INT_MAX);
    vector<int> hacked;
    vector<int> c;
    for(int i=0;i<k;i++){
        int in;
        cin >> in;
        hacked.push_back(in);
    }
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        c.push_back(in);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(auto &a : hacked){
        pq.push({c[a],a});
        dist[a] = c[a];
    }
    while(!pq.empty()){
        int t = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for(auto &v : edges[u]){
            if(dist[v]>t+c[v]){
                dist[v] = t+c[v];
                pq.push({dist[v],v});
            }
        }
    }
    cout << *max_element(dist.begin(),dist.end());
}