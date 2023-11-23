#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> v, int k){
    if(k==1){
        if(v[0] == 0 && v[1] == 1) return true;
        return false;
    }
    int twok = pow(2,k-1);
    vector<int> v1(twok);
    for(int i=0;i<twok;i++){
        v1[i] = v[i];
    }
    vector<int> v2(v1);
    reverse(v2.begin(),v2.end());
    vector<int> v3(twok);
    for(int i=twok;i<(twok+twok);i++){
        v3[i-twok] = v[i];
    }
    bool front = check(v1,k-1);
    bool frontreverse = check(v2,k-1);
    bool back = check(v3,k-1);
    return ((front || frontreverse) && back);
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v;
    int twok = pow(2,k);
    for(int i=0;i<n;i++){
        v.clear();
        for(int j=0;j<twok;j++){
            int in;
            cin >> in;
            v.push_back(in);
        }
        if(check(v,k)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}