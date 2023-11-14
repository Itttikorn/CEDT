#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,pos,color;
    cin >> n >> pos >> color;
    list<int> line;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        line.push_back(in);
    }
    auto itr = line.begin();
    advance(itr,pos);
    auto inspos = line.insert(itr,color);
    list<int>::iterator beforepos=inspos,afterpos=inspos;
    bool working = true;
    int count=0;
    while(working){
        if(line.size()==0) break;
        int countbefore=0,countafter=0;
        auto beforepos=inspos,afterpos=inspos;
        while(*beforepos == *(--beforepos)) countbefore++;
        while(*afterpos == *(++afterpos)) countafter++;
        beforepos++;
        afterpos--;
        if(countbefore+countafter+1>=3 && (count==0 || countbefore>=1)){
            for(int i=0;i<countbefore+countafter+1;i++){
                beforepos = line.erase(beforepos);
            }
            inspos = beforepos;
        }else{
            working = false;
        }
        count++;
    }
    if(line.size()==0) return 0;
    for(auto itr = line.begin();itr!=line.end();itr++){
        cout << *itr << " ";
    }
}
