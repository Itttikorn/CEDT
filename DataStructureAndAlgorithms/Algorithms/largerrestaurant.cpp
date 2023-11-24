#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

map<ll,int> t;
int n,a;

pair<ll,ll> find_customer(ll time){
    ll h=0, l=0;
    for(auto &x : t){
        h += (time/x.first)*x.second;
        l += ((time-1)/x.first)*x.second;
    }
    return make_pair(h,l);
}

ll b_search(ll l, ll r, ll v){
    if(l>=r) return l;
    ll m = (l+r)/2;
    pair<ll,ll> customers = find_customer(m);
    if(v<=customers.first && v>customers.second) return m;
    else if(v<=customers.first) return b_search(l,m,v);
    else return b_search(m+1,r,v);
}
int main(){
    cin >> n >> a;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        t[in]++;
    }
    for(int i=0;i<a;i++){
        long long customer;
        cin >> customer;
        if(customer<=n) {cout << 0 << endl; continue;}
        cout << b_search(0,-1,customer-n) << endl;
    }
}