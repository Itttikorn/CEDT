#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> a,b;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        b.insert(in);
        a.insert(i+1);
    }
    if(a==b){
        cout << "YES";
    }else{
        cout << "NO";
    }
}