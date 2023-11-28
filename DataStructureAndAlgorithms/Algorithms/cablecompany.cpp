#include<bits/stdc++.h>
using namespace std;

int findset(int x, vector<int> &parent){
    if(parent[x]==-1) return x;
    parent[x] = findset(parent[x],parent);
    return parent[x];
}

void unions(int x,int y, vector<int> &parent, vector<int> &sizes){
    auto s1 = findset(x,parent);
    auto s2 = findset(y,parent);
    if(sizes[s1] > sizes[s2]){
        parent[s2] = s1;
        sizes[s1]+=sizes[s2];
    }else{
        parent[s1] = s2;
        sizes[s2]+=sizes[s1];
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> edges;
    vector<int> parent(n,-1);
    vector<int> sizes(n,1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int w;
            cin >> w;
            edges.push_back({w,i,j});
            edges.push_back({w,j,i});
        }
    }
    int minweight = 0;
    // cout << "result" << endl;
    // for(auto &a : edges){
    //     for(auto &b : a){
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    sort(edges.begin(),edges.end());
    for(auto &a : edges){
        int w = a[0];
        int x = a[1];
        int y = a[2];
        //cout << findset(x,parent) << findset(y,parent) << endl;
        if(findset(x,parent)!=findset(y,parent)){
            minweight+=w;
            unions(x,y,parent,sizes);
        }
    }
    cout << minweight;
}