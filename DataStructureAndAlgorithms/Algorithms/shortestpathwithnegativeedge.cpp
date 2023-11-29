#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e,s;
    cin >> n >> e >> s;
    vector<int> dist(n,100000);
    vector<vector<pair<int,int>>> edges(n);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges[a].push_back({b,c});
        //edges.push_back({{b,a},c});
    }
    dist[s] = 0;
    //sort(edges.begin(),edges.end());
    for(int i=0;i<n-1;i++){
        for(int a=0;a<n;a++){
            for(auto &v : edges[a]){
                int b = v.first;
                int w = v.second;
                if(dist[b] > dist[a] + w){
                    dist[b] = dist[a] + w;
                }
            }
        }
        
    }
    for(int a=0;a<n;a++){
        for(auto &v : edges[a]){
            int b = v.first;
            int w = v.second;
            if(dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
                cout << -1;
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << dist[i] << " ";
    }
}