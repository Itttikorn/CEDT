#include<bits/stdc++.h>
using namespace std;

int findset(int x, vector<int> &parent){
    if(parent[x]==-1) return x;
    parent[x] = findset(parent[x],parent);
    return parent[x];
}

int main(){
    int n;
    cin >> n;
    vector<pair<long long,pair<int,int>>> edges;
    vector<long long> v;
    vector<int> parent(n,-1);
    for(int i=0;i<n;i++){
        long long in;
        cin >> in;
        v.push_back(in);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            edges.push_back({-(v[i]^v[j]),{i,j}});
            edges.push_back({-(v[j]^v[i]),{i,j}});
        }
    }
    long long minweight = 0;
    sort(edges.begin(),edges.end());
    for(auto &z : edges){
        long long w = z.first;
        long long x = z.second.first;
        long long y = z.second.second;
        int a = findset(x,parent);
        int b = findset(y,parent);
        if(a!=b){
            minweight+= -w;
            parent[a] = b;
        }
    }
    cout << minweight;
}