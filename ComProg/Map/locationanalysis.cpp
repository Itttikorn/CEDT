#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,set<string>> table;
    vector<string> sorted;
    int count=0;
    for(int i=0;i<n;i++){
        string id;
        cin >> id;
        string location;
        set<string> newtable;
        while(cin >> location){
            if (location == "*"){
                break;
            }
            newtable.insert(location);
        }
        table[id] = newtable;
        sorted.push_back(id);
    }
    string searchfrom;
    cin >> searchfrom;
    vector<string> match;
    for(int j=0;j<n;j++){
        //get intersect of 2 sets;
        if(sorted[j]==searchfrom){
            continue;
        }
        set<string> set1 = table.find(searchfrom)->second;
        set<string> set2 = table.find(sorted[j])->second;
        set<string> intersectset;
        for(auto itr = set1.begin();itr!=set1.end();itr++){
            if(set2.find(*itr)!=set2.end()){
                intersectset.insert(*itr);
            }
        }
        if(intersectset.size()!=0){
            match.push_back(sorted[j]);
        }
    }
    if(match.size()==0){
        cout << ">> Not Found";
    }else{
        for(auto itr=match.begin();itr!=match.end();itr++){
            cout << ">> " << *itr << endl;
        }
    }
}