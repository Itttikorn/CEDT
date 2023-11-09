#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> table;
    int firsty,firstm;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        pair<int,int> newpair = make_pair(a,b);
        table.push_back(newpair);
    }
    sort(table.begin(),table.end());
    firsty = table.begin()->first;
    firstm = table.begin()->second;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(a <= firsty){
            if((a == firsty && b < firstm) || (a<firsty)){
                cout << "-1 -1 ";
                continue;
            }
        }
        pair<int,int> searchpair = make_pair(a,b);
        if(*lower_bound(table.begin(),table.end(),searchpair)==searchpair){
            cout << "0 0 ";
            continue;
        }else{
            auto low = lower_bound(table.begin(),table.end(),searchpair);
            low--;
            cout << low->first << " " << low->second << " ";
        }
    }
}