#include<bits/stdc++.h>
using namespace std;

bool findroute(map<int,set<int>> routelist,int pos,int dest){
    if(pos==dest){
        return true;
    }
    if(routelist.find(pos)==routelist.end()){
        return false;
    }
    for(auto itr=routelist.find(pos)->second.begin();itr!=routelist.find(pos)->second.end();itr++){
        bool found = findroute(routelist,*itr,dest);
        if(found){
            return true;
        }
    }
    return false;
}

int main(){
    int n,start,dest;
    map<int,set<int>> routelist;
    cin >> n >> start >> dest;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(routelist.find(a)==routelist.end()){
            set<int> newset;
            newset.insert(b);
            routelist[a]=newset;
        }else{
            routelist[a].insert(b);
        }
    }
    if(findroute(routelist,start,dest)){
        cout << "yes";
    }else{
        cout << "no";
    }
}