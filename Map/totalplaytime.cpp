#include<bits/stdc++.h>
using namespace std;

int main(){
    string song,artist,genre,time;
    map<string,int> table;
    vector<pair<int,string>> genrelist;
    while(cin >> song){
        cin >> artist >> genre >> time;
        //cout << genre << " " << time << endl;
        int timeinmin=0;
        int count=0;
        if(table.find(genre)==table.end()){
            table[genre] = 0;
        }
        for(int i=0;i<time.length();i++){
            if(time[i]==':'){
                timeinmin+=stoi(time.substr(0,count))*60;
                timeinmin+=stoi(time.substr(i+1,time.length()-i));
                table[genre] += timeinmin;
                break;
            }else{
                count++;
            }
        }
    }
    for(auto itr = table.begin();itr!=table.end();itr++){
        //cout << itr->first << itr->second/60 << ":" << itr->second%60 << endl;
        genrelist.push_back(make_pair(itr->second,itr->first));
    }
    sort(genrelist.begin(),genrelist.end());
    int sizes = genrelist.size()-3;
    if(sizes<0){
        sizes=0;
    }
    for(int i=genrelist.size()-1;i>=sizes;i--){
        auto to_print = table.find(genrelist[i].second);
        cout << to_print->first << " --> " << to_print->second/60 << ":" << to_print->second%60 << endl;
    }
    
}