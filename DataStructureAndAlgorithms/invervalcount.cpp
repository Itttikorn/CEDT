#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    vector<long long> vn; 
    int n,m;
    long long k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        long long in;
        cin >> in;
        vn.push_back(in);
    }
    sort(vn.begin(),vn.end());
    for(int i=0;i<m;i++){
        long long in;
        cin >> in;
        long long low = in-k;
        long long high = in+k;
        int count=0;
        auto lowpos = lower_bound(vn.begin(),vn.end(),low);
        auto highpos = upper_bound(vn.begin(),vn.end(),high);
        count = highpos-lowpos;
        cout << count << " ";
    }
}