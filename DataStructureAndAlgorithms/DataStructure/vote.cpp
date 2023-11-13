#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> q;
    map<string,int> table;
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        string name;
        cin >> name;
        if(table.find(name)==table.end()){
            table[name] = 1;
        }else{
            table[name]++;
        }
    }
    for(auto itr = table.begin();itr!=table.end();itr++){
        q.push(itr->second);
    }
    int currentlow = q.top();
    for(int i=0;i<k;i++){
        if(q.size()==0){
            break;
        }
        currentlow = q.top();
        q.pop();
    }
    cout << currentlow;
}