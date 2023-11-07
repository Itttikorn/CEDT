#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,set<string>> stations;
    string first;
    string current;
    set<string> cango;
    while(cin >> first){
        string second;
        cin >> second;
        if(second.length()==0){
            current=first;
            break;
        }
        //if station not found
        if(stations.find(first)==stations.end() && stations.find(second)!=stations.end()){
            set<string> newset;
            newset.insert(second);
            stations[first] = newset;
        }else if(stations.find(first)!=stations.end() && stations.find(second)==stations.end()){
            set<string> newset;
            newset.insert(first);
            stations[second] = newset;
        }if(stations.find(first)==stations.end() && stations.find(second)==stations.end()){
            set<string> newset;
            newset.insert(second);
            stations[first] = newset;
            set<string> newset2;
            newset2.insert(first);
            stations[second] = newset2;
        }else{
            stations.find(first)->second.insert(second);
            stations.find(second)->second.insert(first);
        }
    }
    cango.insert(current);
    //find current station
    auto currentpos = stations.find(current);
    if(currentpos!=stations.end()){
        for(auto itr=currentpos->second.begin();itr!=currentpos->second.end();itr++){
            //insert current station;
            cango.insert(*itr);
            //insert next station
            auto nextpos = stations.find(*itr);
            if(nextpos!=stations.end()){
                for(auto jtr=nextpos->second.begin();jtr!=nextpos->second.end();jtr++){
                    cango.insert(*jtr);
                }
            }
        }
    }
    for(auto itr = cango.begin();itr!=cango.end();itr++){
        cout << *itr << endl;
    }

}