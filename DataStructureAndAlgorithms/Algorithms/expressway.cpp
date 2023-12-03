#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> edges(n+1,vector<int>());
    vector<vector<int>> c(n+1,vector<int>(n+1));
    cin >> c[1][2];
    c[2][1] = c[1][2];
    edges[1].push_back(2);
    edges[2].push_back(1);
    for(int i=3;i<=n;i++){
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int t,p;
            cin >> t >> p;
            c[i][t] = p;
            c[t][i] = p;
            edges[i].push_back(t);
            edges[t].push_back(i);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        pq.push({0,1});
        while(!pq.empty()){
            int t = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for(auto &v : edges[u]){
                if(dist[v] > t+c[u][v]){
                    dist[v] = t+c[u][v];
                    pq.push({dist[v],v});
                }
            }
        }
        cout << dist[2] << " ";
    }
}