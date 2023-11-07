#include<bits/stdc++.h>
using namespace std;

int main(){
    string name,type;
    map<string,vector<string>> cartoon;
    vector<string> typelist;
    while(cin >> name){
        cin >> type;
        if(cartoon.find(type)!=cartoon.end()){
            cartoon.find(type)->second.push_back(name);
        }else{
            vector<string> newvector;
            newvector.push_back(name);
            cartoon[type] = newvector;
            typelist.push_back(type);
        }
        
    }
    for(auto itr = typelist.begin();itr!=typelist.end();itr++){
        auto pos=cartoon.find(*itr);
        cout << pos->first << ": ";
        for(auto jtr = pos->second.begin();jtr!=pos->second.end();jtr++){
            cout << *jtr << " ";
        }
        cout << endl;
    }
}