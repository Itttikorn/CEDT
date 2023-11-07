#include<bits/stdc++.h>
using namespace std;

set<set<int>> findroute(map<int,set<int>> routelist,int pos,int dest){
    set<set<int>> foundroute;
    if(pos==dest){
        //cout << "Yes"<<endl;
        set<int> newset;
        newset.insert(pos);
        foundroute.insert(newset);
        return foundroute;
    }
    if(routelist.find(pos)==routelist.end()){
        return foundroute;
    }
    for(auto itr=routelist.find(pos)->second.begin();itr!=routelist.find(pos)->second.end();itr++){
        set<set<int>> previouslyfoundroute;
        previouslyfoundroute = findroute(routelist,*itr,dest);
        if(previouslyfoundroute.size()!=0){
            for(auto itr=previouslyfoundroute.begin();itr!=previouslyfoundroute.end();itr++){
                set<int> newset;
                newset.insert(pos);
                for(auto jtr=itr->begin();jtr!=itr->end();jtr++){
                    newset.insert(*jtr);
                }
                foundroute.insert(newset);
            }
        }
    }
    return foundroute;
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
    set<set<int>> foundroute = findroute(routelist,start,dest);
    if(foundroute.size()!=0){
        for(auto itr=foundroute.begin();itr!=foundroute.end();itr++){
            for(auto jtr=itr->begin();jtr!=itr->end();jtr++){
                if(*jtr!=dest){
                    cout << *jtr << " -> ";
                }else{
                    cout << *jtr << endl;
                }
            }
        }
    }else{
        cout << "no" << endl;
    }
}