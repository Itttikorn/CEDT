#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    map<long long, long long> table;
    for(int i=0;i<n;i++){
        long long father,son;
        cin >> father >> son;
        table[son] = father;
    }
    for(int i=0;i<m;i++){
        long long man1father,man1gf,man2father,man2gf,man1,man2;
        cin >> man1 >> man2;
        if(man1 == man2){
            cout << "NO" << endl;
            continue;
        }
        if(table.find(man1)==table.end()){
            cout << "NO" << endl;
            continue;
        }else{
            man1father = table.find(man1)->second;
        }
        if(table.find(man1father)==table.end()){
            cout << "NO" << endl;
            continue;
        }else{
            man1gf = table.find(man1father)->second;
        }
        if(table.find(man2)==table.end()){
            cout << "NO" << endl;
            continue;
        }else{
            man2father = table.find(man2)->second;
        }
        if(table.find(man2father)==table.end()){
            cout << "NO" << endl;
            continue;
        }else{
            man2gf = table.find(man2father)->second;
        }
        //cout << man1gf << " " << man2gf << endl;
        if(man1gf == man2gf){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}