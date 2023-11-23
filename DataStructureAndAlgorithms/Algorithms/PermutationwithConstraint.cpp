#include <bits/stdc++.h>
using namespace std;

void next(int &n, vector<pair<int,int>> &rule, vector<int> &path){
    for(int i=0;i<n;i++){
        bool check = true;
        for(auto itr = rule.begin();itr!=rule.end();itr++){
            for(int i=0;i<path.size();i++){
                if(path[i]==itr->first){
                    check = true;
                    break;
                }
                if(path[i]==itr->second){
                    check = false;
                    break;
                }
            }
            if(!check) break;
        }
        for(int j=0;j<path.size();j++){
            if(i==path[j]){
                check = false;
                break;
            }
        }
        if(check){
            path.push_back(i);
            if(path.size()==n){
                for(auto &x : path){
                    cout << x << " ";
                }
                cout << "\n";
            }else{
                next(n,rule,path);
            }
            path.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> rule;
    vector<int> path;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        rule.push_back(make_pair(a,b));
    }
    next(n,rule,path);

}