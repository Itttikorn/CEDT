#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> allzero(n+1),someone(n+1);
    allzero[1] = 1;
    someone[1] = 2;
    for(long long i=2;i<=n;i++){
        allzero[i] = (allzero[i-1]+someone[i-1])%100000007;
        someone[i] = (2*allzero[i-1]+someone[i-1])%100000007;
    }
    cout << (allzero[n] + someone[n])%100000007;
    return 0;
}