#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e,s;
    cin >> n >> e >> s;
    vector<int> dist(n,100000);
    vector<pair<pair<int,int>,int>> edges;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({{a,b},c});
        //edges.push_back({{b,a},c});
    }
    dist[s] = 0;
    //sort(edges.begin(),edges.end());
    for(int i=0;i<n-1;i++){
        for(auto &v : edges){
            int a = v.first.first;
            int b = v.first.second;
            int w = v.second;
            if(dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
            }
        }
    }
    for(auto &e : edges){
        if(dist[e.first.second]>dist[e.first.first]+e.second){
            cout << -1;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        cout << dist[i] << " ";
    }
}